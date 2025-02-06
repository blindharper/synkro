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
// Purpose: Memory copy routine.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_COPY_
#define _SYNKRO_INTERNAL_COPY_


#include <memory.h>


// Helper function for copying memory.
template <class T> SYNKRO_INLINE static void Copy( T* dst, const T* src, synkro::UInt count )
{
	memcpy( dst, src, count*sizeof(T) );
}


#endif // _SYNKRO_INTERNAL_COPY_
