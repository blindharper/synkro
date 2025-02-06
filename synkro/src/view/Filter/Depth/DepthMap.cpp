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
// Purpose: Depth map implementation.
//==============================================================================
#include "config.h"
#include "DepthMap.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


DepthMap::DepthMap( IPlainDepthTexture* texture ) :
	_texture( texture )
{
}


} // view


} // synkro
