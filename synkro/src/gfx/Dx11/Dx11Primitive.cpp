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
// Purpose: DX11 primitive implementation.
//==============================================================================
#include "config.h"
#include "Dx11Primitive.h"
#include "Dx11VertexBuffer.h"
#include "Dx11IndexBuffer.h"
#include "Dx11VertexBufferSet.h"
#include "Dx11OutputBufferSet.h"
#include "Dx11Program.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Dx11Primitive::Dx11Primitive( Dx11Context* context, IProgram* program, const DataUsage& usage, const DataAccess& access, const PrimitiveType& type, const IndexType& indexType, UInt vertexCount, UInt indexCount, UInt instanceCount, UInt pointCount, Bool interleaved, Bool adjacency ) :
	PrimitiveImpl<IPrimitive>( program, indexType, type, vertexCount, indexCount, instanceCount, pointCount, adjacency ),
	_context( context ),
	_first( true )
{
	HRESULT hr = S_OK;

	// Get vertex declaration.
	Dx11Program* dx11Program = dynamic_cast<Dx11Program*>( program );
	_layout = interleaved ? dx11Program->_layoutInterleaved : dx11Program->_layout;
	if ( _layout != nullptr )
	{
		_layout->AddRef();
	}

	// Calculate the total number of low-level primitives.
	_primitiveType = Dx11::Convert( type, pointCount, adjacency );

	// Create input buffers.
	IDataFormat* format = program->GetInputFormat();
	Dx11VertexBufferSet* inputBuffers = new Dx11VertexBufferSet( context );
	if ( interleaved )
	{
		UInt vertexSize = 0;
		for ( UInt i = 0; i < format->GetVertexStreamCount(); ++i )
		{
			vertexSize += format->GetVertexStreamDataType( i ).Size();
		}
		inputBuffers->AddBuffer( new Dx11VertexBuffer(inputBuffers, context, usage, access, vertexSize, vertexCount) );
	}
	else
	{
		for ( UInt i = 0; i < format->GetVertexStreamCount(); ++i )
		{
			UInt size = format->GetVertexStreamDataType( i ).Size();
			inputBuffers->AddBuffer( new Dx11VertexBuffer(inputBuffers, context, usage, access, size, vertexCount) );
		}
	}

	if ( format->GetInstanceStreamCount() > 0 )
	{
		UInt instanceSize = 0;
		for ( UInt i = 0; i < format->GetInstanceStreamCount(); ++i )
		{
			instanceSize += format->GetInstanceStreamDataType( i ).Size();
		}
		inputBuffers->AddBuffer( new Dx11VertexBuffer(inputBuffers, context, usage, access, instanceSize, instanceCount) );
	}
	_inputBuffers = inputBuffers;

	if ( indexType != IndexType::None )
	{
		_indexBuffer = new Dx11IndexBuffer( context, usage, access, indexType, indexCount );
	}

	// Create output buffers.
	if ( (program->GetGeometryStage() != nullptr) && (program->GetOutputFormat() != nullptr) )
	{
		Dx11OutputBufferSet* outputBuffers = new Dx11OutputBufferSet( context );
		IDataFormat* outputFormat = program->GetOutputFormat();
		outputBuffers->AddBuffer( new Dx11OutputBuffer(_context.Device(), outputFormat, vertexCount) );
		_outputBuffers = outputBuffers;
	}
}

Dx11Primitive::~Dx11Primitive()
{
	SafeRelease( _layout );
}

UInt Dx11Primitive::Draw( UInt startElement, UInt elementCount, UInt startInstance, UInt instanceCount )
{
	Dx11Lock( _context );
	_context->IASetInputLayout( _layout );
	_context->IASetPrimitiveTopology( _primitiveType );

	UInt primitiveCount = PrimitiveType::GetPrimitiveCount( _primitiveType, elementCount );
	if ( _instanceCount != 0 )
	{
		if ( _indexCount != 0 )
			_context->DrawIndexedInstanced( elementCount, instanceCount, startElement, 0, startInstance );
		else
			_context->DrawInstanced( elementCount, instanceCount, startElement, startInstance );

		return instanceCount * primitiveCount;
	}
	else
	{
		if ( _indexCount != 0 )
			_context->DrawIndexed( elementCount, startElement, 0 );
		else
			_context->Draw( elementCount, startElement );

		return primitiveCount;
	}
}

void Dx11Primitive::Resize( UInt vertexCount, UInt indexCount, UInt instanceCount )
{
	if ( vertexCount != _vertexCount )
	{
		UInt cnt = (_instanceCount > 0) ? _inputBuffers->GetSize()-1 : _inputBuffers->GetSize();
		for ( UInt i = 0; i < cnt; ++i )
		{
			_inputBuffers->Get( i )->Resize( vertexCount );
		}
		_vertexCount = vertexCount;
	}

	if ( indexCount != _indexCount )
	{
		if ( _indexBuffer != nullptr )
		{
			_indexBuffer->Resize( indexCount );
		}
		_indexCount = indexCount;
	}

	if ( instanceCount != _instanceCount )
	{
		UInt idx = _inputBuffers->GetSize()-1;
		_inputBuffers->Get( idx )->Resize( instanceCount );
		_instanceCount = instanceCount;
	}
}


} // gfx


} // synkro
