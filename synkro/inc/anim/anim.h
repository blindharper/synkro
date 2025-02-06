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
// Purpose: 'anim' namespace includes.
//==============================================================================
#ifndef _SYNKRO_ANIM_
#define _SYNKRO_ANIM_


#include <anim/IAnimation.h>
#include <anim/IAnimationSet.h>
#include <anim/IAnimationCodec.h>
#include <anim/IAnimationCodecFactory.h>
#include <anim/IPlaybackAnimationController.h>
#include <anim/IRecordAnimationController.h>
#include <anim/IAnimationSystem.h>
#include <anim/IAnimationTrackFactory.h>
#include <anim/IExpressionScript.h>
#include <anim/IExpressionBoolTrack.h>
#include <anim/IExpressionColorGradientTrack.h>
#include <anim/IExpressionColorTrack.h>
#include <anim/IExpressionFloatTrack.h>
#include <anim/IExpressionFloatRectTrack.h>
#include <anim/IExpressionIntTrack.h>
#include <anim/IExpressionMatrix4x4Track.h>
#include <anim/IExpressionPointTrack.h>
#include <anim/IExpressionQuaternionTrack.h>
#include <anim/IExpressionRangeTrack.h>
#include <anim/IExpressionRectTrack.h>
#include <anim/IExpressionSizeTrack.h>
#include <anim/IExpressionVector3Track.h>
#include <anim/IKeyframedBoolTrack.h>
#include <anim/IKeyframedColorTrack.h>
#include <anim/IKeyframedColorGradientTrack.h>
#include <anim/IKeyframedIntTrack.h>
#include <anim/IKeyframedFloatTrack.h>
#include <anim/IKeyframedFloatRectTrack.h>
#include <anim/IKeyframedMatrix4x4Track.h>
#include <anim/IKeyframedQuaternionTrack.h>
#include <anim/IKeyframedPointTrack.h>
#include <anim/IKeyframedSizeTrack.h>
#include <anim/IKeyframedRangeTrack.h>
#include <anim/IKeyframedRectTrack.h>
#include <anim/IKeyframedVector3Track.h>
#include <anim/IProceduralColorTrack.h>
#include <anim/IProceduralFloatTrack.h>
#include <anim/IProceduralVector3Track.h>
#include <anim/INoiseFloatTrack.h>
#include <anim/IWaveFloatTrack.h>
#include <anim/AnimationTrack.h>
#include <anim/AnimationCodec.h>
#include <anim/AnimationListener.h>
#include <anim/ExpressionException.h>


#define PtrAnimation P(synkro::anim::IAnimation)
#define PtrAnimationSet P(synkro::anim::IAnimationSet)
#define PtrExpressionScript P(synkro::anim::IExpressionScript)
#define PtrKeyframedBoolTrack P(synkro::anim::IKeyframedBoolTrack)
#define PtrKeyframedColorTrack P(synkro::anim::IKeyframedColorTrack)
#define PtrKeyframedColorGradientTrack P(synkro::anim::IKeyframedColorGradientTrack)
#define PtrKeyframedIntTrack P(synkro::anim::IKeyframedIntTrack)
#define PtrKeyframedFloatTrack P(synkro::anim::IKeyframedFloatTrack)
#define PtrKeyframedFloatRectTrack P(synkro::anim::IKeyframedFloatRectTrack)
#define PtrKeyframedMatrix4x4Track P(synkro::anim::IKeyframedMatrix4x4Track)
#define PtrKeyframedQuaternionTrack P(synkro::anim::IKeyframedQuaternionTrack)
#define PtrKeyframedPointTrack P(synkro::anim::IKeyframedPointTrack)
#define PtrKeyframedSizeTrack P(synkro::anim::IKeyframedSizeTrack)
#define PtrKeyframedRangeTrack P(synkro::anim::IKeyframedRangeTrack)
#define PtrKeyframedRectTrack P(synkro::anim::IKeyframedRectTrack)
#define PtrKeyframedVector3Track P(synkro::anim::IKeyframedVector3Track)
#define PtrWaveFloatTrack P(synkro::anim::IWaveFloatTrack)


namespace synkro
{


/**
 * The 'anim' namespace contains interfaces used
 * to animate virtually any property of the objects created by user.
 */
namespace anim
{
} // anim


} // synkro


#endif // _SYNKRO_ANIM_
