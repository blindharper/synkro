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
// Purpose: Defines input device axes.
//==============================================================================
#ifndef _SYNKRO_INPUT_AXIS_
#define _SYNKRO_INPUT_AXIS_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace input
{


/**
 * Input device axes.
 */
SYNKRO_ENUM_BEGIN( Axis )
	/** Unknown axis. */
	SYNKRO_ENUM_CONST( Axis, Unknown )

	/** X axis. */
	SYNKRO_ENUM_CONST( Axis, X )

	/** Y axis. */
	SYNKRO_ENUM_CONST( Axis, Y )

	/** Z axis. */
	SYNKRO_ENUM_CONST( Axis, Z )

	/** Creates an axis from string. */
	Axis( const lang::String& mode );

	/** Converts axis to string. */
	lang::String								ToString() const;
SYNKRO_ENUM_END()


} // input


} // synkro


#endif // _SYNKRO_INPUT_AXIS_
