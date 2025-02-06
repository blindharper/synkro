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
// Purpose: Logical volume texture.
//==============================================================================
#ifndef _SYNKRO_GFX_VOLUMETEXTURE_
#define _SYNKRO_GFX_VOLUMETEXTURE_


#include "config.h"
#include "BaseResourceImpl.h"
#include "BaseResource.h"
#include "VolumeTextureImpl.h"
#include <gfx/IVolumeTexture.h>


namespace synkro
{


namespace gfx
{


// Logical volume texture.
class VolumeTexture :
	public VolumeTextureImpl<IVolumeTexture>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	VolumeTexture( IVolumeTexture* texture );

	// ITexture methods.
	void													GenerateLevels();

	// IVolumeTexture methods.
	Bool													SetData( UInt element, UInt level, UInt width, UInt height, UInt stride, UInt sliceStride, const img::PixelFormat& format, const Byte* data );

private:
	P(IVolumeTexture)										_texture;
};


#include "VolumeTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_VOLUMETEXTURE_
