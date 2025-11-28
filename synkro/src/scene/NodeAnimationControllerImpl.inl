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
SYNKRO_INLINE NodeAnimationControllerImpl<T>::NodeAnimationControllerImpl( INode* node, anim::IAnimationSystem* animationSystem, anim::IAnimationSet* animations, anim::AnimationListener* listener ) :
	anim::PlaybackControllerImpl<T>( animationSystem, animations, listener ),
	_node( node ),
	_trackTransform( nullptr ),
	_trackPosition( nullptr ),
	_trackPositionX( nullptr ),
	_trackPositionY( nullptr ),
	_trackPositionZ( nullptr ),
	_trackOrientation( nullptr ),
	_trackOrientationYaw( nullptr ),
	_trackOrientationPitch( nullptr ),
	_trackOrientationRoll( nullptr ),
	_trackScale( nullptr ),
	_trackScaleX( nullptr ),
	_trackScaleY( nullptr ),
	_trackScaleZ( nullptr ),
	_trackScaleUniform( nullptr ),
	_trackPathPhase( nullptr )
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
		_trackTransform->GetValue( CurrentTime(), transform );
		_node->SetTransform( transform );
	}
	else
	{
		if ( _trackScale != nullptr )
		{
			math::Vector3 scale;
			_trackScale->GetValue( CurrentTime(), scale );
			_node->SetScale( scale );
		}
		else
		{
			if ( _trackScaleUniform != nullptr )
			{
				Float scale;
				_trackScaleUniform->GetValue( CurrentTime(), scale );
				_node->SetScale( scale );
			}
			else
			{
				if ( _trackScaleX != nullptr )
				{
					Float scale;
					_trackScaleX->GetValue( CurrentTime(), scale );
					_node->SetScaleX( scale );
				}

				if ( _trackScaleY != nullptr )
				{
					Float scale;
					_trackScaleY->GetValue( CurrentTime(), scale );
					_node->SetScaleY( scale );
				}

				if ( _trackScaleZ != nullptr )
				{
					Float scale;
					_trackScaleZ->GetValue( CurrentTime(), scale );
					_node->SetScaleZ( scale );
				}
			}
		}

		ICurve* path = _node->GetPath();
		if ( (path != nullptr) && (_trackPathPhase != nullptr) )
		{
			Float phase;
			_trackPathPhase->GetValue( CurrentTime(), phase );
			_node->SetPathPhase( phase );
		}
		else if ( _trackPosition != nullptr )
		{
			math::Vector3 position;
			_trackPosition->GetValue( CurrentTime(), position );
			_node->SetPosition( position );
		}
		else
		{
			if ( _trackPositionX != nullptr )
			{
				Float pos;
				_trackPositionX->GetValue( CurrentTime(), pos );
				_node->SetPositionX( pos );
			}

			if ( _trackPositionY != nullptr )
			{
				Float pos;
				_trackPositionY->GetValue( CurrentTime(), pos );
				_node->SetPositionY( pos );
			}

			if ( _trackPositionZ != nullptr )
			{
				Float pos;
				_trackPositionZ->GetValue( CurrentTime(), pos );
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
			_trackOrientation->GetValue( CurrentTime(), orientation );
			_node->SetOrientation( orientation );
		}
		else
		{
			if ( _trackOrientationYaw != nullptr )
			{
				Float angle;
				_trackOrientationYaw->GetValue( CurrentTime(), angle );
				_node->SetOrientationYaw( angle );
			}

			if ( _trackOrientationPitch != nullptr )
			{
				Float angle;
				_trackOrientationPitch->GetValue( CurrentTime(), angle );
				_node->SetOrientationPitch( angle );
			}

			if ( _trackOrientationRoll != nullptr )
			{
				Float angle;
				_trackOrientationRoll->GetValue( CurrentTime(), angle );
				_node->SetOrientationRoll( angle );
			}
		}
	}
}

template <class T>
SYNKRO_INLINE anim::IKeyframedMatrix4x4Track* NodeAnimationControllerImpl<T>::CreateTransformTrack()
{
	return (_trackTransform = _animations->GetActiveAnimation()->CreateMatrix4x4Track( NodeProperty::Transform.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IExpressionMatrix4x4Track* NodeAnimationControllerImpl<T>::CreateTransformTrack( anim::IExpressionScript* script )
{
	return (_trackTransform = _animations->GetActiveAnimation()->CreateMatrix4x4Track( NodeProperty::Transform.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionMatrix4x4Track* NodeAnimationControllerImpl<T>::CreateTransformTrack( const lang::String& expression )
{
	return (_trackTransform = _animations->GetActiveAnimation()->CreateMatrix4x4Track( NodeProperty::Transform.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedVector3Track* NodeAnimationControllerImpl<T>::CreatePositionTrack()
{
	return (_trackPosition = _animations->GetActiveAnimation()->CreateVector3Track( NodeProperty::Position.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralVector3Track* NodeAnimationControllerImpl<T>::CreatePositionTrack( const anim::AnimationTrack& type )
{
	return (_trackPosition = _animations->GetActiveAnimation()->CreateVector3Track( NodeProperty::Position.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionVector3Track* NodeAnimationControllerImpl<T>::CreatePositionTrack( anim::IExpressionScript* script )
{
	return (_trackPosition = _animations->GetActiveAnimation()->CreateVector3Track( NodeProperty::Position.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionVector3Track* NodeAnimationControllerImpl<T>::CreatePositionTrack( const lang::String& expression )
{
	return (_trackPosition = _animations->GetActiveAnimation()->CreateVector3Track( NodeProperty::Position.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionXTrack()
{
	return (_trackPositionX = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionX.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionXTrack( const anim::AnimationTrack& type )
{
	return (_trackPositionX = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionX.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionXTrack( anim::IExpressionScript* script )
{
	return (_trackPositionX = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionX.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionXTrack( const lang::String& expression )
{
	return (_trackPositionX = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionX.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionYTrack()
{	
	return (_trackPositionY = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionY.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionYTrack( const anim::AnimationTrack& type )
{
	return (_trackPositionY = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionY.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionYTrack( anim::IExpressionScript* script )
{
	return (_trackPositionY = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionY.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionYTrack( const lang::String& expression )
{
	return (_trackPositionY = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionY.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionZTrack()
{
	return (_trackPositionZ = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionZ.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionZTrack( const anim::AnimationTrack& type )
{
	return (_trackPositionZ = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionZ.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionZTrack( anim::IExpressionScript* script )
{
	return (_trackPositionZ = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionZ.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreatePositionZTrack( const lang::String& expression )
{
	return (_trackPositionZ = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PositionZ.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedQuaternionTrack* NodeAnimationControllerImpl<T>::CreateOrientationTrack()
{
	return (_trackOrientation = _animations->GetActiveAnimation()->CreateQuaternionTrack( NodeProperty::Orientation.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralQuaternionTrack* NodeAnimationControllerImpl<T>::CreateOrientationTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientation = _animations->GetActiveAnimation()->CreateQuaternionTrack( NodeProperty::Orientation.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionQuaternionTrack* NodeAnimationControllerImpl<T>::CreateOrientationTrack( anim::IExpressionScript* script )
{
	return (_trackOrientation = _animations->GetActiveAnimation()->CreateQuaternionTrack( NodeProperty::Orientation.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionQuaternionTrack* NodeAnimationControllerImpl<T>::CreateOrientationTrack( const lang::String& expression )
{
	return (_trackOrientation = _animations->GetActiveAnimation()->CreateQuaternionTrack( NodeProperty::Orientation.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationYawTrack()
{
	return (_trackOrientationYaw = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationYaw.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationYawTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationYaw = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationYaw.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationYawTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationYaw = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationYaw.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationYawTrack( const lang::String& expression )
{
	return (_trackOrientationYaw = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationYaw.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationPitchTrack()
{
	return (_trackOrientationPitch = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationPitch.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationPitchTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationPitch = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationPitch.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationPitchTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationPitch = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationPitch.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationPitchTrack( const lang::String& expression )
{
	return (_trackOrientationPitch = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationPitch.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationRollTrack()
{
	return (_trackOrientationRoll = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationRoll.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationRollTrack( const anim::AnimationTrack& type )
{
	return (_trackOrientationRoll = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationRoll.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationRollTrack( anim::IExpressionScript* script )
{
	return (_trackOrientationRoll = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationRoll.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateOrientationRollTrack( const lang::String& expression )
{
	return (_trackOrientationRoll = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::OrientationRoll.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedVector3Track* NodeAnimationControllerImpl<T>::CreateScaleTrack()
{
	return (_trackScale = _animations->GetActiveAnimation()->CreateVector3Track( NodeProperty::Scale.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralVector3Track* NodeAnimationControllerImpl<T>::CreateScaleTrack( const anim::AnimationTrack& type )
{
	return (_trackScale = _animations->GetActiveAnimation()->CreateVector3Track( NodeProperty::Scale.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionVector3Track* NodeAnimationControllerImpl<T>::CreateScaleTrack( anim::IExpressionScript* script )
{
	return (_trackScale = _animations->GetActiveAnimation()->CreateVector3Track( NodeProperty::Scale.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionVector3Track* NodeAnimationControllerImpl<T>::CreateScaleTrack( const lang::String& expression )
{
	return (_trackScale = _animations->GetActiveAnimation()->CreateVector3Track( NodeProperty::Scale.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleXTrack()
{
	return (_trackScaleX = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleX.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleXTrack( const anim::AnimationTrack& type )
{
	return (_trackScaleX = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleX.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleXTrack( anim::IExpressionScript* script )
{
	return (_trackScaleX = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleX.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleXTrack( const lang::String& expression )
{
	return (_trackScaleX = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleX.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleYTrack()
{
	return (_trackScaleY = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleY.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleYTrack( const anim::AnimationTrack& type )
{
	return (_trackScaleY = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleY.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleYTrack( anim::IExpressionScript* script )
{
	return (_trackScaleY = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleY.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleYTrack( const lang::String& expression )
{
	return (_trackScaleY = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleY.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleZTrack()
{
	return (_trackScaleZ = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleZ.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleZTrack( const anim::AnimationTrack& type )
{
	return (_trackScaleZ = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleZ.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleZTrack( anim::IExpressionScript* script )
{
	return (_trackScaleZ = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleZ.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleZTrack( const lang::String& expression )
{
	return (_trackScaleZ = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleZ.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleUniformTrack()
{
	return (_trackScaleUniform = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleUniform.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleUniformTrack( const anim::AnimationTrack& type )
{
	return (_trackScaleUniform = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleUniform.ToString(), type) )->AsProcedural();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleUniformTrack( anim::IExpressionScript* script )
{
	return (_trackScaleUniform = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleUniform.ToString(), script) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IExpressionFloatTrack* NodeAnimationControllerImpl<T>::CreateScaleUniformTrack( const lang::String& expression )
{
	return (_trackScaleUniform = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::ScaleUniform.ToString(), expression) )->AsExpression();
}

template <class T>
SYNKRO_INLINE anim::IKeyframedFloatTrack* NodeAnimationControllerImpl<T>::CreatePathPhaseTrack()
{
	return (_trackPathPhase = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PathPhase.ToString()) )->AsKeyframed();
}

template <class T>
SYNKRO_INLINE anim::IProceduralFloatTrack* NodeAnimationControllerImpl<T>::CreatePathPhaseTrack( const anim::AnimationTrack& type )
{
	return (_trackPathPhase = _animations->GetActiveAnimation()->CreateFloatTrack( NodeProperty::PathPhase.ToString(), type) )->AsProcedural();
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

template <class T>
SYNKRO_INLINE void NodeAnimationControllerImpl<T>::UpdateTracks()
{
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
