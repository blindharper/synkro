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
// Purpose: Logical plain texture.
//==============================================================================
#ifndef _SYNKRO_GFX_PLAINTEXTURE_
#define _SYNKRO_GFX_PLAINTEXTURE_


#include "config.h"
#include "PlainTextureImpl.h"
#include <gfx/IPlainTexture.h>
#include "BaseResourceImpl.h"
#include "BaseResource.h"


namespace synkro
{


namespace gfx
{


// Logical plain texture.
class PlainTexture :
	public PlainTextureImpl<IPlainTexture>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	PlainTexture( IPlainTexture* texture );

	// ITexture methods.
	void													GenerateLevels();

	// IPlainTexture methods.
	Bool													SetData( UInt element, UInt level, UInt width, UInt height, UInt stride, const img::PixelFormat& format, const Byte* data );

private:
	P(IPlainTexture)										_texture;
};


#include "PlainTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PLAINTEXTURE_
