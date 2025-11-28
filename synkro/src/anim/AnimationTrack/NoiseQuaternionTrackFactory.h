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
// Purpose: Quaternion noise animation track factory.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISEQUATERNIONTRACKFACTORY_
#define _SYNKRO_ANIM_NOISEQUATERNIONTRACKFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <anim/IAnimationTrackFactory.h>
#include <anim/AnimationTrack.h>
#include "NoiseQuaternionTrack.h"


namespace synkro
{


namespace anim
{


// Quaternion noise animation track factory.
SYNKRO_FACTORY_BEGIN( NoiseQuaternionTrackFactory, IAnimationTrackFactory, AnimationTrack, AnimationTrack::QuaternionNoise )
	IAnimationTrack*	Create( const lang::String& name ) { return new NoiseQuaternionTrack( name ); }
	AnimationDataType	GetType() const { return AnimationDataType::Quaternion; }
SYNKRO_FACTORY_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISEQUATERNIONTRACKFACTORY_
