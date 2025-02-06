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
// Purpose: Defines stack overflow exception.
//==============================================================================
#ifndef _SYNKRO_LANG_STACKOVERFLOWEXCEPTION_
#define _SYNKRO_LANG_STACKOVERFLOWEXCEPTION_


#include "config.h"


namespace synkro
{


namespace lang
{


// Thrown if pushing element to the stack causes the stack to exceed its capacity.
class StackOverflowException
{
public:
	// Constructor.
	StackOverflowException() {}
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_STACKOVERFLOWEXCEPTION_
