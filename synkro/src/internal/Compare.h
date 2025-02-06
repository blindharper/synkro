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
// Purpose: Memory comparison routine.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_COMPARE_
#define _SYNKRO_INTERNAL_COMPARE_


#include <memory.h>


// Helper function for comparing memory.
template <class T> SYNKRO_INLINE static synkro::Bool Compare( T* a, const T* b, synkro::UInt count )
{
	return memcmp( a, b, count*sizeof(T) ) == 0;
}


#endif // _SYNKRO_INTERNAL_COMPARE_
