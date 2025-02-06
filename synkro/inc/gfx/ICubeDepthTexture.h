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
// Purpose: Defines cube depth texture.
//==============================================================================
#ifndef _SYNKRO_GFX_ICUBEDEPTHTEXTURE_
#define _SYNKRO_GFX_ICUBEDEPTHTEXTURE_


#include "config.h"
#include <gfx/IDepthTexture.h>
#include <gfx/CubeFace.h>


namespace synkro
{


namespace gfx
{


/**
 * Cube depth texture.
 */
iface ICubeDepthTexture :
	public IDepthTexture
{
public:
	/**
	 * Binds a particular texture face to the pipeline.
	 * @param face Cube face to bind.
	 * @return True, if the texture face has been successfully bound, false otherwise.
	 */
	virtual Bool											BindFace( const CubeFace& face ) = 0;

	/**
	 * Retrieves texture edge length.
	 */
	virtual UInt											GetLength() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_ICUBEDEPTHTEXTURE_
