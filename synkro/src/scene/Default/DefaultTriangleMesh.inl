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
// Purpose: Default triangle mesh implementation.
//==============================================================================
SYNKRO_INLINE INodeAnimationController* DefaultTriangleMesh::CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener )
{
	return nullptr;
}

SYNKRO_INLINE IParentConstraint* DefaultTriangleMesh::CreateParentConstraint( INode* parent, const math::Matrix4x4& transform )
{
	return nullptr;
}

SYNKRO_INLINE ILookAtConstraint* DefaultTriangleMesh::CreateLookAtConstraint( INode* target )
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetTransform( const math::Matrix4x4& transform )
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

SYNKRO_INLINE void DefaultTriangleMesh::SetPosition( const math::Vector3& position )
{
	_translation = position;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetPositionX( Float x )
{
	_translation.x = x;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetPositionY( Float y )
{
	_translation.y = y;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetPositionZ( Float z )
{
	_translation.z = z;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetOrientation( const math::Quaternion& orientation )
{
	_orientation = orientation;
	_orientation.GetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetOrientationYaw( Float yaw )
{
	_yaw = yaw;
	AdjustAngle( _yaw );
	_orientation.SetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetOrientationPitch( Float pitch )
{
	_pitch = pitch;
	AdjustAngle( _pitch );
	_orientation.SetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetOrientationRoll( Float roll )
{
	_roll = roll;
	AdjustAngle( _roll );
	_orientation.SetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::LookAt( const math::Vector3& target )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMesh::SetScale( const math::Vector3& scale )
{
	_scale = scale;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetScale( Float scale )
{
	SetScale( math::Vector3(scale) );
}

SYNKRO_INLINE void DefaultTriangleMesh::SetScaleX( Float scale )
{
	_scale.x = scale;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetScaleY( Float scale )
{
	_scale.y = scale;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetScaleZ( Float scale )
{
	_scale.z = scale;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMesh::SetPath( ICurve* path )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMesh::SetPathPhase( Float phase )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMesh::SetParent( INode* parent )
{
	_parent = parent;
}

SYNKRO_INLINE void DefaultTriangleMesh::ShowGizmo( Bool show )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMesh::SetGizmoSize( Float size )
{
	// Do nothing.
}

SYNKRO_INLINE IParentConstraint* DefaultTriangleMesh::GetParentConstraint() const
{
	return nullptr;
}

SYNKRO_INLINE ILookAtConstraint* DefaultTriangleMesh::GetLookAtConstraint() const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMesh::GetWorldTransform( math::Matrix4x4& transform ) const
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

SYNKRO_INLINE void DefaultTriangleMesh::GetTransform( math::Matrix4x4& transform ) const
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

SYNKRO_INLINE void DefaultTriangleMesh::GetPosition( math::Vector3& position ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMesh::GetPositionX() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMesh::GetPositionY() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMesh::GetPositionZ() const
{
	return 0.0f;
}

SYNKRO_INLINE void DefaultTriangleMesh::GetOrientation( math::Quaternion& orientation ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMesh::GetOrientationYaw() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMesh::GetOrientationPitch() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMesh::GetOrientationRoll() const
{
	return 0.0f;
}

SYNKRO_INLINE void DefaultTriangleMesh::GetScale( math::Vector3& scale ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMesh::GetScaleX() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMesh::GetScaleY() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMesh::GetScaleZ() const
{
	return 0.0f;
}

SYNKRO_INLINE ICurve* DefaultTriangleMesh::GetPath() const
{
	return nullptr;
}

SYNKRO_INLINE Float DefaultTriangleMesh::GetPathPhase() const
{
	return 0.0f;
}

SYNKRO_INLINE INode* DefaultTriangleMesh::GetParent() const
{
	return nullptr;
}

SYNKRO_INLINE INode* DefaultTriangleMesh::GetNode( const lang::String& name ) const
{
	return nullptr;
}

SYNKRO_INLINE ISceneEx* DefaultTriangleMesh::GetSceneEx() const
{
	return nullptr;
}

SYNKRO_INLINE lang::String DefaultTriangleMesh::GetName() const
{
	return lang::String::Empty;
}

SYNKRO_INLINE ICamera* DefaultTriangleMesh::AsCamera() const
{
	return nullptr;
}

SYNKRO_INLINE ILight* DefaultTriangleMesh::AsLight() const
{
	return nullptr;
}

SYNKRO_INLINE IMesh* DefaultTriangleMesh::AsMesh() const
{
	return nullptr;
}

SYNKRO_INLINE ISound* DefaultTriangleMesh::AsSound() const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMesh::Show( Bool show )
{
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		_subsets[i]->Show( show );
	}
}

SYNKRO_INLINE UInt DefaultTriangleMesh::GetSubsetCount() const
{
	return _subsets.Size();
}

SYNKRO_INLINE lang::String DefaultTriangleMesh::GetSubsetName( UInt index ) const
{
	return lang::String::Empty;
}

SYNKRO_INLINE IPrimitive* DefaultTriangleMesh::GetSubset( UInt index ) const
{
	assert( index < _subsets.Size() );

	return _subsets[index];
}

SYNKRO_INLINE IPrimitive* DefaultTriangleMesh::GetSubset( const lang::String& name ) const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMesh::GetCenter( math::Vector3& center ) const
{
	if ( _base != nullptr )
	{
		_base->GetCenter( center );
		return;
	}

	math::Vector3 total;
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		math::Vector3 vec;
		_subsets[i]->GetCenter( vec );
		total += vec;
	}
	center = total/CastFloat(_subsets.Size());
}

SYNKRO_INLINE Float DefaultTriangleMesh::GetBoundSphere() const
{
	if ( _base != nullptr )
		return _base->GetBoundSphere();

	Float boundSphere = 0.0f;

	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		Float primitiveSphere = _subsets[i]->GetBoundSphere();
		if ( boundSphere < primitiveSphere )
		{
			boundSphere = primitiveSphere;
		}
	}

	return boundSphere;
}

SYNKRO_INLINE Bool DefaultTriangleMesh::IsVisible() const
{
	return (_subsets.Size() > 0) && _subsets[0]->IsVisible();
}

SYNKRO_INLINE IPointMesh* DefaultTriangleMesh::AsPoint() const
{
	return nullptr;
}

SYNKRO_INLINE ILineMesh* DefaultTriangleMesh::AsLine() const
{
	return nullptr;
}


SYNKRO_INLINE ITriangleMesh* DefaultTriangleMesh::AsTriangle() const
{
	return (ITriangleMesh*)this;
}

SYNKRO_INLINE ISkeleton* DefaultTriangleMesh::GetSkeleton() const
{
	return _skeleton;
}

SYNKRO_INLINE mat::IVisualMaterial* DefaultTriangleMesh::GetMaterial() const
{
	return _material;
}

SYNKRO_INLINE IScene* DefaultTriangleMesh::GetScene() const
{
	return _scene;
}

SYNKRO_INLINE ITriangleMeshBatch* DefaultTriangleMesh::AsBatch() const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMesh::AdjustAngle( Float& angle )
{
	Float delta = math::Math::Abs( angle ) - math::Math::TwoPi;
	if ( delta > 0.0f )
	{
		angle = math::Math::Sign( angle ) * delta;
	}
}
