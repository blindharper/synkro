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
// Purpose: DX11 cube texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11CUBETEXTURE_
#define _SYNKRO_GFX_DX11CUBETEXTURE_


#include "config.h"
#include <gfx/CubeTextureImpl.h>
#include <gfx/ICubeTexture.h>
#undef new
#include "Dx11.h"
#include "Dx11Resource.h"
#include "Dx11ResourceImpl.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 11 cube texture implementation.
class Dx11CubeTexture :
	public CubeTextureImpl<ICubeTexture>,
	public Dx11ResourceImpl<Dx11Resource>
{
public:
	// Constructor & destructor.
	Dx11CubeTexture( Dx11Context* context, const DataUsage& usage, UInt length, const img::PixelFormat& format, UInt levelCount );
	~Dx11CubeTexture();

	// ITexture methods.
	void													GenerateLevels();

	// ICubeTexture methods.
	Bool													SetData( const CubeFace& face, UInt level, UInt length, UInt stride, const img::PixelFormat& format, const Byte* data );

private:
	ID3D11Texture2D*										_texture;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11CUBETEXTURE_
