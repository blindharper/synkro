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
// Purpose: Logical primitive.
//==============================================================================
#include "config.h"
#include "Primitive.h"
#include "NdcVector4Stream.h"
#include "Matrix4x4Stream.h"
#include <gfx/IProgram.h>
#include <gfx/IndexType.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace gfx
{


Primitive::Primitive( IPrimitive* primitive, Program* program ) :
	_vertices( A(P(IDataStream)) ),
	_instances( A(P(IDataStream)) ),
	_primitive( primitive ),
	_program( program )
{
	assert( _primitive != nullptr );
	assert( _program != nullptr );
}

IDataStream* Primitive::GetVertexStream( const DataStream& dataType, UInt index ) const
{
	GetStream func( dataType, index );
	_vertices.Each( func );
	return func.Stream();
}

IDataStream* Primitive::GetInstanceStream( const DataStream& dataType, UInt index ) const
{
	GetStream func( dataType, index );
	_instances.Each( func );
	return func.Stream();
}

void Primitive::Prepare( Ndc* ndc )
{
	if ( _vertices.Size() == 0 )
	{
		InitVertices( _primitive->GetVertexCount(), ndc );
		InitInstances( _primitive->GetInstanceCount() );
		InitIndexes( _primitive->GetIndexCount() );
	}
}

void Primitive::Update()
{
	for ( UInt i = 0; i < _vertices.Size(); ++i )
	{
		NdcVector4Stream* stream = dynamic_cast<NdcVector4Stream*>( _vertices[i].AsPtr() );
		if ( stream != nullptr )
		{
			stream->Update();
		}
	}
}

void Primitive::InitVertices( UInt vertexCount, Ndc* ndc )
{
	IDataFormat* format = _primitive->GetProgram()->GetInputFormat();

	if ( format->GetVertexStreamCount() > 0 )
	{
		// Create buffer.
		UInt vertexSize = 0;
		for ( UInt i = 0; i < format->GetVertexStreamCount(); ++i )
		{
			vertexSize += format->GetVertexStreamDataType( i ).Size();
		}

		// Map streams to the buffer.
		UInt offset = 0;
		Bool interleaved = (format->GetInstanceStreamCount() > 0) ? (_primitive->GetInputBuffers()->GetSize() >= 2) : (_primitive->GetInputBuffers()->GetSize() == 1);
		for ( UInt i = 0; i < format->GetVertexStreamCount(); ++i )
		{
			IDataStream* stream = nullptr;
			DataStream type = format->GetVertexStreamType( i ); 
			ProgramDataType dataType = format->GetVertexStreamDataType( i );
			UInt idx = interleaved ? 0 : i;

			if ( dataType == ProgramDataType::Float )
			{
				stream = new FloatStream( _primitive->GetInputBuffers()->Get(idx), type, offset, vertexCount );
			}
			else if ( dataType == ProgramDataType::Int )
			{
				stream = new LongStream( _primitive->GetInputBuffers()->Get(idx), type, offset, vertexCount );
			}
			else if ( dataType == ProgramDataType::Vector2 )
			{
				stream = new Vector2Stream( _primitive->GetInputBuffers()->Get(idx), type, offset, vertexCount );
			}
			else if ( dataType == ProgramDataType::Vector3 )
			{
				stream = new Vector3Stream( _primitive->GetInputBuffers()->Get(idx), type, offset, vertexCount );
			}
			else if ( dataType == ProgramDataType::Vector4 )
			{
				if ( type == DataStream::Position2D )
					stream = new NdcVector4Stream( _primitive->GetInputBuffers()->Get(idx), type, offset, vertexCount, ndc );
				else
					stream = new Vector4Stream( _primitive->GetInputBuffers()->Get(idx), type, offset, vertexCount );
			}
			else if ( (dataType == ProgramDataType::Matrix4x4) || (dataType == ProgramDataType::Matrix4x4Transposed) )
			{
				stream = new Matrix4x4Stream( _primitive->GetInputBuffers()->Get(idx), type, offset, vertexCount, (dataType == ProgramDataType::Matrix4x4Transposed) );
			}
			else
			{
				throw Exception( String::Format(L"Unknown vertex stream dataType: {0}.", dataType.ToString()) );
			}

			if ( interleaved )
			{
				offset += dataType.Size();
			}
			_vertices.Add( stream );
		}
	}
}

void Primitive::InitInstances( UInt instanceCount )
{
	IDataFormat* format = _primitive->GetProgram()->GetInputFormat();

	if ( format->GetInstanceStreamCount() > 0 )
	{
		// Create buffer.
		UInt instanceSize = 0;
		for ( UInt i = 0; i < format->GetInstanceStreamCount(); ++i )
		{
			instanceSize += format->GetInstanceStreamDataType( i ).Size();
		}

		// Map streams to instance buffers.
		Bool interleaved = (format->GetInstanceStreamCount() > 0) ? (_primitive->GetInputBuffers()->GetSize() >= 2) : (_primitive->GetInputBuffers()->GetSize() == 1);
		UInt cnt = _primitive->GetInputBuffers()->GetSize()-1;
		UInt offset = 0;
		for ( UInt i = 0; i < format->GetInstanceStreamCount(); ++i )
		{
			IDataStream* stream = nullptr;
			DataStream type = format->GetInstanceStreamType( i ); 
			ProgramDataType dataType = format->GetInstanceStreamDataType( i );
			UInt idx = (cnt == 1) ? _primitive->GetInputBuffers()->GetSize()-1 : i+1;

			if ( dataType == ProgramDataType::Float )
			{
				stream = new FloatStream( _primitive->GetInputBuffers()->Get(idx), type, offset, instanceCount );
			}
			else if ( dataType == ProgramDataType::Vector2 )
			{
				stream = new Vector2Stream( _primitive->GetInputBuffers()->Get(idx), type, offset, instanceCount );
			}
			else if ( dataType == ProgramDataType::Vector3 )
			{
				stream = new Vector3Stream( _primitive->GetInputBuffers()->Get(idx), type, offset, instanceCount );
			}
			else if ( dataType == ProgramDataType::Vector4 )
			{
				stream = new Vector4Stream( _primitive->GetInputBuffers()->Get(idx), type, offset, instanceCount );
			}
			else if ( (dataType == ProgramDataType::Matrix4x4) || (dataType == ProgramDataType::Matrix4x4Transposed) )
			{
				stream = new Matrix4x4Stream( _primitive->GetInputBuffers()->Get(idx), type, offset, instanceCount, (dataType == ProgramDataType::Matrix4x4Transposed) );
			}
			else
			{
				throw Exception( String::Format(L"Unknown instance stream dataType: {0}.", dataType.ToString()) );
			}

			if ( cnt == 1 )
			{
				offset += dataType.Size();
			}
			_instances.Add( stream );
		}
	}
}

void Primitive::InitIndexes( UInt indexCount )
{
	if ( _primitive->GetIndexType() == IndexType::Short )
	{
		_indexStream = new ShortStream( (IDataBuffer*)_primitive->GetIndexBuffer(), DataStream::Unknown, 0, indexCount );
	}
	else if ( _primitive->GetIndexType() == IndexType::Long )
	{
		_indexStream = new LongStream( (IDataBuffer*)_primitive->GetIndexBuffer(), DataStream::Unknown, 0, indexCount );
	}
}


} // gfx


} // synkro
