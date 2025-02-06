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
// Purpose: Generic typed buffer implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_TYPEDBUFFERIMPL_
#define _SYNKRO_GFX_TYPEDBUFFERIMPL_


#include "config.h"
#include <gfx/BufferImpl.h>
#include <gfx/GraphicsException.h>
#include <gfx/ProgramDataType.h>


namespace synkro
{


namespace gfx
{


// Generic typed buffer implementation.
template <class T>
class TypedBufferImpl :
	public BufferImpl<T>
{
public:
	// Constructor & destructor.
	TypedBufferImpl( const ProgramDataType& dataType, UInt count );
	virtual ~TypedBufferImpl();

	// ITypedBuffer methods.
	virtual ProgramDataType									GetDataType() const;
	virtual ITypedBuffer*									AsTyped() const;

protected:
	ProgramDataType											_dataType;
};


#include "TypedBufferImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_TYPEDBUFFERIMPL_
