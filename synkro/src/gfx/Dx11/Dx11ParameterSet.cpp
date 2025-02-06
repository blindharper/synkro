//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: DX11 program parameters.
//==============================================================================
#include "config.h"
#include "Dx11ParameterSet.h"
#include <gfx/ProgramStageTypeConst.h>
#include <d3d11shader.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11ParameterSet::Dx11ParameterSet( Dx11Context* context, ID3D11ShaderReflection* reflect, const ProgramStageType& type, IParameterSet* parent, IParameterSet* grandParent, UINT startSlot ) :
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>( type ),
	_buffers( A(ID3D11Buffer*) ),
	_dirtyBuffers( A(BufferEntry) ),
	_startSlot( startSlot ),
	_context( context )
{
	HRESULT hr = S_OK;
	UInt total = 0;

	D3D11_SHADER_DESC shaderDesc;
	reflect->GetDesc( &shaderDesc );

	// Enumerate parameter buffers.
	D3D11_SHADER_BUFFER_DESC bufDesc;
	for ( UINT i = 0; i < shaderDesc.ConstantBuffers; ++i )
	{
		ID3D11ShaderReflectionConstantBuffer* buf = reflect->GetConstantBufferByIndex( i );
		buf->GetDesc( &bufDesc );

		// Skip texture buffers.
		if ( bufDesc.Type == D3D11_CT_TBUFFER )
			continue;

		// Create buffer.
		D3D11_BUFFER_DESC desc;
		desc.ByteWidth		= bufDesc.Size;
		desc.Usage			= D3D11_USAGE_DYNAMIC;
		desc.BindFlags		= D3D11_BIND_CONSTANT_BUFFER;
		desc.CPUAccessFlags	= D3D11_CPU_ACCESS_WRITE;
		desc.MiscFlags		= 0;

		ID3D11Buffer* buffer = nullptr;
		if ( FAILED(hr = _context.Device()->CreateBuffer(&desc, nullptr, &buffer)) )
			throw GraphicsException( L"Failed to create parameter buffer.", Dx11::ToString(hr) );

		// Enumerate parameters.
		UInt paramCount = 0;
		D3D11_SHADER_VARIABLE_DESC varDesc;
		for ( UINT i = 0; i < bufDesc.Variables; ++i )
		{
			ID3D11ShaderReflectionVariable* var = buf->GetVariableByIndex( i );
			var->GetDesc( &varDesc );

			String name( varDesc.Name );

			// Skip existing parameters.
			if ( _params.ContainsKey(name) )
				continue;

			// Ignore shared parameters for non-parent programs.
			if ( name.StartsWith(L"sp_") )
			{
				if ( (parent != nullptr) && parent->GetParam(name) != nullptr )
					continue;

				if ( (grandParent != nullptr) && grandParent->GetParam(name) != nullptr )
					continue;
			}

			D3D11_SHADER_TYPE_DESC typeDesc;
			var->GetType()->GetDesc( &typeDesc );
			ProgramDataType dataType = ProgramDataType::Unknown;
			switch ( typeDesc.Type )
			{
				case D3D10_SVT_BOOL:										dataType = ProgramDataType::Bool; break;
				case D3D10_SVT_INT:											dataType = ProgramDataType::Int; break;

				case D3D10_SVT_FLOAT:			
				{
						 if ( typeDesc.Class == D3D10_SVC_SCALAR )			dataType = ProgramDataType::Float;
					else if ( typeDesc.Class == D3D10_SVC_VECTOR )
					{
							 if ( typeDesc.Columns == 2 )					dataType = ProgramDataType::Vector2;
						else if ( typeDesc.Columns == 3 )					dataType = ProgramDataType::Vector3;
						else if ( typeDesc.Columns == 4 )					dataType = ProgramDataType::Vector4;
					}
					else if ( typeDesc.Class == D3D10_SVC_MATRIX_ROWS )		dataType = ProgramDataType::Matrix4x4;
					else if ( typeDesc.Class == D3D10_SVC_MATRIX_COLUMNS )	dataType = ProgramDataType::Matrix4x4Transposed;
				}
				break;

				case D3D10_SVT_VOID:
				{
					if ( typeDesc.Class == D3D10_SVC_STRUCT )				dataType = ProgramDataType::Structure;
				}
				break;

				default:			break;
			}

			// Skip parameters of unrecognized type.
			if ( dataType == ProgramDataType::Unknown )
				continue;

			_params[name] = Dx11ProgramParam( name );
			Dx11ProgramParam& p = _params[name];
			p.Type			= dataType;
			p.Buffer		= buffer;
			p.BufferOffset	= varDesc.StartOffset;
			p.Size			= varDesc.Size;
			p.ElementCount	= (typeDesc.Elements > 0) ? typeDesc.Elements : 1;
			p.Offset		= total;
			_names.Add( name );
			total += p.Size;
			++paramCount;
		}

		// Add buffer, if needed.
		if ( paramCount > 0 )
		{
			_buffers.Add( buffer );
		}
		else
		{
			buffer->Release();
		}
	}
	_data.SetSize( total );
}

Dx11ParameterSet::Dx11ParameterSet( const Dx11ParameterSet& other, Bool cloneShared ) :
	ParameterSetImpl<IParameterSet, Dx11ProgramParam>( other._type ),
	_buffers( A(ID3D11Buffer*) ),
	_dirtyBuffers( A(BufferEntry) ),
	_startSlot( other._startSlot ),
	_context( &other._context )
{
	_params	= other._params;
	_names	= other._names;
	_data	= other._data;

	// Copy buffers.
	HRESULT hr = S_OK;
	for ( UInt i = 0; i < other._buffers.Size(); ++i )
	{
		// See if we can just use a reference to existing buffer.
		Bool shareBuffer = false;
		if ( !cloneShared )
		{
			MapIterator<String, Dx11ProgramParam> it = _params.Begin();
			MapIterator<String, Dx11ProgramParam> itEnd = _params.End();
			for ( ; it != itEnd ; ++it )
			{
				if ( it.Value().Name.StartsWith(L"sp_") && (it.Value().Buffer == other._buffers[i]) )
				{
					shareBuffer = true;
					break;
				}
			}
		}

		// Reference or clone original buffer.
		ID3D11Buffer* buffer = nullptr;
		if ( shareBuffer )
		{
			buffer = other._buffers[i];
			buffer->AddRef();
		}
		else
		{
			D3D11_BUFFER_DESC desc;
			other._buffers[i]->GetDesc( &desc );
			if ( FAILED(hr = _context.Device()->CreateBuffer(&desc, nullptr, &buffer)) )
				throw GraphicsException( L"Failed to create parameter buffer.", Dx11::ToString(hr) );

			Pointer key = reinterpret_cast<Pointer>( buffer );
			_dirtyBuffers[key] = buffer;
		}
		_buffers.Add( buffer );
	}

	// Re-assign parameter buffers.
	MapIterator<String, Dx11ProgramParam> it = _params.Begin();
	MapIterator<String, Dx11ProgramParam> itEnd = _params.End();
	for ( ; it != itEnd ; ++it )
	{
		UInt idx = other._buffers.IndexOf( it.Value().Buffer );
		it.Value().Buffer = _buffers[idx];
	}
}

Dx11ParameterSet::~Dx11ParameterSet()
{
	for ( UInt i = 0; i < _buffers.Size(); ++i )
	{
		SafeRelease( _buffers[i] );
	}
}

void Dx11ParameterSet::Bind()
{
	HRESULT hr = S_OK;

	// Update modified buffers, if needed.
	if ( _dirtyBuffers.Size() > 0 )
	{
		MapIterator<Pointer, ID3D11Buffer*> itBuf = _dirtyBuffers.Begin();
		MapIterator<Pointer, ID3D11Buffer*> itBufEnd = _dirtyBuffers.End();
		for ( ; itBuf != itBufEnd ; ++itBuf )
		{
			// Get access to buffer's internal data storage.
			D3D11_MAPPED_SUBRESOURCE subRes;
			Dx11Lock( _context );
			if ( FAILED(hr = _context->Map(itBuf.Value(), 0, D3D11_MAP_WRITE_DISCARD, 0, &subRes)) )
				throw GraphicsException( core::Str::ProgramParameterFail, Dx11::ToString(hr) );

			// Write parameters.
			MapIterator<String, Dx11ProgramParam> it = _params.Begin();
			MapIterator<String, Dx11ProgramParam> itEnd = _params.End();
			for ( ; it != itEnd ; ++it )
			{
				const Dx11ProgramParam& p = it.Value();
				if ( p.Buffer == itBuf.Value() )
				{
					Copy( (Byte*)(subRes.pData)+p.BufferOffset, (const Byte*)(_data.Begin()+p.Offset), p.Size );
				}
			}

			// Commit changes.
			_context->Unmap( itBuf.Value(), 0 );
		}

		_dirtyBuffers.Clear();
	}

	// Bind buffers.
	if ( _buffers.Size() > 0 )
	{
		Dx11Lock( _context );
		switch ( _type )
		{
			case PROGRAM_STAGE_TYPE_VERTEX:
				_context->VSSetConstantBuffers( _startSlot, _buffers.Size(), _buffers.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_HULL:
				_context->HSSetConstantBuffers( _startSlot, _buffers.Size(), _buffers.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_DOMAIN:
				_context->DSSetConstantBuffers( _startSlot, _buffers.Size(), _buffers.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_GEOMETRY:
				_context->GSSetConstantBuffers( _startSlot, _buffers.Size(), _buffers.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_FRAGMENT:
				_context->PSSetConstantBuffers( _startSlot, _buffers.Size(), _buffers.Begin() );
				break;
		}
	}
}

IParameterSet* Dx11ParameterSet::Clone( UInt ownerID, Bool cloneShared ) const
{
	return new Dx11ParameterSet( *this, cloneShared );
}


} // gfx


} // synkro
