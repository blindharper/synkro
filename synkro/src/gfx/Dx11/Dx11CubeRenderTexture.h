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
// Purpose: DX11 cube rendering texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11CUBERENDERTEXTURE_
#define _SYNKRO_GFX_DX11CUBERENDERTEXTURE_


#include "config.h"
#include <gfx/CubeRenderTextureImpl.h>
#include <gfx/ICubeRenderTexture.h>
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


// DirectX 11 cube rendering texture implementation.
class Dx11CubeRenderTexture :
	public CubeRenderTextureImpl<ICubeRenderTexture>,
	public Dx11BaseRenderTextureImpl<Dx11BaseRenderTexture>,
	public Dx11ResourceImpl<Dx11Resource>
{
public:
	// Constructors & destructor.
	Dx11CubeRenderTexture( Dx11Context* context, UInt length, const img::PixelFormat& format, UInt sampleCount, UInt sampleQuality );
	~Dx11CubeRenderTexture();

	// IRenderTexture methods.
	Bool													Bind();
	void													Clear();

	// ICubeRenderTexture methods.
	Bool													GetData( const CubeFace& face, UInt* length, UInt* stride, img::PixelFormat* format, Byte** data, UInt* size );

private:
	ID3D11Texture2D*										_texture;
	ID3D11Texture2D*										_textureDst;
	D3D11_VIEWPORT											_viewport;
};


#include "Dx11CubeRenderTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11CUBERENDERTEXTURE_
