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
// Purpose: Defines object equality criteria.
//==============================================================================
#ifndef _SYNKRO_INTERNAL_EQUAL_
#define _SYNKRO_INTERNAL_EQUAL_


#include "config.h"


// Predicate for testing objects for equality. Uses operator==. 
template <class T>
class Equal
{
public:
	SYNKRO_INLINE synkro::Bool operator()( const T& a, const T& b ) const
	{
		return a == b;
	}
};

// Predicate for testing objects for equality. Comparison is case-insensitive.
template <class T>
class EqualCI
{
public:
	SYNKRO_INLINE synkro::Bool operator()( const T& a, const T& b ) const
	{
		return a.EqualsTo( b, true );
	}
};


#endif // _SYNKRO_INTERNAL_EQUAL_
