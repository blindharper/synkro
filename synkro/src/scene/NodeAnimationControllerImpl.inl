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
// Purpose: Animation controller for generic node.
//==============================================================================
template <class T> 
SYNKRO_INLINE NodeAnimationControllerImpl<T>::NodeAnimationControllerImpl( INode* node, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener ) :
	anim::PlaybackControllerImpl<T>( animationSystem, animation, listener ),
	_node( node )
{
}

template <class T>
SYNKRO_INLINE NodeAnimationControllerImpl<T>::~NodeAnimationControllerImpl()
{
}

template <class T>
SYNKRO_INLINE void NodeAnimationControllerImpl<T>::Update( Double delta )
{
	// Call base implementation.
	anim::PlaybackControllerImpl<T>::Update( delta );

	// Update node.
	IParentConstraint* parentConstraint = _node->GetParentConstraint();
	if ( (parentConstraint != nullptr) && parentConstraint->IsEnabled() )
	{
		parentConstraint->Apply();
	}
	else if ( _trackTransform != nullptr )
	{
		math::Matrix4x4 transform;
		_trackTransform->GetValue( _time, transform );
		_node->SetTransform( transform );
	}
	else
	{
		if ( _trackScale != nullptr )
		{
			math::Vector3 scale;
			_trackScale->GetValue( _time, scale );
			_node->SetScale( scale );
		}
		else
		{
			if ( _trackScaleUniform != nullptr )
			{
				Float scale;
				_trackScaleUniform->GetValue( _time, scale );
				_node->SetScale( scale );
			}
			else
			{
				if ( _trackScaleX != nullptr )
				{
					Float scale;
					_trackScaleX->GetValue( _time, scale );
					_node->SetScaleX( scale );
				}

				if ( _trackScaleY != nullptr )
				{
					Float scale;
					_trackScaleY->GetValue( _time, scale );
					_node->SetScaleY( scale );
				}

				if ( _trackScaleZ != nullptr )
				{
					Float scale;
					_trackScaleZ->GetValue( _time, scale );
					_node->SetScaleZ( scale );
				}
			}
		}

		ICurve* path = _node->GetPath();
		if ( (path != nullptr) && (_trackPathPhase != nullptr) )
		{
			Float phase;
			_trackPathPhase->GetValue( _time, phase );
			_node->SetPathPhase( phase );
		}
		else if ( _trackPosition != nullptr )
		{
			math::Vector3 position;
			_trackPosition->GetValue( _time, position );
			_node->SetPosition( position );
		}
		else
		{
			if ( _trackPositionX != nullptr )
			{
				Float pos;
				_trackPositionX->GetValue( _time, pos );
				_node->SetPositionX( pos );
			}

			if ( _trackPositionY != nullptr )
			{
				Float pos;
				_trackPositionY->GetValue( _time, pos );
				_node->SetPositionY( pos );
			}

			if ( _trackPositionZ != nullptr )
			{
				Float pos;
				_trackPositionZ->GetValue( _time, pos );
				_node->SetPositionZ( pos );
			}
		}

		ILookAtConstraint* lookAtConstraint = _node->GetLookAtConstraint();
		if ( (lookAtConstraint != nullptr) && lookAtConstraint->IsEnabled() )
		{
			lookAtConstraint->Apply();
		}
		else if ( _trackOrientation != nullptr )
		{
			math::Quaternion orientation;
			_trackOrientation->GetValue( _time, orientation );
			_node->SetOrientation( orientation );
		}
		else
		{
			if ( _trackOrientationYaw != nullptr )
			{
				Float angle;
				_trackOrientationYaw->GetValue( _time, angle );
				_node->SetOrientationYaw( angle );
			}

			if ( _trackOrientationPitch != nullptr )
			{
				Float angle;
				_trackOrientationPitch->GetValue( _time, angle );
				_node->SetOrientationPitch( angle );
			}

			if ( _trackOrientationRoll != nullptr )
			{
				Float angle;
				_trackOrientationRoll->GetValue( _time, angle );
				_node->SetOrientationRoll( angle );
			}
		}
	}
}

template <class T>
SYNKRO_INLINE void NodeAnimationControllerImpl<T>::SetAnimation( anim::IAnimation* animation )
{
	// Call base implementation.
	anim::PlaybackControllerImpl<T>::SetAnimation( animation );

	_trackTransform			= GetTrack( _trackTransform, NodeProperty::Transform );
	_trackPosition			= GetTrack( _trackPosition, NodeProperty::Position );
	_trackPositionX			= GetTrack( _trackPositionX, NodeProperty::PositionX );
	_trackPositionY			= GetTrack( _trackPositionY, NodeProperty::PositionY );
	_trackPositionZ			= GetTrack( _trackPositionZ, NodeProperty::PositionZ );
	_trackOrientation		= GetTrack( _trackOrientation, NodeProperty::Orientation );
	_trackOrientationYaw	= GetTrack( _trackOrientationYaw, NodeProperty::OrientationYaw );
	_trackOrientationPitch	= GetTrack( _trackOrientationPitch, NodeProperty::OrientationPitch );
	_trackOrientationRoll	= GetTrack( _trackOrientationRoll, NodeProperty::OrientationRoll );
	_trackScale				= GetTrack( _trackScale, NodeProperty::Scale );
	_trackScaleX			= GetTrack( _trackScaleX, NodeProperty::ScaleX );
	_trackScaleY			= GetTrack( _trackScaleY, NodeProperty::ScaleY );
	_trackScaleZ			= GetTrack( _trackScaleZ, NodeProperty::ScaleZ );
	_trackScaleUniform		= GetTrack( _trackScaleUniform, NodeProperty::ScaleUniform );
	_trackPathPhase			= GetTrack( _trackPathPhase, NodeProperty::PathPhase );
}

template <class T>
SYNKRO_INLINE anim::IKeyframedMatrix4x4Track* NodeAnimationControllerImpl<T>::CreateTransformTrack()
{
	return (_trackTransform = (_trackTransform == nullptr) ? _animation->CreateMatrix4x4Track(NodeProperty::Transform.ToString()) : _trackTransform)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IExpressionMatrix4x4Track* NodeAnimationControllerImpl<T>::CreateTransformTrack( anim::IExpressionScript* script )
{
	return (_trackTransform = (_trackTransform == nullptr) ? _animation->CreateMatrix4x4Track(NodeProperty::Transform.ToString(), script) : _trackTransform)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionMatrix4x4Track* NodeAnimationControllerImpl<T>::CreateTransformTrack( const lang::String& expression )
{
	return (_trackTransform = (_trackTransform == nullptr) ? _animation->CreateMatrix4x4Track(NodeProperty::Transform.ToString(), expression) : _trackTransform)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedVector3Track* NodeAnimationControllerImpl<T>::CreatePositionTrack()
{
	return (_trackPosition = (_trackPosition == nullptr) ? _animation->CreateVector3Track(NodeProperty::Position.ToString()) : _trackPosition)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralVector3Track* NodeAnimationControllerImpl<T>::CreatePositionTrack( const anim::AnimationTrack& type )
{
	return (_trackPosition = (_trackPosition == nullptr) ? _animation->CreateVector3Track(NodeProperty::Position.ToString(), type) : _trackPosition)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionVector3Track* NodeAnimationControllerImpl<T>::CreatePositionTrack( anim::IExpressionScript* script )
{
	return (_trackPosition = (_trackPosition == nullptr) ? _animation->CreateVector3Track(NodeProperty::Position.ToString(), script) : _trackPosition)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionVector3Track* NodeAnimationControllerImpl<T>::CreatePositionTrack( const lang::String& expression )
{
	return (_trackPosition = (_trackPosition == nullptr) ? _animation->CreateVector3Track(NodeProperty::Position.ToString(), expression) : _trackPosition)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionXTrack()
{
	return (_trackPositionX = (_trackPositionX == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionX.ToString()) : _trackPositionX)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionXTrack( const anim::AnimationTrack& type )
{
	return (_trackPositionX = (_trackPositionX == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionX.ToString(), type) : _trackPositionX)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionXTrack( anim::IExpressionScript* script )
{
	return (_trackPositionX = (_trackPositionX == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionX.ToString(), script) : _trackPositionX)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionXTrack( const lang::String& expression )
{
	return (_trackPositionX = (_trackPositionX == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionX.ToString(), expression) : _trackPositionX)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionYTrack()
{	
	return (_trackPositionY = (_trackPositionY == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionY.ToString()) : _trackPositionY)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionYTrack( const anim::AnimationTrack& type )
{
	return (_trackPositionY = (_trackPositionY == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionY.ToString(), type) : _trackPositionY)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionYTrack( anim::IExpressionScript* script )
{
	return (_trackPositionY = (_trackPositionY == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionY.ToString(), script) : _trackPositionY)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionYTrack( const lang::String& expression )
{
	return (_trackPositionY = (_trackPositionY == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionY.ToString(), expression) : _trackPositionY)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionZTrack()
{
	return (_trackPositionZ = (_trackPositionZ == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionZ.ToString()) : _trackPositionZ)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionZTrack( const anim::AnimationTrack& type )
{
	return (_trackPositionZ = (_trackPositionZ == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionZ.ToString(), type) : _trackPositionZ)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionZTrack( anim::IExpressionScript* script )
{
	return (_trackPositionZ = (_trackPositionZ == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionZ.ToString(), script) : _trackPositionZ)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionZTrack( const lang::String& expression )
{
	return (_trackPositionZ = (_trackPositionZ == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PositionZ.ToString(), expression) : _trackPositionZ)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedQuaternionTrack* NodeAnimationControllerImpl<T>::CreateOrientationTrack()
{
	return (_trackOrientation = (_trackOrientation == nullptr) ? _animation->CreateQuaternionTrack(NodeProperty::Orientation.ToString()) : _trackOrientation)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IExpressionQuaternionTrack* NodeAnimationControllerImpl<T>::CreateOrientationTrack( anim::IExpressionScript* script )
{
	return (_trackOrientation = (_trackOrientation == nullptr) ? _animation->CreateQuaternionTrack(NodeProperty::Orientation.ToString(), script) : _trackOrientation)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionQuaternionTrack* NodeAnimationControllerImpl<T>::CreateOrientationTrack( const lang::String& expression )
{
	return (_trackOrientation = (_trackOrientation == nullptr) ? _animation->CreateQuaternionTrack(NodeProperty::Orientation.ToString(), expression) : _trackOrientation)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationYawTrack()
{
	return (_trackOrientationYaw = (_trackOrientationYaw == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationYaw.ToString()) : _trackOrientationYaw)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationYawTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationYaw = (_trackOrientationYaw == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationYaw.ToString(), type) : _trackOrientationYaw)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationYawTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationYaw = (_trackOrientationYaw == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationYaw.ToString(), script) : _trackOrientationYaw)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationYawTrack( const lang::String& expression )
{
	return (_trackOrientationYaw = (_trackOrientationYaw == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationYaw.ToString(), expression) : _trackOrientationYaw)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationPitchTrack()
{
	return (_trackOrientationPitch = (_trackOrientationPitch == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationPitch.ToString()) : _trackOrientationPitch)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationPitchTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationPitch = (_trackOrientationPitch == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationPitch.ToString(), type) : _trackOrientationPitch)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationPitchTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationPitch = (_trackOrientationPitch == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationPitch.ToString(), script) : _trackOrientationPitch)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationPitchTrack( const lang::String& expression )
{
	return (_trackOrientationPitch = (_trackOrientationPitch == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationPitch.ToString(), expression) : _trackOrientationPitch)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationRollTrack()
{
	return (_trackOrientationRoll = (_trackOrientationRoll == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationRoll.ToString()) : _trackOrientationRoll)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationRollTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationRoll = (_trackOrientationRoll == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationRoll.ToString(), type) : _trackOrientationRoll)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationRollTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationRoll = (_trackOrientationRoll == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationRoll.ToString(), script) : _trackOrientationRoll)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationRollTrack( const lang::String& expression )
{
	return (_trackOrientationRoll = (_trackOrientationRoll == nullptr) ? _animation->CreateFloatTrack(NodeProperty::OrientationRoll.ToString(), expression) : _trackOrientationRoll)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedVector3Track* NodeAnimationControllerImpl<T>::CreateScaleTrack()
{
	return (_trackScale = (_trackScale == nullptr) ? _animation->CreateVector3Track(NodeProperty::Scale.ToString()) : _trackScale)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralVector3Track* NodeAnimationControllerImpl<T>::CreateScaleTrack( const anim::AnimationTrack& type )
{
	return (_trackScale = (_trackScale == nullptr) ? _animation->CreateVector3Track(NodeProperty::Scale.ToString(), type) : _trackScale)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionVector3Track* NodeAnimationControllerImpl<T>::CreateScaleTrack( anim::IExpressionScript* script )
{
	return (_trackScale = (_trackScale == nullptr) ? _animation->CreateVector3Track(NodeProperty::Scale.ToString(), script) : _trackScale)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionVector3Track* NodeAnimationControllerImpl<T>::CreateScaleTrack( const lang::String& expression )
{
	return (_trackScale = (_trackScale == nullptr) ? _animation->CreateVector3Track(NodeProperty::Scale.ToString(), expression) : _trackScale)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleXTrack()
{
	return (_trackScaleX = (_trackScaleX == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleX.ToString()) : _trackScaleX)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleXTrack( const anim::AnimationTrack& type )
{
	return (_trackScaleX = (_trackScaleX == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleX.ToString(), type) : _trackScaleX)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleXTrack( anim::IExpressionScript* script )
{
	return (_trackScaleX = (_trackScaleX == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleX.ToString(), script) : _trackScaleX)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleXTrack( const lang::String& expression )
{
	return (_trackScaleX = (_trackScaleX == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleX.ToString(), expression) : _trackScaleX)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleYTrack()
{
	return (_trackScaleY = (_trackScaleY == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleY.ToString()) : _trackScaleY)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleYTrack( const anim::AnimationTrack& type )
{
	return (_trackScaleY = (_trackScaleY == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleY.ToString(), type) : _trackScaleY)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleYTrack( anim::IExpressionScript* script )
{
	return (_trackScaleY = (_trackScaleY == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleY.ToString(), script) : _trackScaleY)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleYTrack( const lang::String& expression )
{
	return (_trackScaleY = (_trackScaleY == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleY.ToString(), expression) : _trackScaleY)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleZTrack()
{
	return (_trackScaleZ = (_trackScaleZ == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleZ.ToString()) : _trackScaleZ)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleZTrack( const anim::AnimationTrack& type )
{
	return (_trackScaleZ = (_trackScaleZ == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleZ.ToString(), type) : _trackScaleZ)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleZTrack( anim::IExpressionScript* script )
{
	return (_trackScaleZ = (_trackScaleZ == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleZ.ToString(), script) : _trackScaleZ)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleZTrack( const lang::String& expression )
{
	return (_trackScaleZ = (_trackScaleZ == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleZ.ToString(), expression) : _trackScaleZ)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleUniformTrack()
{
	return (_trackScaleUniform = (_trackScaleUniform == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleUniform.ToString()) : _trackScaleUniform)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleUniformTrack( const anim::AnimationTrack& type )
{
	return (_trackScaleUniform = (_trackScaleUniform == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleUniform.ToString(), type) : _trackScaleUniform)->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleUniformTrack( anim::IExpressionScript* script )
{
	return (_trackScaleUniform = (_trackScaleUniform == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleUniform.ToString(), script) : _trackScaleUniform)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleUniformTrack( const lang::String& expression )
{
	return (_trackScaleUniform = (_trackScaleUniform == nullptr) ? _animation->CreateFloatTrack(NodeProperty::ScaleUniform.ToString(), expression) : _trackScaleUniform)->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreatePathPhaseTrack()
{
	return (_trackPathPhase = (_trackPathPhase == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PathPhase.ToString()) : _trackPathPhase)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreatePathPhaseTrack( const anim::AnimationTrack& type )
{
	return (_trackPathPhase = (_trackPathPhase == nullptr) ? _animation->CreateFloatTrack(NodeProperty::PathPhase.ToString(), type) : _trackPathPhase)->AsProcedural();
}

template <class T>
SYNKRO_INLINE ICameraAnimationController* NodeAnimationControllerImpl<T>::AsCamera() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ILightAnimationController* NodeAnimationControllerImpl<T>::AsLight() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IMeshBatchAnimationController* NodeAnimationControllerImpl<T>::AsMeshBatch() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ISoundAnimationController* NodeAnimationControllerImpl<T>::AsSound() const
{
	return nullptr;
}
