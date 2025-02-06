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
// Purpose: Virtual rendering window.
//==============================================================================
#ifndef _SYNKRO_GFX_VIRTUALRENDERWINDOW_
#define _SYNKRO_GFX_VIRTUALRENDERWINDOW_


#include "config.h"
#include <gfx/IVirtualRenderWindow.h>
#include "BaseRenderWindowImpl.h"
#include "BaseRenderWindow.h"
#include <gfx/IPlainRenderTexture.h>


namespace synkro
{


namespace gfx
{


// Virtual rendering window.
class VirtualRenderWindow :
	public core::ObjectImpl<IVirtualRenderWindow>,
	public BaseRenderWindowImpl<BaseRenderWindow>
{
public:
	// Constructor.
	VirtualRenderWindow( GraphicsDevice* device, UInt width, UInt height, const img::PixelFormat& format, IProgram* programScreen, IProgram* programView, UInt sampleCount, UInt sampleQuality );

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

	// IVirtualRenderWindow methods.
	void													EnableOverlay();
	IRenderView*											GetView() const;
	IPlainRenderTexture*									GetTarget() const;
	IOverlayRenderQueue*									GetOverlayQueue() const;

private:
	P(IPlainRenderTexture)									_target;
};


#include "VirtualRenderWindow.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_VIRTUALRENDERWINDOW_
