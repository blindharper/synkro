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
// Purpose: 3-component vector noise animation track factory.
//==============================================================================
#ifndef _SYNKRO_ANIM_NOISEVECTOR3TRACKFACTORY_
#define _SYNKRO_ANIM_NOISEVECTOR3TRACKFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <anim/IAnimationTrackFactory.h>
#include <anim/AnimationTrack.h>
#include "NoiseVector3Track.h"


namespace synkro
{


namespace anim
{


// 3-component vector noise animation track factory.
SYNKRO_FACTORY_BEGIN( NoiseVector3TrackFactory, IAnimationTrackFactory, AnimationTrack, AnimationTrack::Vector3Noise )
	IAnimationTrack*	Create( const lang::String& name ) { return new NoiseVector3Track( name ); }
	AnimationDataType	GetType() const { return AnimationDataType::Vector3; }
SYNKRO_FACTORY_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_NOISEVECTOR3TRACKFACTORY_
