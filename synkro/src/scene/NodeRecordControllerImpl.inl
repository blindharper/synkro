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
// Purpose: Generic node record controller implementation.
//==============================================================================
template <class T> 
SYNKRO_INLINE NodeRecordControllerImpl<T>::NodeRecordControllerImpl( INode* node, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation ) :
	anim::RecordControllerImpl<T>( animationSystem, animation ),
	_node( node )
{
}

template <class T>
SYNKRO_INLINE NodeRecordControllerImpl<T>::~NodeRecordControllerImpl()
{
}

template <class T>
SYNKRO_INLINE void NodeRecordControllerImpl<T>::Update( Double delta )
{
	// Call base implementation.
	anim::RecordControllerImpl<T>::Update( delta );

	// Save node parameters.
	if ( _trackTransform != nullptr )
	{
		math::Matrix4x4 transform;
		_node->GetTransform( transform );
		_trackTransform->SetKey( _time, transform );
	}
	else
	{
		if ( _trackScale != nullptr )
		{
			math::Vector3 scale;
			_node->GetScale( scale );
			_trackScale->SetKey( _time, scale );
		}

		if ( _trackPosition != nullptr )
		{
			math::Vector3 position;
			_node->GetPosition( position );
			_trackPosition->SetKey( _time, position );
		}

		if ( _trackOrientation != nullptr )
		{
			math::Quaternion orientation;
			_node->GetOrientation( orientation );
			_trackOrientation->SetKey( _time, orientation );
		}
	}
}

template <class T>
SYNKRO_INLINE anim::IKeyframedMatrix4x4Track* NodeRecordControllerImpl<T>::CreateTransformTrack()
{
	return (_trackTransform == nullptr) ? _trackTransform = _animation->CreateMatrix4x4Track( NodeProperty::Transform.ToString() ) : _trackTransform;
}

template <class T>
SYNKRO_INLINE anim::IKeyframedVector3Track* NodeRecordControllerImpl<T>::CreatePositionTrack()
{
	return (_trackPosition == nullptr) ? _trackPosition = _animation->CreateVector3Track( NodeProperty::Position.ToString() ) : _trackPosition;
}

template <class T>
SYNKRO_INLINE anim::IKeyframedQuaternionTrack* NodeRecordControllerImpl<T>::CreateOrientationTrack()
{
	return (_trackOrientation == nullptr) ? _trackOrientation = _animation->CreateQuaternionTrack( NodeProperty::Orientation.ToString() ) : _trackOrientation;
}

template <class T>
SYNKRO_INLINE anim::IKeyframedVector3Track* NodeRecordControllerImpl<T>::CreateScaleTrack()
{
	return (_trackScale == nullptr) ? _trackScale = _animation->CreateVector3Track( NodeProperty::Scale.ToString() ) : _trackScale;
}
