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
// Purpose: Implements color gradient noise animation track.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISECOLORGRADIENTTRACK_
#define _SYNKRO_ANIM_NOISECOLORGRADIENTTRACK_


#include "config.h"
#include "NoiseTrackImpl.h"
#include <anim/INoiseColorGradientTrack.h>
#include <math/Math.h>


namespace synkro
{


namespace anim
{


// Color gradient noise animation track.
class NoiseColorGradientTrack :
	public NoiseTrackImpl<INoiseColorGradientTrack, TYPE_COLOR_GRADIENT>
{
public:
	// Constructor.
	NoiseColorGradientTrack( const lang::String& name );

	// IAnimationColorGradientTrack methods.
	void													GetValue( Double time, img::ColorGradient& value ) const;
	IKeyframedColorGradientTrack*							AsKeyframed() const;
	IProceduralColorGradientTrack*							AsProcedural() const;
	IExpressionColorGradientTrack*							AsExpression() const;

	// INoiseColorGradientTrack methods.
	void													SetGradientType( const lang::GradientType& type );
	lang::GradientType										GetGradientType() const;

private:
	lang::GradientType										_gradientType;
};


#include "NoiseColorGradientTrack.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISECOLORGRADIENTTRACK_
