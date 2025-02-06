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
// Purpose: Defines comparison functions.
//==============================================================================
#ifndef _SYNKRO_GFX_COMPAREFUNCTION_
#define _SYNKRO_GFX_COMPAREFUNCTION_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace gfx
{


/**
 * Comparison functions.
 */
SYNKRO_ENUM_BEGIN( CompareFunction )
	/** Always fails. */
	SYNKRO_ENUM_CONST( CompareFunction, Never )

	/** Succeeds if new value is less than the old one. */
	SYNKRO_ENUM_CONST( CompareFunction, Less )

	/** Succeeds if new value is equal to the old one. */
	SYNKRO_ENUM_CONST( CompareFunction, Equal )

	/** Succeeds if new value is less or equal to the old one. */
	SYNKRO_ENUM_CONST( CompareFunction, LessOrEqual )

	/** Succeeds if new value is greater than the old one. */
	SYNKRO_ENUM_CONST( CompareFunction, Greater )

	/** Succeeds if new value is not equal to the old one. */
	SYNKRO_ENUM_CONST( CompareFunction, NotEqual )

	/** Succeeds if new value is greater or equal to the old one. */
	SYNKRO_ENUM_CONST( CompareFunction, GreaterOrEqual )

	/** Always succeeds. */
	SYNKRO_ENUM_CONST( CompareFunction, Always )

	/** Creates comparison function from string. */
	CompareFunction( const lang::String& function );

	/** Converts comparison function to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_COMPAREFUNCTION_
