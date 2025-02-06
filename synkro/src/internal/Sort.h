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
// Purpose: Array sort routine.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_SORT_
#define _SYNKRO_INTERNAL_SORT_


#include "config.h"
#include <internal/Swap.h>


// In-place quick sort.
template <class T> SYNKRO_INLINE static synkro::UInt SortPartition( T* array, synkro::UInt left, synkro::UInt right, synkro::UInt pivot )
{
	T pivotValue = array[pivot];
	
	// Move pivot to the end.
	Swap( array[pivot], array[right] );

	// Compare all elements to pivot.
	synkro::UInt index = left;
	for ( synkro::UInt i = left; i < right; ++i )
	{
		if ( !(pivotValue < array[i]) )
		{
			Swap( array[i], array[index] );
			++index;
		}
	}

	// Move pivot to its final position.
	Swap( array[index], array[right] );

	return index;
}

// In-place quick sort.
template <class T> SYNKRO_INLINE static void QuickSort( T* array, synkro::UInt left, synkro::UInt right )
{
	// Choose pivot point between left and right.
	synkro::UInt pivot = left + (right-left)/2;

	// Get the lists of smaller and bigger elements and final position of pivot.
	pivot = SortPartition( array, left, right, pivot );

	// Sort elements smaller than pivot.
	if ( left+1 < pivot )
	{
		QuickSort( array, left, pivot-1 );
	}

	// Sort elements at least as big as pivot.
	if ( pivot+1 < right )
	{
		QuickSort( array, pivot+1, right );
	}
}

// Array sort routine.
template <class T> SYNKRO_INLINE static void Sort( T* array, synkro::UInt count )
{
	if ( count > 1 )
	{
		QuickSort( array, 0, count-1 );
	}
}


#endif // _SYNKRO_INTERNAL_SORT_
