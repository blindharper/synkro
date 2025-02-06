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
// Purpose: Generic rendering texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_RENDERTEXTUREIMPL_
#define _SYNKRO_GFX_RENDERTEXTUREIMPL_


#include "config.h"
#include <gfx/ResourceImpl.h>
#include <gfx/GraphicsException.h>
#include <img/PixelFormat.h>
#include <math/Vector4.h>


namespace synkro
{


namespace gfx
{


// Generic rendering texture implementation.
template <class T>
class RenderTextureImpl :
	public ResourceImpl<T>
{
public:
	// Constructors & destructor.
	RenderTextureImpl( const img::PixelFormat& format );
	virtual ~RenderTextureImpl();

	// IResource methods.
	virtual IRenderTexture*									AsRenderTexture() const;

	// IRenderTexture methods.
	virtual Bool											Present();
	virtual	void											SetDefaultColor( const math::Vector4& color );
	virtual	void											GetDefaultColor( math::Vector4& color ) const;
	virtual img::PixelFormat								GetFormat() const;

protected:
	math::Vector4											_defaultColor;
	img::PixelFormat										_format;
};


#include "RenderTextureImpl.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RENDERTEXTUREIMPL_
