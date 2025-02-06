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
// Purpose: Animation controller for skeleton.
//==============================================================================
#ifndef _SYNKRO_SCENE_SKELETONANIMATIONCONTROLLER_
#define _SYNKRO_SCENE_SKELETONANIMATIONCONTROLLER_


#include "config.h"
#include <anim/PlaybackControllerImpl.h>
#include <scene/ISkeletonAnimationController.h>
#include <scene/ISkeleton.h>
#include <anim/IAnimationSet.h>
#include <anim/IAnimation.h>
#include <anim/IKeyframedVector3Track.h>
#include <anim/IKeyframedMatrix4x4Track.h>
#include <anim/IKeyframedQuaternionTrack.h>
#include <lang/Vector.h>


namespace synkro
{


namespace scene
{


// Animation controller for skeleton.
class SkeletonAnimationController :
	public anim::PlaybackControllerImpl<ISkeletonAnimationController>
{
public:
	// Constructor.
	SkeletonAnimationController( ISkeleton* skeleton, anim::IAnimationSystem* animationSystem, anim::IAnimationSet* animations, anim::AnimationListener* listener );

	// IController methods.
	void													Update( Double delta );

	// ISkeletonAnimationController methods.
	void													SetAnimationSet( UInt index );
	void													SetAnimationSet( const lang::String& name );
	void													SetAnimationSetWeight( const lang::String& name, Float weight, Double delta );
	Float													GetAnimationSetWeight( const lang::String& name ) const;

private:
	struct WeightInfo
	{
		WeightInfo( UInt index, Float fromWeight, Float toWeight, Double fromTime, Double toTime ) :
			Index( 0 ),
			FromWeight( 0.0f ),
			ToWeight( 0.0f ),
			FromTime( 0.0 ),
			ToTime( 0.0 )
		{
		}
		
		WeightInfo() :
			Index( 0 ),
			FromWeight( 0.0f ),
			ToWeight( 0.0f ),
			FromTime( 0.0 ),
			ToTime( 0.0 )
		{
		}

		UInt	Index;
		Float	FromWeight;
		Float	ToWeight;
		Double	FromTime;
		Double	ToTime;
	};

	struct BoneDesc
	{
		BoneDesc( UInt index ) :
			TrackTransform( nullptr ),
			TrackPosition( nullptr ),
			TrackOrientation( nullptr ),
			TrackScale( nullptr ),
			Index( index )
		{
		}

		BoneDesc() :
			TrackTransform( nullptr ),
			TrackPosition( nullptr ),
			TrackOrientation( nullptr ),
			TrackScale( nullptr ),
			Index( none )
		{
		}

		anim::IKeyframedMatrix4x4Track*		TrackTransform;
		anim::IKeyframedVector3Track*		TrackPosition;
		anim::IKeyframedQuaternionTrack*	TrackOrientation;
		anim::IKeyframedVector3Track*		TrackScale;
		UInt								Index;
	};

	lang::Vector<BoneDesc>									_bones;
	lang::Vector<WeightInfo>								_weights;
	P(anim::IAnimationSet)									_animationSet;
	ISkeleton*												_skeleton;

	void													SetBonesTracks( anim::IAnimationSet* set );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_SKELETONANIMATIONCONTROLLER_
