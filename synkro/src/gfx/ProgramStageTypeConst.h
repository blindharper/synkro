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
// Purpose: Defines graphics program stage type constant values.
//==============================================================================
#ifndef _SYNKRO_GFX_PROGRAMSTAGETYPECONST_
#define _SYNKRO_GFX_PROGRAMSTAGETYPECONST_


#include "config.h"


namespace synkro
{


namespace gfx
{


// Graphics program stage type constant values.
enum ProgramStageTypeConst
{
	PROGRAM_STAGE_TYPE_UNKNOWN	= 0,
	PROGRAM_STAGE_TYPE_VERTEX	= 1,
	PROGRAM_STAGE_TYPE_HULL		= 2,
	PROGRAM_STAGE_TYPE_DOMAIN	= 3,
	PROGRAM_STAGE_TYPE_GEOMETRY	= 4,
	PROGRAM_STAGE_TYPE_FRAGMENT	= 5,
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_PROGRAMSTAGETYPECONST_
