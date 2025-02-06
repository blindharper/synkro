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
// Purpose: Generic frame rendering window implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_FRAMERENDERWINDOWIMPL_
#define _SYNKRO_GFX_FRAMERENDERWINDOWIMPL_


#include "config.h"
#include "RenderWindowImpl.h"
#include <gfx/DisplayMode.h>
#include <win/IFrameWindow.h>


namespace synkro
{


namespace gfx
{


// Generic frame rendering window implementation.
template <class T>
class FrameRenderWindowImpl :
	public RenderWindowImpl<T>
{
public:
	// Constructor & destructor.
	FrameRenderWindowImpl( IGraphicsDevice* device, win::IFrameWindow* window, UInt sampleCount );
	virtual ~FrameRenderWindowImpl();

	// IFrameRenderWindow methods.
	virtual void											GetDisplayMode( DisplayMode& displayMode ) const;
	virtual win::IFrameWindow*								GetWindow() const;

protected:
	win::IFrameWindow*										_window;
	DisplayMode												_displayMode;
};


#include "FrameRenderWindowImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_FRAMERENDERWINDOWIMPL_
