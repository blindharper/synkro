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
// Purpose: TCB spline.
//==============================================================================
SYNKRO_INLINE Float TcbSpline::Hermit0( Float t ) const
{
	return 2.0f*t*t*t - 3.0f*t*t + 1.0f;
}

SYNKRO_INLINE Float TcbSpline::Hermit1( Float t ) const
{
	return -2.0f*t*t*t + 3.0f*t*t;
}

SYNKRO_INLINE Float TcbSpline::Hermit2( Float t ) const
{
	return t*t*t - 2.0f*t*t + t;
}

SYNKRO_INLINE Float TcbSpline::Hermit3( Float t ) const
{
	return t*t*t - t*t;
}
