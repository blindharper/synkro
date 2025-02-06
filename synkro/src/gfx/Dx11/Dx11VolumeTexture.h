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
// Purpose: DX11 volume texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11VOLUMETEXTURE_
#define _SYNKRO_GFX_DX11VOLUMETEXTURE_


#include "config.h"
#include <gfx/VolumeTextureImpl.h>
#include <gfx/IVolumeTexture.h>
#undef new
#include "Dx11.h"
#include "Dx11Resource.h"
#include "Dx11ResourceImpl.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 11 volume texture implementation.
class Dx11VolumeTexture :
	public VolumeTextureImpl<IVolumeTexture>,
	public Dx11ResourceImpl<Dx11Resource>
{
public:
	// Constructor & destructor.
	Dx11VolumeTexture( Dx11Context* context, const DataUsage& usage, UInt width, UInt height, UInt depth, const img::PixelFormat& format, UInt levelCount );
	~Dx11VolumeTexture();

	// ITexture methods.
	void													GenerateLevels();

	// IVolumeTexture methods.
	Bool													SetData( UInt element, UInt level, UInt width, UInt height, UInt stride, UInt sliceStride, const img::PixelFormat& format, const Byte* data );

private:
	ID3D11Texture3D*										_texture;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11VOLUMETEXTURE_
