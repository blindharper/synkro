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
// Purpose: Memory initializer.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_ZERO_
#define _SYNKRO_INTERNAL_ZERO_


#include <memory.h>


// Helper function for memory initialization.
template <class T> SYNKRO_INLINE static void Zero( T* v, size_t len = sizeof(T) )
{
	memset( v, 0, len );
}


#endif // _SYNKRO_INTERNAL_ZERO_
