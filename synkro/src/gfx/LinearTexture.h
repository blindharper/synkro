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
// Purpose: Logical linear texture.
//==============================================================================
#ifndef _SYNKRO_GFX_LINEARTEXTURE_
#define _SYNKRO_GFX_LINEARTEXTURE_


#include "config.h"
#include "BaseResourceImpl.h"
#include "BaseResource.h"
#include "LinearTextureImpl.h"
#include <gfx/ILinearTexture.h>


namespace synkro
{


namespace gfx
{


// Logical linear texture.
class LinearTexture :
	public LinearTextureImpl<ILinearTexture>,
	public BaseResourceImpl<BaseResource>
{
public:
	// Constructor.
	LinearTexture( ILinearTexture* texture );

	// ITexture methods.
	void													GenerateLevels();

	// ILinearTexture methods.
	Bool													SetData( UInt element, UInt level, UInt length, const img::PixelFormat& format, const Byte* data );
	void													Write( const Byte* data, UInt size );

private:
	P(ILinearTexture)										_texture;
};


#include "LinearTexture.inl"


} // gfx


} // synkro


#endif // _SYNKRO_GFX_LINEARTEXTURE_
