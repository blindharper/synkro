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
// Purpose: Generic data buffer implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DATABUFFERIMPL_
#define _SYNKRO_GFX_DATABUFFERIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/DataUsage.h>
#include <gfx/DataAccess.h>
#include <gfx/GraphicsException.h>


namespace synkro
{


namespace gfx
{


// Generic data buffer implementation.
template <class T>
class DataBufferImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	DataBufferImpl( const DataUsage& usage, const DataAccess& access, UInt stride, UInt size );
	virtual ~DataBufferImpl();

	// IDataBuffer methods.
	virtual void											SetData( const Byte* data, UInt size, UInt offset, UInt start, UInt count );
	virtual void											GetData( Byte* data, UInt size, UInt offset, UInt start, UInt count );
	virtual UInt											GetStride() const;
	virtual UInt											GetSize() const;

protected:
	Byte*													_data;
	DataUsage												_usage;
	DataAccess												_access;
	UInt													_stride;
	UInt													_size;
};


#include "DataBufferImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DATABUFFERIMPL_
