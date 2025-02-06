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
// Purpose: Defines font styles.
//==============================================================================
#ifndef _SYNKRO_OVER_FONTSTYLE_
#define _SYNKRO_OVER_FONTSTYLE_


#include "config.h"
#include <lang/Flag.h>


namespace synkro
{


namespace over
{


/**
 * Font styles.
 */
SYNKRO_FLAG_BEGIN( FontStyle )
	/** Normal text. */
	SYNKRO_FLAG_CONST( FontStyle, Normal )

	/** Semibold text. */
	SYNKRO_FLAG_CONST( FontStyle, Bold )

	/** Italics text. */
	SYNKRO_FLAG_CONST( FontStyle, Italic )

	/** Underlined text. */
	SYNKRO_FLAG_CONST( FontStyle, Underline )

	/** Strikeout text. */
	SYNKRO_FLAG_CONST( FontStyle, Strikeout )

	/** Subscript text. */
	SYNKRO_FLAG_CONST( FontStyle, Subscript )

	/** Superscript text. */
	SYNKRO_FLAG_CONST( FontStyle, Superscript )

	/** Creates font style from string. */
	FontStyle( const lang::String& style );

	/** Converts font style to string. */
	lang::String								ToString() const;
SYNKRO_FLAG_END()


} // over


} // synkro


#endif // _SYNKRO_OVER_FONTSTYLE_
