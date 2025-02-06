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
// Purpose: Implements generic animation codec.
//==============================================================================
#ifndef _SYNKRO_ANIM_ANIMATIONCODECIMPL_
#define _SYNKRO_ANIM_ANIMATIONCODECIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IContext.h>
#include <anim/IAnimation.h>
#include <anim/IAnimationSet.h>
#include <anim/IAnimationSystem.h>
#include <anim/IKeyframedBoolTrack.h>
#include <anim/IKeyframedColorGradientTrack.h>
#include <anim/IKeyframedColorTrack.h>
#include <anim/IKeyframedFloatRectTrack.h>
#include <anim/IKeyframedFloatTrack.h>
#include <anim/IKeyframedIntTrack.h>
#include <anim/IKeyframedMatrix4x4Track.h>
#include <anim/IKeyframedPointTrack.h>
#include <anim/IKeyframedQuaternionTrack.h>
#include <anim/IKeyframedRectTrack.h>
#include <anim/IKeyframedSizeTrack.h>
#include <anim/IKeyframedRangeTrack.h>
#include <anim/IKeyframedVector3Track.h>


namespace synkro
{


namespace anim
{


// Generic animation codec implementation.
template <class T>
class AnimationCodecImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	AnimationCodecImpl( core::IContext* context );
	virtual ~AnimationCodecImpl();

	// IAnimationCodec methods.
	virtual IAnimationSet*									Load( io::IStream* stream );
	virtual void											Save( const IAnimationSet* animation, io::IStream* stream );

protected:
	core::IContext*											_context;
};


#include "AnimationCodecImpl.inl"


} // anim


} // synkro


#endif // _SYNKRO_ANIM_ANIMATIONCODECIMPL_
