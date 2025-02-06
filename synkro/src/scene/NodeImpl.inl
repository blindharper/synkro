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
// Purpose: Generic INode interface implementation.
//==============================================================================
template <class T> 
SYNKRO_INLINE NodeImpl<T>::NodeImpl( ISceneEx* scene, core::IContext* context, const lang::String& name, Bool visualize ) :
	_context( context ),
	_scene( scene ),
	_name( name ),
	_transformDirty( true ),
	_scale( 1.0f ),
	_yaw( 0.0f ),
	_pitch( 0.0f ),
	_roll( 0.0f ),
	_parent( nullptr ),
	_child( nullptr ),
	_next( nullptr ),
	_prev( nullptr ),
	_pathPhase( 0.0f )
{
	// Create gizmo.
	if ( visualize && _scene->GetDebugMode().IsSet(DebugMode::Gizmos) )
	{
		_gizmo.Create( _context->GetGraphicsSystem(), _scene );
	}
}

template <class T>
SYNKRO_INLINE NodeImpl<T>::~NodeImpl()
{
	INode* parent = _parent;
	this->SetParent( nullptr );

	while ( _child != nullptr )
	{
		_child->SetParent( parent );
	}
}

template <class T>
SYNKRO_INLINE IParentConstraint* NodeImpl<T>::CreateParentConstraint( INode* parent, const math::Matrix4x4& transform )
{
	throw lang::NotSupportedException();
}

template <class T>
SYNKRO_INLINE ILookAtConstraint* NodeImpl<T>::CreateLookAtConstraint( INode* target )
{
	throw lang::NotSupportedException();
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetTransform( const math::Matrix4x4& transform )
{
	_transform = transform;
	_translation = _transform.Translation();
	_orientation = _transform.Orientation();
	_orientation.GetAngles( _yaw, _pitch, _roll );
	AdjustAngle( _yaw );
	AdjustAngle( _pitch );
	AdjustAngle( _roll );
	_scale = _transform.Scale();
	_transformDirty = false;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetPosition( const math::Vector3& position )
{
	_translation = position;
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetPositionX( Float x )
{
	_translation.x = x;
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetPositionY( Float y )
{
	_translation.y = y;
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetPositionZ( Float z )
{
	_translation.z = z;
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetOrientation( const math::Quaternion& orientation )
{
	_orientation = orientation;
	_orientation.GetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetOrientationYaw( Float yaw )
{
	_yaw = yaw;
	AdjustAngle( _yaw );
	_orientation.SetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetOrientationPitch( Float pitch )
{
	_pitch = pitch;
	AdjustAngle( _pitch );
	_orientation.SetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetOrientationRoll( Float roll )
{
	_roll = roll;
	AdjustAngle( _roll );
	_orientation.SetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::LookAt( const math::Vector3& target )
{
	_orientation = math::Quaternion::Identity;
	_transformDirty = true;

	math::Matrix4x4 transform;
	GetWorldTransform( transform );
	math::Vector3 eye = transform.Translation();
	
	math::Vector3 dir = (eye - target).Normalize();
	math::Vector3 forward = transform.Forward().Normalize();
	Float angle = forward * dir;

	if ( angle < -1+0.001f )
	{
		math::Vector3 axis = math::Vector3::Z ^ forward;
		Float len = axis.Length();
		if ( len*len < 0.01f )
		{
			axis = math::Vector3::X ^ forward;
		}
		axis.Normalize();
		math::Quaternion orientation( axis, math::Math::Pi );
		SetOrientation( orientation );
	}
	else
	{
		math::Vector3 axis = forward ^ dir;
		Float s = math::Math::Sqrt( (1.0f+angle)*2.0f );
		Float invs = 1.0f / s;
		math::Quaternion orientation( axis.x*invs, axis.y*invs, axis.z*invs, s*0.5f );
		SetOrientation( orientation );
	}
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetScale( const math::Vector3& scale )
{
	_scale = scale;
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetScale( Float scale )
{
	SetScale( math::Vector3(scale) );
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetScaleX( Float scale )
{
	_scale.x = scale;
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetScaleY( Float scale )
{
	_scale.y = scale;
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetScaleZ( Float scale )
{
	_scale.z = scale;
	_transformDirty = true;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetPath( ICurve* path )
{
	_path = path;
	SetPathPhase( _pathPhase );
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetPathPhase( Float phase )
{
	_pathPhase = math::Math::Clamp( phase, 0.0f, 1.0f );
	if ( _path != nullptr )
	{
		math::Vector3 position;
		_path->GetPosition( _pathPhase, position );
		SetPosition( position );
	}
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetParent( INode* parent )
{
	if ( parent == _parent )
		return;

	if ( parent != nullptr )
	{
		assert( this != parent );
		assert( !this->IsParent(parent) );

		SetParent( nullptr );

		_next = ((NodeImpl<T>*)parent)->_child;
		if ( _next != nullptr )
			((NodeImpl<T>*)(INode*)_next)->_prev = this;

		_parent = const_cast<INode*>( parent );
		((NodeImpl<T>*)_parent)->_child = this;
	}
	else if ( _parent != nullptr )
	{
		if ( ((NodeImpl<T>*)_parent)->_child == this )
		{
			assert( _prev == nullptr );
			((NodeImpl<T>*)_parent)->_child = _next;
			if ( _next != nullptr )
				((NodeImpl<T>*)(INode*)_next)->_prev = nullptr;
		}
		else
		{
			assert( _prev != nullptr );
			if ( _prev != nullptr )
				((NodeImpl<T>*)_prev)->_next = _next;
			if ( _next != nullptr )
				((NodeImpl<T>*)(INode*)_next)->_prev = _prev;
		}

		_next = _prev = _parent = nullptr;
	}
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::ShowGizmo( Bool show )
{
	_gizmo.Show( show );
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::SetGizmoSize( Float size )
{
	if ( _gizmo.IsCreated() )
	{
		_gizmo.SetSize( size );
	}
}

template <class T>
SYNKRO_INLINE IParentConstraint* NodeImpl<T>::GetParentConstraint() const
{
	return _parentConstraint;
}

template <class T>
SYNKRO_INLINE ILookAtConstraint* NodeImpl<T>::GetLookAtConstraint() const
{
	return _lookAtConstraint;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::GetWorldTransform( math::Matrix4x4& transform ) const
{
	math::Matrix4x4 parentTransform;
	if ( _parent != nullptr )
	{
		_parent->GetWorldTransform( parentTransform );
	}

	math::Matrix4x4 nodeTransform;
	GetTransform( nodeTransform );

	transform = parentTransform * nodeTransform;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::GetTransform( math::Matrix4x4& transform ) const
{
	if ( _transformDirty )
	{
		math::Matrix4x4 transPosition;
		transPosition.SetTranslation( _translation );
		math::Matrix4x4 transOrientation;
		transOrientation.SetOrientation( _orientation );
		math::Matrix4x4 transScale;
		transScale.SetScale( _scale );

		_transform = transPosition * transOrientation;
		_transform = _transform * transScale;
		_transformDirty = false;
	}
	transform = _transform;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::GetPosition( math::Vector3& position ) const
{
	if ( _transformDirty )
	{
		_transform.SetTranslation( _translation );
		_transformDirty = false;
	}
	position = _transform.Translation();
}

template <class T>
SYNKRO_INLINE Float NodeImpl<T>::GetPositionX() const
{
	return _translation.x;
}

template <class T>
SYNKRO_INLINE Float NodeImpl<T>::GetPositionY() const
{
	return _translation.y;
}

template <class T>
SYNKRO_INLINE Float NodeImpl<T>::GetPositionZ() const
{
	return _translation.z;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::GetOrientation( math::Quaternion& orientation ) const
{
	if ( _transformDirty )
	{
		_transform.SetOrientation( _orientation );
		_transformDirty = false;
	}
	orientation = _orientation;
}

template <class T>
SYNKRO_INLINE Float NodeImpl<T>::GetOrientationYaw() const
{
	return _yaw;
}

template <class T>
SYNKRO_INLINE Float NodeImpl<T>::GetOrientationPitch() const
{
	return _pitch;
}

template <class T>
SYNKRO_INLINE Float NodeImpl<T>::GetOrientationRoll() const
{
	return _roll;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::GetScale( math::Vector3& scale ) const
{
	if ( _transformDirty )
	{
		_transform.SetScale( _scale );
		_transformDirty = false;
	}
	scale = _transform.Scale();
}

template <class T>
SYNKRO_INLINE Float NodeImpl<T>::GetScaleX() const
{
	return _scale.x;
}

template <class T>
SYNKRO_INLINE Float NodeImpl<T>::GetScaleY() const
{
	return _scale.y;
}

template <class T>
SYNKRO_INLINE Float NodeImpl<T>::GetScaleZ() const
{
	return _scale.z;
}

template <class T>
SYNKRO_INLINE ICurve* NodeImpl<T>::GetPath() const
{
	return _path;
}

template <class T>
SYNKRO_INLINE Float NodeImpl<T>::GetPathPhase() const
{
	return _pathPhase;
}

template <class T>
SYNKRO_INLINE INode* NodeImpl<T>::GetParent() const
{
	return _parent;
}

template <class T>
SYNKRO_INLINE INode* NodeImpl<T>::GetNode( const lang::String& name ) const
{
	for ( INode* child = _child; child != nullptr; child = ((NodeImpl<T>*)child)->_next )
	{
		if ( child->GetName().EqualsTo(name, true) )
			return child;
	}
	return nullptr;
}

template <class T>
SYNKRO_INLINE ISceneEx* NodeImpl<T>::GetSceneEx() const
{
	return _scene;
}

template <class T>
SYNKRO_INLINE lang::String NodeImpl<T>::GetName() const
{
	return _name;
}

template <class T>
SYNKRO_INLINE ICamera* NodeImpl<T>::AsCamera() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ILight* NodeImpl<T>::AsLight() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IMesh* NodeImpl<T>::AsMesh() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ISound* NodeImpl<T>::AsSound() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE INode* NodeImpl<T>::GetNextNode() const
{
	INode* ret = nullptr;

	if ( ret = ((NodeImpl<T>*)this)->_child )
	{
		return ret;
	}
	else if ( ret = ((NodeImpl<T>*)this)->_next )
	{
		return ret;
	}
	else
	{
		for ( const INode* parent = this->GetParent(); parent; parent = parent->GetParent() )
		{
			if ( ret = ((NodeImpl<T>*)parent)->_next )
				return ret;
		}
	}

	return ret;
}

template <class T>
SYNKRO_INLINE Bool NodeImpl<T>::IsParent( const INode* node ) const
{
	for ( const INode* parent = this->GetParent(); parent; parent = parent->GetParent() )
	{
		if ( parent == node )
			return true;
	}

	return false;
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::AdjustAngle( Float& angle )
{
	Float delta = math::Math::Abs( angle ) - math::Math::TwoPi;
	if ( delta > 0.0f )
	{
		angle = math::Math::Sign( angle ) * delta;
	}
}

template <class T>
SYNKRO_INLINE void NodeImpl<T>::ApplyConstraints( INodeAnimationController* ctrl )
{
	if ( (ctrl == nullptr) || (ctrl->GetState() == ControllerState::Inactive) )
	{
		if ( (_parentConstraint != nullptr) && _parentConstraint->IsEnabled() )
		{
			_parentConstraint->Apply();
		}

		if ( (_lookAtConstraint != nullptr) && _lookAtConstraint->IsEnabled() )
		{
			_lookAtConstraint->Apply();
		}
	}
}
