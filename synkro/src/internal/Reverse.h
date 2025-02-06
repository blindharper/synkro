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
// Purpose: Array reverter.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_REVERSE_
#define _SYNKRO_INTERNAL_REVERSE_


#include "config.h"


// Helper function for reverting array elements.
template <class T> SYNKRO_INLINE static void Reverse( T* arr, synkro::UInt count )
{
	T e;
	synkro::UInt cnt = count/2;
	for ( synkro::UInt i = 0; i < cnt; ++i )
	{
		e = arr[i];
		arr[i] = arr[count-i-1];
		arr[count-i-1] = e;
	}
}


#endif // _SYNKRO_INTERNAL_REVERSE_
