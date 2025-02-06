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
// Purpose: Defines base console.
//==============================================================================
#ifndef _SYNKRO_CONS_BASECONSOLE_
#define _SYNKRO_CONS_BASECONSOLE_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace cons
{


// Base console.
class BaseConsole
{
public:
	virtual void											Print( const lang::String& text ) = 0;
};


// Casts object to BaseConsole.
#define AsBaseConsole( OBJ ) dynamic_cast<BaseConsole*>( OBJ )


} // cons


} // synkro


#endif // _SYNKRO_CONS_BASECONSOLE_
