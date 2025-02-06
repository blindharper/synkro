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
#ifndef _SYNKRO_GFX_PRIMITIVE_
#define _SYNKRO_GFX_PRIMITIVE_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <gfx/IPrimitiveEx.h>
#include <gfx/IDataFormat.h>
#include <gfx/IDataBufferSet.h>
#include <gfx/IDataStream.h>
#include "Program.h"
#include "Ndc.h"


namespace synkro
{


namespace gfx
{


// Logical primitive.
class Primitive :
	public core::ObjectImpl<IPrimitiveEx>
{
public:
	// Constructor.
	Primitive( IPrimitive* primitive, Program* program );

	// IPrimitive methods.
	UInt													Draw( UInt startElement, UInt elementCount, UInt startInstance, UInt instanceCount );
	UInt													Draw();
	void													Resize( UInt vertexCount, UInt indexCount, UInt instanceCount );
	IProgram*												GetProgram() const;
	IDataBufferSet*											GetInputBuffers() const;
	IDataBufferSet*											GetOutputBuffers() const;
	IIndexBuffer*											GetIndexBuffer() const;
	Bool													HasAdjacency() const;
	IndexType												GetIndexType() const;
	PrimitiveType											GetType() const;
	UInt													GetPointCount() const;
	UInt													GetVertexCount() const;
	UInt													GetIndexCount() const;
	UInt													GetInstanceCount() const;

	// IPrimitiveEx methods.
	IDataStream*											GetVertexStream( const DataStream& type, UInt index ) const;
	IDataStream*											GetInstanceStream( const DataStream& type, UInt index ) const;
	IDataStream*											GetIndexStream() const;

	// Other methods.
	void													Prepare( Ndc* ndc );
	void													Update();

private:
	class GetStream
	{
	public:
		GetStream( const DataStream& dataType, UInt index ) :
			_stream( nullptr ),
			_dataType( dataType ),
			_index( index ),
			_idx( 0 )
		{
		}

		Bool Call( IDataStream* stream )
		{
			if ( (stream->GetType() == _dataType) && (_idx++ == _index) )
			{
				_stream = stream;
				return false;
			}
			return true;
		}

		IDataStream* Stream() const
		{
			return _stream;
		}

		IDataStream* _stream;
		DataStream	_dataType;
		UInt		_index;
		UInt		_idx;
	};

	lang::Vector<P(IDataStream)>							_vertices;
	lang::Vector<P(IDataStream)>							_instances;
	P(IDataStream)											_indexStream;
	P(IPrimitive)											_primitive;
	Program*												_program;

	void													InitVertices( UInt vertexCount, Ndc* ndc );
	void													InitInstances( UInt instanceCount );
	void													InitIndexes( UInt indexCount );
};


#include "Primitive.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PRIMITIVE_
