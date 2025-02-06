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
// Purpose: DX11 based resource set implementation.
//==============================================================================
#include "config.h"
#include "Dx11ResourceSet.h"
#include <gfx/ProgramStageTypeConst.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11ResourceSet::Dx11ResourceSet( Dx11Context* context, ID3D11ShaderReflection* reflect, const ProgramStageType& type, UINT startSlot ) :
	ResourceSetImpl<IResourceSet, Dx11Resource>( type ),
	_views( A(ID3D11ShaderResourceView*) ),
	_nulls( A(ID3D11ShaderResourceView*) ),
	_startSlot( startSlot ),
	_context( context )
{
	D3D11_SHADER_DESC desc;
	reflect->GetDesc( &desc );
	for ( UINT i = 0; i < desc.BoundResources; ++i )
	{
		D3D11_SHADER_INPUT_BIND_DESC paramDesc;
		reflect->GetResourceBindingDesc( i, &paramDesc );
		switch ( paramDesc.Type )
		{
			case D3D10_SIT_TEXTURE:
			case D3D11_SIT_STRUCTURED:
				_resources.Add( nullptr );
				_views.Add( nullptr );
				_nulls.Add( nullptr );
				break;

			default:
				break;
		}
	}
}

Dx11ResourceSet::Dx11ResourceSet( const Dx11ResourceSet& other ) :
	ResourceSetImpl<IResourceSet, Dx11Resource>( other._type ),
	_views( A(ID3D11ShaderResourceView*) ),
	_nulls( A(ID3D11ShaderResourceView*) ),
	_startSlot( other._startSlot ),
	_context( &other._context )
{
	for ( UInt i = 0; i < other._resources.Size(); ++i )
	{
		_resources.Add( other._resources[i] );
		_views.Add( other._views[i] );
		_nulls.Add( nullptr );
	}
}

void Dx11ResourceSet::Set( UInt index, IResource* resource )
{
	// Call base implementation.
	ResourceSetImpl<IResourceSet, Dx11Resource>::Set( index, resource );

	if ( resource != nullptr )
	{
		Dx11Resource* tex = AsDx11Resource( resource );
		_views[index] = tex->AsDx11ShaderResourceView();
	}
	else
	{
		_views[index] = nullptr;
	}
}

void Dx11ResourceSet::Bind()
{
	if ( _views.Size() > 0 )
	{
		Dx11Lock( _context );
		switch ( _type )
		{
			case PROGRAM_STAGE_TYPE_VERTEX:
				_context->VSSetShaderResources( _startSlot, _views.Size(), _views.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_HULL:
				_context->HSSetShaderResources( _startSlot, _views.Size(), _views.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_DOMAIN:
				_context->DSSetShaderResources( _startSlot, _views.Size(), _views.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_GEOMETRY:
				_context->GSSetShaderResources( _startSlot, _views.Size(), _views.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_FRAGMENT:
				_context->PSSetShaderResources( _startSlot, _views.Size(), _views.Begin() );
				break;
		}
	}
}

void Dx11ResourceSet::Unbind()
{
	if ( _views.Size() > 0 )
	{
		Dx11Lock( _context );
		switch ( _type )
		{
			case PROGRAM_STAGE_TYPE_VERTEX:
				_context->VSSetShaderResources( _startSlot, _views.Size(), _nulls.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_HULL:
				_context->HSSetShaderResources( _startSlot, _views.Size(), _nulls.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_DOMAIN:
				_context->DSSetShaderResources( _startSlot, _views.Size(), _nulls.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_GEOMETRY:
				_context->GSSetShaderResources( _startSlot, _views.Size(), _nulls.Begin() );
				break;

			case PROGRAM_STAGE_TYPE_FRAGMENT:
				_context->PSSetShaderResources( _startSlot, _views.Size(), _nulls.Begin() );
				break;
		}
	}
}

IResourceSet* Dx11ResourceSet::Clone( UInt ownerID ) const
{
	return new Dx11ResourceSet( *this );
}


} // gfx


} // synkro
