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
// Purpose: Defines texture filtering modes.
//==============================================================================
#ifndef _SYNKRO_GFX_TEXTUREFILTER_
#define _SYNKRO_GFX_TEXTUREFILTER_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Texture filtering modes.
 */
SYNKRO_ENUM_BEGIN( TextureFilter )
	/** Point filtering. The texel with coordinates nearest to the desired pixel value is used. */
	SYNKRO_ENUM_CONST( TextureFilter, Point )

	/** Bilinear interpolation filtering used as a texture magnification or minification filter. A weighted average of a 2x2 area of texels surrounding the desired pixel is used. */
	SYNKRO_ENUM_CONST( TextureFilter, Linear )

	/** Anisotropic texture filtering. Compensates for distortion caused by the difference in angle between the texture polygon and the plane of the screen. */
	SYNKRO_ENUM_CONST( TextureFilter, Anisotropic )

	/** A 4-sample tent filter used as a texture magnification or minification filter. */
	SYNKRO_ENUM_CONST( TextureFilter, PyramidalQuad )

	/** A 4-sample Gaussian filter used as a texture magnification or minification filter. */
	SYNKRO_ENUM_CONST( TextureFilter, GaussianQuad )

	/** Creates texture filter from string. */
	TextureFilter( const lang::String& filter );

	/** Converts texture filter to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_TEXTUREFILTER_
