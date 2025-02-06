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
// Purpose: DX11 linear texture implementation.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11LINEARTEXTURE_
#define _SYNKRO_GFX_DX11LINEARTEXTURE_


#include "config.h"
#include <gfx/LinearTextureImpl.h>
#include <gfx/ILinearTexture.h>
#undef new
#include "Dx11.h"
#include "Dx11Resource.h"
#include "Dx11ResourceImpl.h"
#define new SYNKRO_NEW


namespace synkro
{


namespace gfx
{


// DirectX 11 linear texture implementation.
class Dx11LinearTexture :
	public LinearTextureImpl<ILinearTexture>,
	public Dx11ResourceImpl<Dx11Resource>
{
public:
	// Constructor & destructor.
	Dx11LinearTexture( Dx11Context* context, const DataUsage& usage, UInt length, const img::PixelFormat& format, UInt levelCount, UInt elementCount );
	~Dx11LinearTexture();

	// ITexture methods.
	void													GenerateLevels();

	// ILinearTexture methods.
	Bool													SetData( UInt element, UInt level, UInt length, const img::PixelFormat& format, const Byte* data );
	void													Write( const Byte* data, UInt size );

private:
	ID3D11Texture1D*										_texture;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11LINEARTEXTURE_
