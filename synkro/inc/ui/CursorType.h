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
// Purpose: Defines cursor types.
//==============================================================================
#ifndef _SYNKRO_UI_CURSORTYPE_
#define _SYNKRO_UI_CURSORTYPE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace ui
{


/**
 * Cursor types.
 */
SYNKRO_ENUM_BEGIN( CursorType )
	/** Default pointer cursor. */
	SYNKRO_ENUM_CONST( CursorType, Pointer )

	/** Hand cursor. */
	SYNKRO_ENUM_CONST( CursorType, Hand )

	/** Cursor is over an editable text. */
	SYNKRO_ENUM_CONST( CursorType, IBeam )
SYNKRO_ENUM_END()


} // ui


} // synkro


#endif // _SYNKRO_UI_CURSORTYPE_
