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
// Purpose: Generic rendering state implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RENDERSTATEIMPL_
#define _SYNKRO_GFX_RENDERSTATEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/GraphicsException.h>


namespace synkro
{


namespace gfx
{


// Generic rendering state implementation.
template <class T>
class RenderStateImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	RenderStateImpl();
	virtual ~RenderStateImpl();

protected:
	Bool													_dirty;
};


#include "RenderStateImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RENDERSTATEIMPL_
