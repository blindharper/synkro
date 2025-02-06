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
// Purpose: Generic buffer implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_BUFFERIMPL_
#define _SYNKRO_GFX_BUFFERIMPL_


#include "config.h"
#include <gfx/ResourceImpl.h>
#include <gfx/GraphicsException.h>
#include <gfx/ProgramDataType.h>


namespace synkro
{


namespace gfx
{


// Generic buffer implementation.
template <class T>
class BufferImpl :
	public ResourceImpl<T>
{
public:
	// Constructor & destructor.
	BufferImpl( UInt size );
	virtual ~BufferImpl();

	// IResource methods.
	virtual IBuffer*										AsBuffer() const;

	// IBuffer methods.
	virtual UInt											GetSize() const;
	virtual ITypedBuffer*									AsTyped() const;
	virtual IStructuredBuffer*								AsStructured() const;

protected:
	UInt													_size;
};


#include "BufferImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BUFFERIMPL_
