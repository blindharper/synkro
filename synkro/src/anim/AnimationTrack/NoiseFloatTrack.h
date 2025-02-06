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
#include "ProceduralTrackImpl.h"
#include <anim/INoiseFloatTrack.h>


namespace synkro
{


namespace anim
{


// Scalar noise animation track.
class NoiseFloatTrack :
	public ProceduralTrackImpl<INoiseFloatTrack, TYPE_FLOAT>
{
public:
	// Constructor.
	NoiseFloatTrack( const lang::String& name );

	// IFloatTrack methods.
	void													GetValue( Double time, Float& value ) const;

	// IAnimationFloatTrack methods.
	IKeyframedFloatTrack*									AsKeyframed() const;
	IProceduralFloatTrack*									AsProcedural() const;
	IExpressionFloatTrack*									AsExpression() const;

	// IProceduralFloatTrack methods.
	INoiseFloatTrack*										AsNoise() const;
	IWaveFloatTrack*										AsWave() const;

	// INoiseFloatTrack methods.
	void													SetSeed( UInt seed );
	UInt													GetSeed() const;

private:
	UInt													_seed;

	Float													GetNoise( UInt x ) const;
};


#include "NoiseFloatTrack.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISEFLOATTRACK_
