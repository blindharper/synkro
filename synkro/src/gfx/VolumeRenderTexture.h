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
// Purpose: Logical volume rendering texture.
//==============================================================================
#ifndef _SYNKRO_GFX_VOLUMERENDERTEXTURE_
#define _SYNKRO_GFX_VOLUMERENDERTEXTURE_


#include "config.h"
#include <gfx/ResourceImpl.h>
#include <gfx/IVolumeRenderTexture.h>
#include "BaseResourceImpl.h"
#include "BaseResource.h"


namespace synkro
{


namespace gfx
{


// Logical volume rendering texture.
class VolumeRenderTexture :
	public ResourceImpl<IVolumeRenderTexture>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	VolumeRenderTexture( IVolumeRenderTexture* texture );

	// IResource methods.
	IRenderTexture*											AsRenderTexture() const;

	// IRenderTexture methods.
	Bool													Bind();
	void													Clear();
	Bool													Present();
	void													SetDefaultColor( const math::Vector4& color );
	void													GetDefaultColor( math::Vector4& color ) const;
	img::PixelFormat										GetFormat() const;

	// IVolumeRenderTexture methods.
	Bool													GetData( UInt element, UInt* width, UInt* height, UInt* depth, UInt* stride, UInt* sliceStride, img::PixelFormat* format, Byte** data, UInt* size );
	UInt													GetWidth() const;
	UInt													GetHeight() const;
	UInt													GetDepth() const;

private:
	P(IVolumeRenderTexture)									_texture;
};


#include "VolumeRenderTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_VOLUMERENDERTEXTURE_
