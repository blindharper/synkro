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
#include "config.h"
#include "SkeletonAnimationController.h"
#include "BaseSkeleton.h"
#include "BoneProperty.h"
#include <scene/IBone.h>
#include <core/CallStack.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::gfx;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


SkeletonAnimationController::SkeletonAnimationController( ISkeleton* skeleton, IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	PlaybackControllerImpl<ISkeletonAnimationController>( animationSystem, (animations != nullptr) ? animations->GetAnimation(0) : skeleton->GetAnimationSet(0)->GetAnimation(0), listener ),
	_bones( A(BoneDesc), skeleton->GetBoneCount() ),
	_weights( A(WeightInfo) ),
	_skeleton( skeleton )
{
	SynkroCall( "SkeletonAnimationController.SkeletonAnimationController", String::Empty );

	// Activate default animation set.
	IAnimationSet* set = (animations != nullptr) ? animations : _skeleton->GetAnimationSet( 0 );
	SetBonesTracks( set );
}

void SkeletonAnimationController::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<ISkeletonAnimationController>::Update( delta );

	/*// Apply animation set weights.
	UInt weightsToDelete = 0;
	for ( UInt i = 0; i < _weights.Size(); ++i )
	{
		const WeightInfo& info = _weights[i];
		Float weight = 0.0;
		if ( _time >= info.ToTime )
		{
			++weightsToDelete;
			weight = info.ToWeight;
		}
		else
		{
			const Double s = (_time - info.FromTime)/(info.ToTime - info.FromTime);
			weight = Lerp( info.FromWeight, info.ToWeight, s );
		}
		_animationSet->SetWeight( info.Index, weight );
	}
	if ( weightsToDelete == _weights.Size() )
	{
		_weights.Clear();
	}*/

	// Update bone transformations.
	Matrix4x4 transform;
	for ( UInt i = 0; i < _bones.Size(); ++i )
	{
		const BoneDesc& bone = _bones[i];
		if ( bone.TrackTransform != nullptr )
		{
			bone.TrackTransform->GetValue( _time, transform );
		}
		else
		{
			Matrix4x4 position;
			if ( bone.TrackPosition != nullptr )
			{
				Vector3 value;
				bone.TrackPosition->GetValue( _time, value );
				position.SetTranslation( value );
			}

			Matrix4x4 rotation;
			if ( bone.TrackOrientation != nullptr )
			{
				Quaternion value;
				bone.TrackOrientation->GetValue( _time, value );
				rotation.SetOrientation( value );
			}
			
			Matrix4x4 scale;
			if ( bone.TrackScale != nullptr )
			{
				Vector3 value;
				bone.TrackScale->GetValue( _time, value );
				scale.SetScale( value );
			}

			transform = position * rotation * scale;
		}
		_skeleton->GetBone( bone.Index )->SetTransform( transform );
	}
}

void SkeletonAnimationController::SetAnimationSet( UInt index )
{
	IAnimationSet* set = _skeleton->GetAnimationSet( index );
	SetBonesTracks( set );
	Reset();
	_animation = set->GetAnimation( 0 );
}

void SkeletonAnimationController::SetAnimationSet( const String& name )
{
	IAnimationSet* set = _skeleton->GetAnimationSet( name );
	if ( set == nullptr )
		throw BadArgumentException( String::Format(L"Animation set '{0,q}' not found", name), L"name", name );

	SetBonesTracks( set );
	Reset();
	_animation = set->GetAnimation( 0 );
}

void SkeletonAnimationController::SetAnimationSetWeight( const String& name, Float weight, Double delta )
{
	// NB:
	/*if ( _animationSet!=nullptr )
	{
		for ( UInt i = 0; i < _skeleton->GetAnimationSetCount(); ++i )
		{
			if ( _skeleton->GetAnimationSet(i)->GetName() == name )
			{
				for ( UInt j = 0; j < _weights.Size(); ++j )
				{
					if ( _weights[j].Index == i )
					{
						_weights[j].ToWeight = weight;
						_weights[j].FromTime = _time;
						_weights[j].ToTime = _time+delta;
						return;
					}
				}
				Float fromWeight = _animationSet->GetWeight( i );
				_weights.Add( WeightInfo(i, fromWeight, weight, _time, _time+delta) );
			}
		}
	}*/
}

Float SkeletonAnimationController::GetAnimationSetWeight( const String& name ) const
{
	// NB:
	/*if ( _animationSet!=nullptr )
	{
		for ( UInt i = 0; i < _skeleton->GetAnimationSetCount(); ++i )
		{
			if ( _skeleton->GetAnimationSet(i)->GetName() == name )
				return _animationSet->GetWeight( i );
		}
	}*/
	return 0.0f;
}

void SkeletonAnimationController::SetBonesTracks( IAnimationSet* set )
{
	IAnimationTrack* track = nullptr;
	_bones.Clear();
	for ( UInt i = 0; i < _skeleton->GetBoneCount(); ++i )
	{
		IAnimation* animation = set->GetAnimation( _skeleton->GetBone(i)->GetName() );
		if ( animation != nullptr )
		{
			BoneDesc bone( i );
			track = animation->GetTrack( BoneProperty::Transform.ToString() );
			bone.TrackTransform = (track != nullptr) ? track->AsMatrix4x4()->AsKeyframed() : nullptr;
			if ( bone.TrackTransform == nullptr )
			{
				track = animation->GetTrack( BoneProperty::Position.ToString() );
				bone.TrackPosition = (track != nullptr) ? track->AsVector3()->AsKeyframed() : nullptr;

				track = animation->GetTrack( BoneProperty::Orientation.ToString() );
				bone.TrackOrientation = (track != nullptr) ? track->AsQuaternion()->AsKeyframed() : nullptr;

				track = animation->GetTrack( BoneProperty::Scale.ToString() );
				bone.TrackScale = (track != nullptr) ? track->AsVector3()->AsKeyframed() : nullptr;
			}
			_bones.Add( bone );
		}
	}
}


} // scene


} // synkro
