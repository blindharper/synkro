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
// Purpose: Color gradient noise animation track factory.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISECOLORGRADIENTTRACKFACTORY_
#define _SYNKRO_ANIM_NOISECOLORGRADIENTTRACKFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <anim/IAnimationTrackFactory.h>
#include <anim/AnimationTrack.h>
#include "NoiseColorGradientTrack.h"


namespace synkro
{


namespace anim
{


// Color gradient noise animation track factory.
SYNKRO_FACTORY_BEGIN( NoiseColorGradientTrackFactory, IAnimationTrackFactory, AnimationTrack, AnimationTrack::ColorGradientNoise )
	IAnimationTrack*	Create( const lang::String& name ) { return new NoiseColorGradientTrack( name ); }
	AnimationDataType	GetType() const { return AnimationDataType::ColorGradient; }
SYNKRO_FACTORY_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISECOLORGRADIENTTRACKFACTORY_
