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
// Purpose: Boolean noise animation track factory.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISEBOOLTRACKFACTORY_
#define _SYNKRO_ANIM_NOISEBOOLTRACKFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <anim/IAnimationTrackFactory.h>
#include <anim/AnimationTrack.h>
#include "NoiseBoolTrack.h"


namespace synkro
{


namespace anim
{


// Boolean noise animation track factory.
SYNKRO_FACTORY_BEGIN( NoiseBoolTrackFactory, IAnimationTrackFactory, AnimationTrack, AnimationTrack::BoolNoise )
	IAnimationTrack*	Create( const lang::String& name ) { return new NoiseBoolTrack( name ); }
	AnimationDataType	GetType() const { return AnimationDataType::Bool; }
SYNKRO_FACTORY_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISEBOOLTRACKFACTORY_
