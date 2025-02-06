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
// Purpose: Defines standard user interface theme names.
//==============================================================================
#ifndef _SYNKRO_UI_THEMENAME_
#define _SYNKRO_UI_THEMENAME_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace ui
{


/**
 * Standard user interface theme names.
 */
SYNKRO_ENUM_BEGIN( ThemeName )
	/** Custom theme. */
	SYNKRO_ENUM_CONST( ThemeName, Custom )

	/** Glass theme. */
	SYNKRO_ENUM_CONST( ThemeName, Glass )

	/** Glass theme. */
	SYNKRO_ENUM_CONST( ThemeName, Flat )

	/** Creates theme name from string. */
	ThemeName( const lang::String& type );

	/** Converts theme name to string. */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // ui


} // synkro


#endif // _SYNKRO_UI_THEMENAME_
