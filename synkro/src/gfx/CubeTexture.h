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
// Purpose: Logical cube texture.
//==============================================================================
#ifndef _SYNKRO_GFX_CUBETEXTURE_
#define _SYNKRO_GFX_CUBETEXTURE_


#include "config.h"
#include "BaseResourceImpl.h"
#include "BaseResource.h"
#include "CubeTextureImpl.h"
#include <gfx/ICubeTexture.h>


namespace synkro
{


namespace gfx
{


// Logical cube texture.
class CubeTexture :
	public CubeTextureImpl<ICubeTexture>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	CubeTexture( ICubeTexture* texture );

	// ITexture methods.
	void													GenerateLevels();

	// ICubeTexture methods.
	Bool													SetData( const CubeFace& face, UInt level, UInt length, UInt stride, const img::PixelFormat& format, const Byte* data );

private:
	P(ICubeTexture)											_texture;
};


#include "CubeTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_CUBETEXTURE_
