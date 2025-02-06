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
// Purpose: Defines animation data type constant values.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATIONDATATYPECONST_
#define _SYNKRO_ANIM_ANIMATIONDATATYPECONST_


#include "config.h"


namespace synkro
{


namespace anim
{


// Animation data type constant values.
enum AnimationDataTypeConst
{
	TYPE_UNKNOWN		= 0,
	TYPE_BOOL			= 1,
	TYPE_COLOR			= 2,
	TYPE_COLOR_GRADIENT	= 3,
	TYPE_FLOAT			= 4,
	TYPE_FLOAT_RECT		= 5,
	TYPE_INT			= 6,
	TYPE_MATRIX4X4		= 7,
	TYPE_POINT			= 8,
	TYPE_QUATERNION		= 9,
	TYPE_RANGE			= 10,
	TYPE_RECT			= 11,
	TYPE_SIZE			= 12,	
	TYPE_VECTOR3		= 13,
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONDATATYPECONST_
