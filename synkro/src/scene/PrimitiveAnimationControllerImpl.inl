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
SYNKRO_INLINE PrimitiveAnimationControllerImpl<T>::PrimitiveAnimationControllerImpl( IPrimitive* primitive, anim::IAnimationSystem* animationSystem, anim::IAnimationSet* animations, anim::AnimationListener* listener ) :
	PlaybackControllerImpl<T>( animationSystem, animations, listener ),
	_primitive( primitive ),
	_trackTransform( nullptr ),
	_trackOrientation( nullptr ),
	_trackOrientationYaw( nullptr ),
	_trackOrientationPitch( nullptr ),
	_trackOrientationRoll( nullptr ),
	_trackElementRange( nullptr )
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
		_trackTransform->GetValue( CurrentTime(), transform );
		_primitive->SetTransform( transform );
	}
	else
	{
		math::Quaternion orientation;
		if ( _trackOrientation != nullptr )
		{
			_trackOrientation->GetValue( CurrentTime(), orientation );
			_primitive->GetTransform( transform );
			transform.SetOrientation( orientation );
			_primitive->SetTransform( transform );
		}
		else
		{
			if ( (_trackOrientationYaw != nullptr) || (_trackOrientationPitch != nullptr) || (_trackOrientationRoll != nullptr) )
			{
				Float yaw = 0.0f;
				_trackOrientationYaw->GetValue( CurrentTime(), yaw );

				Float pitch = 0.0f;
				_trackOrientationPitch->GetValue( CurrentTime(), pitch );
				
				Float roll = 0.0f;
				_trackOrientationRoll->GetValue( CurrentTime(), roll );

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
		_trackElementRange->GetValue( CurrentTime(), range );
		_primitive->SetElementRange( range );
	}
}

template <class T>
SYNKRO_INLINE anim::IKeyframedMatrix4x4Track* PrimitiveAnimationControllerImpl<T>::CreateTransformTrack()
{
	return (_trackTransform = _animations->GetActiveAnimation()->CreateMatrix4x4Track( PrimitiveProperty::Transform.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IExpressionMatrix4x4Track* PrimitiveAnimationControllerImpl<T>::CreateTransformTrack( anim::IExpressionScript* script )
{
	return (_trackTransform = _animations->GetActiveAnimation()->CreateMatrix4x4Track( PrimitiveProperty::Transform.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionMatrix4x4Track* PrimitiveAnimationControllerImpl<T>::CreateTransformTrack( const lang::String& expression )
{
	return (_trackTransform = _animations->GetActiveAnimation()->CreateMatrix4x4Track( PrimitiveProperty::Transform.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedQuaternionTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationTrack()
{
	return (_trackOrientation = _animations->GetActiveAnimation()->CreateQuaternionTrack( PrimitiveProperty::Orientation.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IExpressionQuaternionTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationTrack( anim::IExpressionScript* script )
{
	return (_trackOrientation = _animations->GetActiveAnimation()->CreateQuaternionTrack( PrimitiveProperty::Orientation.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionQuaternionTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationTrack( const lang::String& expression )
{
	return (_trackOrientation = _animations->GetActiveAnimation()->CreateQuaternionTrack( PrimitiveProperty::Orientation.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationYawTrack()
{
	return (_trackOrientationYaw = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationYaw.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationYawTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationYaw = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationYaw.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationYawTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationYaw = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationYaw.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationYawTrack( const lang::String& expression )
{
	return (_trackOrientationYaw = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationYaw.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationPitchTrack()
{
	return (_trackOrientationPitch = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationPitch.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationPitchTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationPitch = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationPitch.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationPitchTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationPitch = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationPitch.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationPitchTrack( const lang::String& expression )
{
	return (_trackOrientationPitch = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationPitch.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationRollTrack()
{
	return (_trackOrientationRoll = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationRoll.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationRollTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationRoll = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationRoll.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationRollTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationRoll = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationRoll.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* PrimitiveAnimationControllerImpl<T>::CreateOrientationRollTrack( const lang::String& expression )
{
	return (_trackOrientationRoll = _animations->GetActiveAnimation()->CreateFloatTrack( PrimitiveProperty::OrientationRoll.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedRangeTrack* PrimitiveAnimationControllerImpl<T>::CreateElementRangeTrack()
{
	return (_trackElementRange = _animations->GetActiveAnimation()->CreateRangeTrack( PrimitiveProperty::ElementRange.ToString()) )->AsKeyframed();
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

template <class T>
SYNKRO_INLINE void PrimitiveAnimationControllerImpl<T>::UpdateTracks()
{
	_trackTransform			= GetTrack( _trackTransform, PrimitiveProperty::Transform );
	_trackOrientation		= GetTrack( _trackOrientation, PrimitiveProperty::Orientation );
	_trackOrientationYaw	= GetTrack( _trackOrientationYaw, PrimitiveProperty::OrientationYaw );
	_trackOrientationPitch	= GetTrack( _trackOrientationPitch, PrimitiveProperty::OrientationPitch );
	_trackOrientationRoll	= GetTrack( _trackOrientationRoll, PrimitiveProperty::OrientationRoll );
	_trackElementRange		= GetTrack( _trackElementRange, PrimitiveProperty::ElementRange );
}
