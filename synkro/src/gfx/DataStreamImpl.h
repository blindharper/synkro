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
// Purpose: Generic data stream implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DATASTREAMIMPL_
#define _SYNKRO_GFX_DATASTREAMIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/IDataBuffer.h>
#include <gfx/ILongStream.h>
#include <gfx/IShortStream.h>
#include <gfx/IFloatStream.h>
#include <gfx/IVector2Stream.h>
#include <gfx/IVector3Stream.h>
#include <gfx/IVector4Stream.h>
#include <io/OpenMode.h>


namespace synkro
{


namespace gfx
{


// Generic data stream implementation.
template <class T, class V>
class DataStreamImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	DataStreamImpl( IDataBuffer* buffer, const DataStream& type, UInt offset, UInt length );
	virtual ~DataStreamImpl();

	// IDataStream methods.
	virtual Bool											Open( const io::OpenMode& mode );
	virtual void											Close();
	virtual void											SetPosition( UInt position );
	virtual UInt											GetPosition() const;
	virtual UInt											GetLength() const;
	virtual DataStream										GetType() const;

	// Other methods.
	virtual void											Read( typename V* data, UInt count );
	virtual void											Write( const typename V* data, UInt count );
	virtual void											Set( const typename V& value, UInt count );

protected:
	IDataBuffer*											_buffer;
	DataStream												_type;
	UInt													_offset;
	UInt													_length;
	UInt													_position;
};


#include "DataStreamImpl.inl"


typedef class DataStreamImpl<IFloatStream, Float> FloatStream;
typedef class DataStreamImpl<ILongStream, UInt> LongStream;
typedef class DataStreamImpl<IShortStream, UShort> ShortStream;
typedef class DataStreamImpl<IVector2Stream, math::Vector2> Vector2Stream;
typedef class DataStreamImpl<IVector3Stream, math::Vector3> Vector3Stream;
typedef class DataStreamImpl<IVector4Stream, math::Vector4> Vector4Stream;


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DATASTREAMIMPL_
