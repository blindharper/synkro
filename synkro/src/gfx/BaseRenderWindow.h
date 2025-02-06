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
// Purpose: Defines abstract rendering window.
//==============================================================================
#ifndef _SYNKRO_GFX_BASERENDERWINDOW_
#define _SYNKRO_GFX_BASERENDERWINDOW_


#include "config.h"
#include <gfx/GraphicsStats.h>


namespace synkro
{


namespace gfx
{


// Abstract rendering window.
class BaseRenderWindow
{
public:
	virtual void											Resize() = 0;
	virtual void											Draw( Double delta, GraphicsStats& stats ) = 0;
	virtual UInt											DrawLast() = 0;
	virtual UInt											DrawScreen( IPlainRenderTexture* texture ) = 0;
	virtual IPlainRenderTexture*							GetIntermediateTarget() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_BASERENDERWINDOW_
