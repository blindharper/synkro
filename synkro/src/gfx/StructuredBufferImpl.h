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
// Purpose: Generic structured buffer implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_STRUCTUREDBUFFERIMPL_
#define _SYNKRO_GFX_STRUCTUREDBUFFERIMPL_


#include "config.h"
#include <gfx/BufferImpl.h>
#include <gfx/GraphicsException.h>


namespace synkro
{


namespace gfx
{


// Generic structured buffer implementation.
template <class T>
class StructuredBufferImpl :
	public BufferImpl<T>
{
public:
	// Constructor & destructor.
	StructuredBufferImpl( UInt stride, UInt count );
	virtual ~StructuredBufferImpl();

	// IBuffer methods.
	virtual UInt											GetStride() const;
	virtual IStructuredBuffer*								AsStructured() const;

protected:
	UInt													_stride;
};


#include "StructuredBufferImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_STRUCTUREDBUFFERIMPL_
