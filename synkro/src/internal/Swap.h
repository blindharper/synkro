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
// Purpose: Value swapper.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_SWAP_
#define _SYNKRO_INTERNAL_SWAP_


// Helper function for swapping two pointers.
template <class T> SYNKRO_INLINE static void Swap( const T* first, const T* second )
{
	const T* _tmp = first;
	first = second;
	second = _tmp;
}

// Helper function for swapping two values.
template <class T> SYNKRO_INLINE static void Swap( T& first, T& second )
{
	T _tmp = first;
	first = second;
	second = _tmp;
}


#endif // _SYNKRO_INTERNAL_SWAP_
