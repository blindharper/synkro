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
// Purpose: Value clamper.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_CLAMP_
#define _SYNKRO_INTERNAL_CLAMP_


// Helper function for swapping two values.
template <class T> SYNKRO_INLINE static T Clamp( T value, T min, T max )
{
	if ( value < min )
		return min;

	if ( value > max )
		return max;

	return value;
}


#endif // _SYNKRO_INTERNAL_CLAMP_
