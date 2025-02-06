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
// Purpose: Defines COM framework initializer.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_COMINITIALIZER_
#define _SYNKRO_INTERNAL_COMINITIALIZER_


#include "config.h"
#include <objbase.h>


// Performs COM framework initialization.
class ComInitializer
{
public:
	// Constructor & destructor.
	ComInitializer();
	~ComInitializer();

private:
	ComInitializer( const ComInitializer& );
	ComInitializer& operator=( const ComInitializer& );
};


#include "ComInitializer.inl"


#endif // _SYNKRO_INTERNAL_COMINITIALIZER_
