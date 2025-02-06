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
// Purpose: Defines system language.
//==============================================================================
#ifndef _SYNKRO_CORE_LANGUAGE_
#define _SYNKRO_CORE_LANGUAGE_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace core
{


/**
 * System languages.
 */
SYNKRO_ENUM_BEGIN( Language )
	/** Unknown language. */
	SYNKRO_ENUM_CONST( Language, Unknown )

	/** English language. */
	SYNKRO_ENUM_CONST( Language, English )

	/** Russian language. */
	SYNKRO_ENUM_CONST( Language, Russian )

	/** Creates language from string. */
	Language( const lang::String& language );

	/**
	 * Returns the number of characters in the language alphabet.
	 */
	UInt													CharCount() const;

	/**
	 * Returns alphabet character by index.
	 */
	Char													GetChar( UInt index ) const;

	/**
	 * Converts language to string.
	 */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // core


} // synkro


#endif // _SYNKRO_CORE_LANGUAGE_
