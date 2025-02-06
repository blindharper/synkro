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
// Purpose: DX11 rendering plain texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11PLAINRENDERTEXTURE_
#define _SYNKRO_GFX_DX11PLAINRENDERTEXTURE_


#include "config.h"
#include <gfx/PlainRenderTextureImpl.h>
#include <gfx/IPlainRenderTexture.h>
#include <gfx/Dx/DxGi.h>
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


// DirectX 11 plain rendering texture.
class Dx11PlainRenderTexture :
	public PlainRenderTextureImpl<IPlainRenderTexture>,
	public Dx11BaseRenderTextureImpl<Dx11BaseRenderTexture>,
	public Dx11ResourceImpl<Dx11Resource>
{
public:
	// Constructor & destructor.
	Dx11PlainRenderTexture( Dx11Context* context, UInt width, UInt height, const img::PixelFormat& format, UInt sampleCount, UInt sampleQuality );
	~Dx11PlainRenderTexture();

	// IRenderTexture methods.
	Bool													Bind();
	void													Clear();
	Bool													Present();

	// IPlainRenderTexture methods.
	void													UnbindDepthTexture();
	void													SetDepthTexture( IPlainDepthTexture* texture );
	Bool													GetData( UInt* width, UInt* height, UInt* stride, img::PixelFormat* format, Byte** data, UInt* size );
	IPlainDepthTexture*										GetDepthTexture() const;

private:
	ID3D11Texture2D*										_texture;
	ID3D11Texture2D*										_textureMS;
	ID3D11Texture2D*										_textureDst;
	ID3D11DepthStencilView*									_dsv;
	D3D11_VIEWPORT											_viewport;
	IPlainDepthTexture*										_depthTexture;
};


#include "Dx11PlainRenderTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11PLAINRENDERTEXTURE_
