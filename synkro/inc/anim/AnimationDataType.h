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
// Purpose: Defines animation data types.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATIONDATATYPE_
#define _SYNKRO_ANIM_ANIMATIONDATATYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace anim
{


/**
 * Animation data types.
 */
SYNKRO_ENUM_BEGIN( AnimationDataType )
	/** Unknown value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Unknown )

	/** Boolean value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Bool )

	/** Color value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Color )

	/** Color gradient value. */
	SYNKRO_ENUM_CONST( AnimationDataType, ColorGradient )

	/** Floating-point value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Float )

	/** Floating-point rectangular value. */
	SYNKRO_ENUM_CONST( AnimationDataType, FloatRect )

	/** Whole-number value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Int )

	/** 4x4-matrix value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Matrix4x4 )

	/** Point value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Point )

	/** Quaternion value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Quaternion )

	/** Range value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Range )

	/** Rectangular value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Rect )

	/** Size value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Size )

	/** 3-component floating-point value. */
	SYNKRO_ENUM_CONST( AnimationDataType, Vector3 )

	/** Creates type from string. */
	AnimationDataType( const lang::String& type );

	/** Converts type to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONDATATYPE_
