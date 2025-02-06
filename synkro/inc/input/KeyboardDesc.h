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
// Purpose: Defines keyboard description.
//==============================================================================
#ifndef _SYNKRO_INPUT_KEYBOARDDESC_
#define _SYNKRO_INPUT_KEYBOARDDESC_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace input
{


/**
 * Keyboard device description.
 */
class SYNKRO_API KeyboardDesc
{
public:
	/** Creates default keyboard description. */
	KeyboardDesc();

	/** Creates keyboard description with the specified properties. */
	KeyboardDesc( const lang::String& name, UInt keyCount );

	/** User-friendly device name. */
	lang::String											Name;

	/** Total number of keys in the keyboard. */
	UInt													KeyCount;
};


} // input


} // synkro


#endif // _SYNKRO_INPUT_KEYBOARDDESC_
