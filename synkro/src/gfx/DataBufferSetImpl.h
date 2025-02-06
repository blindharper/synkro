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
// Purpose: Generic data buffer set implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DATABUFFERSETIMPL_
#define _SYNKRO_GFX_DATABUFFERSETIMPL_


#include "config.h"
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <gfx/IDataBuffer.h>


namespace synkro
{


namespace gfx
{


// Generic data buffer set implementation.
template <class T, class B>
class DataBufferSetImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	DataBufferSetImpl();
	virtual ~DataBufferSetImpl();

	// IDataBufferSet methods.
	virtual UInt											GetSize() const;
	virtual IDataBuffer*									Get( UInt index ) const;

protected:
	lang::Vector<P(B)>										_buffers;
};


#include "DataBufferSetImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DATABUFFERSETIMPL_
