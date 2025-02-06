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
// Purpose: Defines texture addressing modes.
//==============================================================================
#ifndef _SYNKRO_GFX_TEXTUREADDRESS_
#define _SYNKRO_GFX_TEXTUREADDRESS_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Method to use for resolving a texture coordinate that is outside the [0.0, 1.0] range.
 */
SYNKRO_ENUM_BEGIN( TextureAddress )
	/** Tile the texture at every integer junction. */
	SYNKRO_ENUM_CONST( TextureAddress, Wrap )

	/** Similar to Wrap, except that the texture is flipped at every integer junction. */
	SYNKRO_ENUM_CONST( TextureAddress, Mirror )

	/** Texture coordinates outside the range [0.0, 1.0] are set to the texture color at 0.0 or 1.0, respectively. */
	SYNKRO_ENUM_CONST( TextureAddress, Clamp )

	/** Texture coordinates outside the range [0.0, 1.0] are set to the border color. */
	SYNKRO_ENUM_CONST( TextureAddress, Border )

	/** Similar to Mirror and Clamp. Takes the absolute value of the texture coordinate (thus, mirroring around 0), and then clamps to the maximum value. */
	SYNKRO_ENUM_CONST( TextureAddress, MirrorOnce )

	/** Creates texture address from string. */
	TextureAddress( const lang::String& address );

	/** Converts texture address to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_TEXTUREADDRESS_
