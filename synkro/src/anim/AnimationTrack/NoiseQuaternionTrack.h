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
// Purpose: Implements quaternion noise animation track.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISEQUATERNIONTRACK_
#define _SYNKRO_ANIM_NOISEQUATERNIONTRACK_


#include "config.h"
#include "NoiseTrackImpl.h"
#include <anim/INoiseQuaternionTrack.h>
#include <math/Math.h>


namespace synkro
{


namespace anim
{


// Quaternion noise animation track.
class NoiseQuaternionTrack :
	public NoiseTrackImpl<INoiseQuaternionTrack, TYPE_QUATERNION>
{
public:
	// Constructor.
	NoiseQuaternionTrack( const lang::String& name );

	// IAnimationQuaternionTrack methods.
	void													GetValue( Double time, math::Quaternion& value ) const;
	IKeyframedQuaternionTrack*								AsKeyframed() const;
	IProceduralQuaternionTrack*								AsProcedural() const;
	IExpressionQuaternionTrack*								AsExpression() const;

	// INoiseQuaternionTrack methods.
	void													SetMagnitude( Float magnitude );
	Float													GetMagnitude() const;

private:
	Float													_magnitude;
};


#include "NoiseQuaternionTrack.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISEQUATERNIONTRACK_
