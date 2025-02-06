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
// Purpose: Logical plain rendering texture.
//==============================================================================
#ifndef _SYNKRO_GFX_PLAINRENDERTEXTURE_
#define _SYNKRO_GFX_PLAINRENDERTEXTURE_


#include "config.h"
#include <gfx/ResourceImpl.h>
#include <gfx/IPlainRenderTexture.h>
#include "BaseResourceImpl.h"
#include "BaseResource.h"


namespace synkro
{


namespace gfx
{


// Logical plain rendering texture.
class PlainRenderTexture :
	public ResourceImpl<IPlainRenderTexture>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	PlainRenderTexture( IPlainRenderTexture* texture );

	// IResource methods.
	IRenderTexture*											AsRenderTexture() const;

	// IRenderTexture methods.
	Bool													Bind();
	void													Clear();
	Bool													Present();
	void													SetDefaultColor( const math::Vector4& color );
	void													GetDefaultColor( math::Vector4& color ) const;
	img::PixelFormat										GetFormat() const;

	// IPlainRenderTexture methods.
	void													UnbindDepthTexture();
	void													SetDepthTexture( IPlainDepthTexture* texture );
	Bool													GetData( UInt* width, UInt* height, UInt* stride, img::PixelFormat* format, Byte** data, UInt* size );
	IPlainDepthTexture*										GetDepthTexture() const;
	UInt													GetWidth() const;
	UInt													GetHeight() const;

private:
	P(IPlainRenderTexture)									_texture;
	P(IPlainDepthTexture)									_depthTexture;
};


#include "PlainRenderTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PLAINRENDERTEXTURE_
