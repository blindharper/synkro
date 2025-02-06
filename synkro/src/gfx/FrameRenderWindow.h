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
// Purpose: Extended frame rendering window.
//==============================================================================
#ifndef _SYNKRO_GFX_FRAMERENDERWINDOW_
#define _SYNKRO_GFX_FRAMERENDERWINDOW_


#include "config.h"
#include <gfx/IFrameRenderWindowEx.h>
#include "BaseRenderWindowImpl.h"
#include "BaseRenderWindow.h"


namespace synkro
{


namespace gfx
{


// Extended frame rendering window.
class FrameRenderWindow :
	public core::ObjectImpl<IFrameRenderWindowEx>,
	public BaseRenderWindowImpl<BaseRenderWindow>,
	public Logger
{
public:
	// Constructor.
	FrameRenderWindow( GraphicsDevice* device, IFrameRenderWindow* window, IProgram* programScreen, IProgram* programView, UInt sampleCount, diag::ILog* log );

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

	// IFrameRenderWindow methods.
	Bool													SetDisplayMode( const DisplayMode& displayMode );
	void													GetDisplayMode( DisplayMode& displayMode ) const;
	win::IFrameWindow*										GetWindow() const;

	// IFrameRenderWindowEx methods.
	IRenderView*											CreateView( Int left, Int top, UInt width, UInt height, UInt sampleCount, const math::Vector4& color );
	void													SetTarget( IPlainRenderTexture* target );
	void													EnableOverlay();
	UInt													GetViewCount() const;
	IRenderView*											GetView( UInt index ) const;
	IPlainRenderTexture*									GetTarget() const;
	IOverlayRenderQueue*									GetOverlayQueue() const;

private:
	P(IFrameRenderWindow)									_window;
	IPlainRenderTexture*									_target;
};


#include "FrameRenderWindow.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_FRAMERENDERWINDOW_
