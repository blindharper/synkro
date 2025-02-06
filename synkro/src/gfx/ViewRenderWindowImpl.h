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
// Purpose: Generic view rendering window implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_VIEWRENDERWINDOWIMPL_
#define _SYNKRO_GFX_VIEWRENDERWINDOWIMPL_


#include "config.h"
#include "RenderWindowImpl.h"
#include <win/IViewWindow.h>


namespace synkro
{


namespace gfx
{


// Generic view rendering window implementation.
template <class T>
class ViewRenderWindowImpl :
	public RenderWindowImpl<T>
{
public:
	// Constructor & destructor.
	ViewRenderWindowImpl( IGraphicsDevice* device, win::IViewWindow* window, const img::PixelFormat& format, UInt sampleCount );
	virtual ~ViewRenderWindowImpl();

	// IViewRenderWindow methods.
	virtual win::IViewWindow*								GetWindow() const;

protected:
	win::IViewWindow*										_window;
};


#include "ViewRenderWindowImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_VIEWRENDERWINDOWIMPL_
