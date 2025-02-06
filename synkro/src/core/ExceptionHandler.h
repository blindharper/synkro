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
// Purpose: Visual exception handler.
//==============================================================================
#ifndef _SYNKRO_CORE_EXCEPTIONHANDLER_
#define _SYNKRO_CORE_EXCEPTIONHANDLER_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace core
{


// Visual exception handler.
class ExceptionHandler
{
public:
	static void												Initialize( Pointer module, ISynkro* synkro );
	static void												Show( const lang::String& message );
};


} // core


} // synkro


#endif // _SYNKRO_CORE_EXCEPTIONHANDLER_
