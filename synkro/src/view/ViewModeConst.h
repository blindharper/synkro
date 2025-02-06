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
// Purpose: Defines viewport visualization mode constant values.
//==============================================================================
#ifndef _SYNKRO_VIEW_VIEWMODECONST_
#define _SYNKRO_VIEW_VIEWMODECONST_


#include "config.h"


namespace synkro
{


namespace view
{


// Viewport visualization mode constant values.
enum ViewModeConst
{
	VIEW_MODE_COLOR		= 0,
	VIEW_MODE_ALPHA		= 1,
	VIEW_MODE_DEPTH		= 2,
	VIEW_MODE_STENCIL	= 3,
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_VIEWMODECONST_
