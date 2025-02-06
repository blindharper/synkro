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
// Purpose: Extended view rendering window.
//==============================================================================
#ifndef _SYNKRO_GFX_VIEWRENDERWINDOW_
#define _SYNKRO_GFX_VIEWRENDERWINDOW_


#include "config.h"
#include <gfx/IViewRenderWindowEx.h>
#include "BaseRenderWindowImpl.h"
#include "BaseRenderWindow.h"


namespace synkro
{


namespace gfx
{


// Extended view rendering window.
class ViewRenderWindow :
	public core::ObjectImpl<IViewRenderWindowEx>,
	public BaseRenderWindowImpl<BaseRenderWindow>
{
public:
	// Constructor.
	ViewRenderWindow( GraphicsDevice* device, IViewRenderWindow* window, IProgram* programScreen, IProgram* programView, UInt sampleCount );

	// IRenderWindow methods.
	Bool													Bind();
	void													Clear();
	Bool													Present();
	void													SetDefaultColor( const math::Vector4& color );
	void													GetDefaultColor( math::Vector4& color ) const;
	img::PixelFormat										GetClientPixelFormat() const;
	img::PixelFormat										GetPixelFormat() const;
	UInt													GetWidth() const;
	UInt													GetHeight() const;
	UInt													GetSampleCount() const;
	IGraphicsDevice*										GetDevice() const;

	// IViewRenderWindow methods.
	win::IViewWindow*										GetWindow() const;

	// IViewRenderWindowEx methods.
	void													EnableOverlay();
	IRenderView*											GetView() const;
	IOverlayRenderQueue*									GetOverlayQueue() const;

private:
	P(IViewRenderWindow)									_window;
};


#include "ViewRenderWindow.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_VIEWRENDERWINDOW_
