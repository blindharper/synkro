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
// Purpose: DX11 plain texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11PLAINTEXTURE_
#define _SYNKRO_GFX_DX11PLAINTEXTURE_


#include "config.h"
#include <gfx/PlainTextureImpl.h>
#include <gfx/IPlainTexture.h>
#undef new
#include "Dx11.h"
#include "Dx11Resource.h"
#include "Dx11ResourceImpl.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 11 plain texture implementation.
class Dx11PlainTexture :
	public PlainTextureImpl<IPlainTexture>,
	public Dx11ResourceImpl<Dx11Resource>
{
public:
	// Constructor & destructor.
	Dx11PlainTexture( Dx11Context* context, const DataUsage& usage, UInt width, UInt height, const img::PixelFormat& format, UInt levelCount, UInt elementCount );
	~Dx11PlainTexture();

	// ITexture methods.
	void													GenerateLevels();

	// IPlainTexture methods.
	Bool													SetData( UInt element, UInt level, UInt width, UInt height, UInt stride, const img::PixelFormat& format, const Byte* data );

private:
	ID3D11Texture2D*										_texture;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11PLAINTEXTURE_
