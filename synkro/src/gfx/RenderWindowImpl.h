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
// Purpose: Generic rendering window implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RENDERWINDOWIMPL_
#define _SYNKRO_GFX_RENDERWINDOWIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <gfx/GraphicsException.h>
#include <win/IWindow.h>
#include <img/PixelFormat.h>
#include <math/Vector4.h>


namespace synkro
{


namespace gfx
{


// Generic rendering window implementation.
template <class T>
class RenderWindowImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	RenderWindowImpl( IGraphicsDevice* device, win::IWindow* window, const img::PixelFormat& format, UInt sampleCount );
	virtual ~RenderWindowImpl();

	// IRenderWindow methods.
	virtual	void											SetDefaultColor( const math::Vector4& color );
	virtual	void											GetDefaultColor( math::Vector4& color ) const;
	virtual img::PixelFormat								GetClientPixelFormat() const;
	virtual img::PixelFormat								GetPixelFormat() const;
	virtual UInt											GetWidth() const;
	virtual UInt											GetHeight() const;
	virtual UInt											GetSampleCount() const;
	virtual IGraphicsDevice*								GetDevice() const;

protected:
	IGraphicsDevice*										_device;
	win::IWindow*											_baseWindow;
	math::Vector4											_defaultColor;
	img::PixelFormat										_clientFormat;
	img::PixelFormat										_format;
	UInt													_sampleCount;
};


#include "RenderWindowImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RENDERWINDOWIMPL_
