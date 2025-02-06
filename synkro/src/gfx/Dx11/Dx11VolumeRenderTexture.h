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
// Purpose: DX11 volume rendering texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11VOLUMERENDERTEXTURE_
#define _SYNKRO_GFX_DX11VOLUMERENDERTEXTURE_


#include "config.h"
#include <gfx/VolumeRenderTextureImpl.h>
#include <gfx/IVolumeRenderTexture.h>
#undef new
#include "Dx11BaseRenderTextureImpl.h"
#include "Dx11BaseRenderTexture.h"
#include "Dx11ResourceImpl.h"
#include "Dx11Resource.h"
#include "Dx11.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 11 volume rendering texture implementation.
class Dx11VolumeRenderTexture :
	public VolumeRenderTextureImpl<IVolumeRenderTexture>,
	public Dx11BaseRenderTextureImpl<Dx11BaseRenderTexture>,
	public Dx11ResourceImpl<Dx11Resource>
{
public:
	// Constructors & destructor.
	Dx11VolumeRenderTexture( Dx11Context* context, UInt width, UInt height, UInt depth, const img::PixelFormat& format );
	~Dx11VolumeRenderTexture();

	// IRenderTexture methods.
	Bool													Bind();
	void													Clear();

	// IVolumeRenderTexture methods.
	Bool													GetData( UInt element, UInt* width, UInt* height, UInt* depth, UInt* stride, UInt* sliceStride, img::PixelFormat* format, Byte** data, UInt* size );

private:
	ID3D11Texture3D*										_texture;
	ID3D11Texture3D*										_textureDst;
};


#include "Dx11VolumeRenderTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11VOLUMERENDERTEXTURE_
