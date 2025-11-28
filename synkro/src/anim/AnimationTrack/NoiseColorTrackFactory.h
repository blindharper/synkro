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
// Purpose: Color noise animation track factory.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISECOLORTRACKFACTORY_
#define _SYNKRO_ANIM_NOISECOLORTRACKFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <anim/IAnimationTrackFactory.h>
#include <anim/AnimationTrack.h>
#include "NoiseColorTrack.h"


namespace synkro
{


namespace anim
{


// Color noise animation track factory.
SYNKRO_FACTORY_BEGIN( NoiseColorTrackFactory, IAnimationTrackFactory, AnimationTrack, AnimationTrack::ColorNoise )
	IAnimationTrack*	Create( const lang::String& name ) { return new NoiseColorTrack( name ); }
	AnimationDataType	GetType() const { return AnimationDataType::Color; }
SYNKRO_FACTORY_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISECOLORTRACKFACTORY_
