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
// Purpose: Defines stack underflow exception.
//==============================================================================
#ifndef _SYNKRO_LANG_STACKUNDERFLOWEXCEPTION_
#define _SYNKRO_LANG_STACKUNDERFLOWEXCEPTION_


#include "config.h"


namespace synkro
{


namespace lang
{


// Thrown if trying to pop element from the empty stack.
class StackUnderflowException
{
public:
	// Constructor.
	StackUnderflowException() {}
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_STACKUNDERFLOWEXCEPTION_
