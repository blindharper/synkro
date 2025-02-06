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
// Purpose: Wildcard mask.
//==============================================================================
#ifndef _SYNKRO_LANG_MASK_
#define _SYNKRO_LANG_MASK_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace lang
{


// Wildcard mask.
class SYNKRO_API Mask
{
public:
	// Constuctor.
	Mask( const String& pattern );

	// Tests if the specified text matches mask pattern.
	Bool													Matches( const String& text ) const;

private:
	String													_pattern;

	static Bool												IsWildcard( Char c );
	static String											GetNonWildcardString( const String& pattern, UInt pos );
	static Bool												MatchesPattern( const String& pattern, const String& text );
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_MASK_
