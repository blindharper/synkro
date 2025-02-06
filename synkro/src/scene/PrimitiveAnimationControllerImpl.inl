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
// Purpose: Generic primitive animation controller implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE PrimitiveAnimationControllerImpl<T>::PrimitiveAnimationControllerImpl( IPrimitive* primitive, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener ) :
	PlaybackControllerImpl<T>( animationSystem, animation, listener ),
	_primitive( primitive )
{
}

template <class T>
SYNKRO_INLINE PrimitiveAnimationControllerImpl<T>::~PrimitiveAnimationControllerImpl()
{
}

template <class T>
SYNKRO_INLINE void PrimitiveAnimationControllerImpl<T>::Update( Double delta )
{
	// Call base implementation.
	anim::PlaybackControllerImpl<T>::Update( delta );

	// Update primmitive.
	math::Matrix4x4 transform;
	if ( _trackTransform != nullptr )
	{
		_trackTransform->GetValue( _time, transform );
		_primitive->SetTransform( transform );
	}
	else
	{
		math::Quaternion orientation;
		if ( _trackOrientation != nullptr )
		{
			_trackOrientation->GetValue( _time, orientation );
			_primitive->GetTransform( transform );
			transform.SetOrientation( orientation );
			_primitive->SetTransform( transform );
		}
		else
		{
			if ( (_trackOrientationYaw != nullptr) || (_trackOrientationPitch != nullptr) || (_trackOrientationRoll != nullptr) )
			{
				Float yaw = 0.0f;
				_trackOrientationYaw->GetValue( _time, yaw );

				Float pitch = 0.0f;
				_trackOrientationPitch->GetValue( _time, pitch );
				
				Float roll = 0.0f;
				_trackOrientationRoll->GetValue( _time, roll );

				_primitive->GetTransform( transform );				

				math::Matrix4x4 transPosition;
				transPosition.SetTranslation( transform.Translation() );

				math::Matrix4x4 transOrientation;
				orientation.SetAngles( yaw, pitch, roll );
				transOrientation.SetOrientation( orientation );

				math::Matrix4x4 transScale;
				transScale.SetScale( transform.Scale() );

				transform = transOrientation * transPosition;
				// TODO: transform = transform * transScale;
				_primitive->SetTransform( transform );
			}
		}
	}

	if ( _trackElementRange != nullptr )
	{
		lang::Range range;
		_trackElementRange->GetValue( _time, range );
		_primitive->SetElementRange( range );
	}
}

template <class T>
SYNKRO_INLINE void PrimitiveAnimationControllerImpl<T>::SetAnimation( anim::IAnimation* animation )
{
	// Call base implementation.
	anim::PlaybackControllerImpl<T>::SetAnimation( animation );

	_trackTransform			= GetTrack( _trackTransform, PrimitiveProperty::Transform );
	_trackOrientation		= GetTrack( _trackOrientation, PrimitiveProperty::Orientation );
	_trackOrientationYaw	= GetTrack( _trackOrientationYaw, PrimitiveProperty::OrientationYaw );
	_trackOrientationPitch	= GetTrack( _trackOrientationPitch, PrimitiveProperty::OrientationPitch );
	_trackOrientationRoll	= GetTrack( _trackOrientationRoll, PrimitiveProperty::OrientationRoll );
	_trackElementRange		= GetTrack( _trackElementRange, PrimitiveProperty::ElementRange );
}

template <class T>
SYNKRO_INLINE anim::IKeyframedMatrix4x4Track* PrimitiveAnimationControllerImpl<T>::CreateTransformTrack()
{
	return (_trackTransform = (_trackTransform == nullptr) ? _animation->CreateMatrix4x4Track(PrimitiveProperty::Transform.ToString()) : _trackTransform)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IExpressionMatrix4x4Track* PrimitiveAnimationControllerImpl<T>::CreateTransformTrack( anim::IExpressionScript* script )
{
	return (_trackTransform = (_trackTransform == nullptr) ? _animation->CreateMatrix4x4Track(PrimitiveProperty::Transform.ToString(), script) : _trackTransform)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionMatrix4x4Track* PrimitiveAnimationControllerImpl<T>::CreateTransformTrack( const lang::String& expression )
{
	return (_trackTransform = (_trackTransform == nullptr) ? _animation->CreateMatrix4x4Track(PrimitiveProperty::Transform.ToString(), expression) : _trackTransform)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedQuaternionTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationTrack()
{
	return (_trackOrientation = (_trackOrientation == nullptr) ? _animation->CreateQuaternionTrack(PrimitiveProperty::Orientation.ToString()) : _trackOrientation)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IExpressionQuaternionTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationTrack( anim::IExpressionScript* script )
{
	return (_trackOrientation = (_trackOrientation == nullptr) ? _animation->CreateQuaternionTrack(PrimitiveProperty::Orientation.ToString(), script) : _trackOrientation)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionQuaternionTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationTrack( const lang::String& expression )
{
	return (_trackOrientation = (_trackOrientation == nullptr) ? _animation->CreateQuaternionTrack(PrimitiveProperty::Orientation.ToString(), expression) : _trackOrientation)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationYawTrack()
{
	return (_trackOrientationYaw = (_trackOrientationYaw == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationYaw.ToString()) : _trackOrientationYaw)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationYawTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationYaw = (_trackOrientationYaw == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationYaw.ToString(), type) : _trackOrientationYaw)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationYawTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationYaw = (_trackOrientationYaw == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationYaw.ToString(), script) : _trackOrientationYaw)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationYawTrack( const lang::String& expression )
{
	return (_trackOrientationYaw = (_trackOrientationYaw == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationYaw.ToString(), expression) : _trackOrientationYaw)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationPitchTrack()
{
	return (_trackOrientationPitch = (_trackOrientationPitch == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationPitch.ToString()) : _trackOrientationPitch)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationPitchTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationPitch = (_trackOrientationPitch == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationPitch.ToString(), type) : _trackOrientationPitch)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationPitchTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationPitch = (_trackOrientationPitch == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationPitch.ToString(), script) : _trackOrientationPitch)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationPitchTrack( const lang::String& expression )
{
	return (_trackOrientationPitch = (_trackOrientationPitch == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationPitch.ToString(), expression) : _trackOrientationPitch)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationRollTrack()
{
	return (_trackOrientationRoll = (_trackOrientationRoll == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationRoll.ToString()) : _trackOrientationRoll)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationRollTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationRoll = (_trackOrientationRoll == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationRoll.ToString(), type) : _trackOrientationRoll)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationRollTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationRoll = (_trackOrientationRoll == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationRoll.ToString(), script) : _trackOrientationRoll)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationRollTrack( const lang::String& expression )
{
	return (_trackOrientationRoll = (_trackOrientationRoll == nullptr) ? _animation->CreateFloatTrack(PrimitiveProperty::OrientationRoll.ToString(), expression) : _trackOrientationRoll)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedRangeTrack* PrimitiveAnimationControllerImpl<T>::CreateElementRangeTrack()
{
	return (_trackElementRange = (_trackElementRange == nullptr) ? _animation->CreateRangeTrack(PrimitiveProperty::ElementRange.ToString()) : _trackElementRange)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE ILineSetAnimationController* PrimitiveAnimationControllerImpl<T>::AsLineSet() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IPointSetAnimationController* PrimitiveAnimationControllerImpl<T>::AsPointSet() const
{
	return nullptr;
}
