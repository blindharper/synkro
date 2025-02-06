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
// Purpose: Implements scalar wave animation track factory.
//==============================================================================
#ifndef _SYNKRO_ANIM_WAVEFLOATTRACKFACTORY_
#define _SYNKRO_ANIM_WAVEFLOATTRACKFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <anim/IAnimationTrackFactory.h>
#include <anim/AnimationTrack.h>
#include "WaveFloatTrack.h"


namespace synkro
{


namespace anim
{


// Scalar wave animation track factory.
SYNKRO_FACTORY_BEGIN( WaveFloatTrackFactory, IAnimationTrackFactory, AnimationTrack, AnimationTrack::FloatWave )
	IAnimationTrack*	Create( const lang::String& name ) { return new WaveFloatTrack( name ); }
	AnimationDataType	GetType() const { return AnimationDataType::Float; }
SYNKRO_FACTORY_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_WAVEFLOATTRACKFACTORY_
