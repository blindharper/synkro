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
// Purpose: Implements boolean noise animation track.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISEBOOLTRACK_
#define _SYNKRO_ANIM_NOISEBOOLTRACK_


#include "config.h"
#include "NoiseTrackImpl.h"
#include <anim/INoiseBoolTrack.h>
#include <math/Math.h>


namespace synkro
{


namespace anim
{


// Boolean noise animation track.
class NoiseBoolTrack :
	public NoiseTrackImpl<INoiseBoolTrack, TYPE_BOOL>
{
public:
	// Constructor.
	NoiseBoolTrack( const lang::String& name );

	// IAnimationBoolTrack methods.
	void													GetValue( Double time, Bool& value ) const;
	IKeyframedBoolTrack*									AsKeyframed() const;
	IProceduralBoolTrack*									AsProcedural() const;
	IExpressionBoolTrack*									AsExpression() const;
};


#include "NoiseBoolTrack.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISEBOOLTRACK_
