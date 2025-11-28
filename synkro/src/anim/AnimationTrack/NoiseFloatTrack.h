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
// Purpose: Implements scalar noise animation track.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISEFLOATTRACK_
#define _SYNKRO_ANIM_NOISEFLOATTRACK_


#include "config.h"
#include "NoiseTrackImpl.h"
#include <anim/INoiseFloatTrack.h>


namespace synkro
{


namespace anim
{


// Scalar noise animation track.
class NoiseFloatTrack :
	public NoiseTrackImpl<INoiseFloatTrack, TYPE_FLOAT>
{
public:
	// Constructor.
	NoiseFloatTrack( const lang::String& name );

	// IAnimationFloatTrack methods.
	void													GetValue( Double time, Float& value ) const;
	IKeyframedFloatTrack*									AsKeyframed() const;
	IProceduralFloatTrack*									AsProcedural() const;
	IExpressionFloatTrack*									AsExpression() const;

	// IProceduralFloatTrack methods.
	IWaveFloatTrack*										AsWave() const;

	// INoiseFloatTrack methods.
	void													SetMagnitude( Float magnitude );
	void													SetShift( Float shift );
	Float													GetMagnitude() const;
	Float													GetShift() const;

private:
	Float													_magnitude;
	Float													_shift;
};


#include "NoiseFloatTrack.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISEFLOATTRACK_
