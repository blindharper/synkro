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
// Purpose: Defines abstract rendering chain.
//==============================================================================
#ifndef _SYNKRO_GFX_RENDERCHAIN_
#define _SYNKRO_GFX_RENDERCHAIN_


#include "config.h"


namespace synkro
{


namespace gfx
{


// Abstract rendering chain.
class RenderChain
{
public:
	// Begins rendering.
	virtual Bool											Begin( IPlainRenderTexture* target ) = 0;

	// Presents rendering results without swapping targets.
	virtual void											Present() = 0;

	// Ends rendering.
	virtual Bool											End() = 0;

	// Retrieves a target of a previous drawing operation.
	virtual IResource*										GetBackBuffer() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_RENDERCHAIN_
