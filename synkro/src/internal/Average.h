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
// Purpose: Average value calculator.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_AVERAGE_
#define _SYNKRO_INTERNAL_AVERAGE_


#include "config.h"


// Average value calculator.
template <class T> SYNKRO_INLINE static T Average( synkro::UInt count, T* array, synkro::Float* weights = null )
{
	T sum = T();
	synkro::Float weight = (count > 1) ? 1.0f/(synkro::Float)count : 1.0f;
	for ( synkro::UInt i = 0; i < count; ++i )
	{
		if ( weights != nullptr )
		{
			weight = weights[i];
		}
		sum += array[i]*weight;
	}
	return sum;
}


#endif // _SYNKRO_INTERNAL_AVERAGE_
