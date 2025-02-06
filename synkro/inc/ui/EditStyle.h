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
// Purpose: Defines text edit styles.
//==============================================================================
#ifndef _SYNKRO_UI_EDITSTYLE_
#define _SYNKRO_UI_EDITSTYLE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace ui
{


/**
 * Text edit styles.
 */
SYNKRO_ENUM_BEGIN( EditStyle )
	/** Editor with no styles applied. */
	SYNKRO_ENUM_CONST( EditStyle, Normal )

	/** Editor converting text to upper case. */
	SYNKRO_ENUM_CONST( EditStyle, Upper )

	/** Editor converting text to lower case. */
	SYNKRO_ENUM_CONST( EditStyle, Lower )

	/** Editor that allows integer numeric input only. */
	SYNKRO_ENUM_CONST( EditStyle, Integer )

	/** Editor that allows decimal numeric input only. */
	SYNKRO_ENUM_CONST( EditStyle, Decimal )

	/** Editor that allows hexadecimal input only. */
	SYNKRO_ENUM_CONST( EditStyle, Hexadecimal )

	/** Creates edit style from string. */
	EditStyle( const lang::String& style );

	/** Converts edit style to string. */
	lang::String								ToString() const;
SYNKRO_ENUM_END()


} // ui


} // synkro


#endif // _SYNKRO_UI_EDITSTYLE_
