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
// Purpose: Generic rendering queue implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RENDERQUEUEIMPL_
#define _SYNKRO_GFX_RENDERQUEUEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>


namespace synkro
{


namespace gfx
{


// Generic rendering queue implementation.
template <class T>
class RenderQueueImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	RenderQueueImpl();
	virtual ~RenderQueueImpl();

	// IRenderQueue methods.
	virtual void											Enable( Bool enable );
	virtual Bool											IsEnabled() const;

protected:
	Bool													_enabled;
};


#include "RenderQueueImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RENDERQUEUEIMPL_
