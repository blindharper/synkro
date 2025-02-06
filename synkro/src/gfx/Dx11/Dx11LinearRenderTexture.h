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
// Purpose: DX11 linear rendering texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11LINEARRENDERTEXTURE_
#define _SYNKRO_GFX_DX11LINEARRENDERTEXTURE_


#include "config.h"
#include <gfx/LinearRenderTextureImpl.h>
#include <gfx/ILinearRenderTexture.h>
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


// DirectX 11 linear rendering texture implementation.
class Dx11LinearRenderTexture :
	public LinearRenderTextureImpl<ILinearRenderTexture>,
	public Dx11BaseRenderTextureImpl<Dx11BaseRenderTexture>,
	public Dx11ResourceImpl<Dx11Resource>
{
public:
	// Constructors & destructor.
	Dx11LinearRenderTexture( Dx11Context* context, UInt length, const img::PixelFormat& format );
	~Dx11LinearRenderTexture();

	// IRenderTexture methods.
	Bool													Bind();
	void													Clear();

	// ILinearRenderTexture methods.
	Bool													GetData( UInt* length, img::PixelFormat* format, Byte** data, UInt* size );

private:
	ID3D11Texture1D*										_texture;
	ID3D11Texture1D*										_textureDst;
};


#include "Dx11LinearRenderTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11LINEARRENDERTEXTURE_
