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
// Purpose: Defines stereo mode constant values.
//==============================================================================
#ifndef _SYNKRO_VIEW_STEREOMODECONST_
#define _SYNKRO_VIEW_STEREOMODECONST_


#include "config.h"


namespace synkro
{


namespace view
{


// Stereo mode constant values.
enum StereoModeConst
{
	STEREO_MODE_NONE			= 0,
	STEREO_MODE_TRUE			= 1,
	STEREO_MODE_RED_CYAN		= 2,
	STEREO_MODE_GREEN_MAGENTA	= 3,
	STEREO_MODE_BLUE_YELLOW		= 4,
	STEREO_MODE_CYAN_RED		= 5,
	STEREO_MODE_MAGENTA_GREEN	= 6,
	STEREO_MODE_YELLOW_BLUE		= 7,
};


} // anim


} // view


#endif // _SYNKRO_VIEW_STEREOMODECONST_
