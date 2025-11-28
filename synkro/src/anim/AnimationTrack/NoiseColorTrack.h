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
// Purpose: Implements color noise animation track.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISECOLORTRACK_
#define _SYNKRO_ANIM_NOISECOLORTRACK_


#include "config.h"
#include "NoiseTrackImpl.h"
#include <anim/INoiseColorTrack.h>
#include <math/Math.h>


namespace synkro
{


namespace anim
{


// Color noise animation track.
class NoiseColorTrack :
	public NoiseTrackImpl<INoiseColorTrack, TYPE_COLOR>
{
public:
	// Constructor.
	NoiseColorTrack( const lang::String& name );

	// IAnimationColorTrack methods.
	void													GetValue( Double time, img::Color& value ) const;
	IKeyframedColorTrack*									AsKeyframed() const;
	IProceduralColorTrack*									AsProcedural() const;
	IExpressionColorTrack*									AsExpression() const;
};


#include "NoiseColorTrack.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISECOLORTRACK_
