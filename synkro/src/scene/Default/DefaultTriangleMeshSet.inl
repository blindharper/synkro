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
// Purpose: Default triangle mesh set implementation.
//==============================================================================
SYNKRO_INLINE INodeAnimationController* DefaultTriangleMeshSet::CreateAnimationController( anim::IAnimationSet* animations, anim::AnimationListener* listener )
{
	return nullptr;
}

SYNKRO_INLINE IParentConstraint* DefaultTriangleMeshSet::CreateParentConstraint( INode* parent, const math::Matrix4x4& transform )
{
	return nullptr;
}

SYNKRO_INLINE ILookAtConstraint* DefaultTriangleMeshSet::CreateLookAtConstraint( INode* target )
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetTransform( const math::Matrix4x4& transform )
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

SYNKRO_INLINE void DefaultTriangleMeshSet::SetPosition( const math::Vector3& position )
{
	_translation = position;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetPositionX( Float x )
{
	_translation.x = x;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetPositionY( Float y )
{
	_translation.y = y;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetPositionZ( Float z )
{
	_translation.z = z;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetOrientation( const math::Quaternion& orientation )
{
	_orientation = orientation;
	_orientation.GetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetOrientationYaw( Float yaw )
{
	_yaw = yaw;
	AdjustAngle( _yaw );
	_orientation.SetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetOrientationPitch( Float pitch )
{
	_pitch = pitch;
	AdjustAngle( _pitch );
	_orientation.SetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetOrientationRoll( Float roll )
{
	_roll = roll;
	AdjustAngle( _roll );
	_orientation.SetAngles( _yaw, _pitch, _roll );
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::LookAt( const math::Vector3& target )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetScale( const math::Vector3& scale )
{
	_scale = scale;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetScale( Float scale )
{
	SetScale( math::Vector3(scale) );
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetScaleX( Float scale )
{
	_scale.x = scale;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetScaleY( Float scale )
{
	_scale.y = scale;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetScaleZ( Float scale )
{
	_scale.z = scale;
	_transformDirty = true;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetPath( ICurve* path )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetPathPhase( Float phase )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetParent( INode* parent )
{
	_parent = parent;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::ShowGizmo( Bool show )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetGizmoSize( Float size )
{
	// Do nothing.
}

SYNKRO_INLINE IParentConstraint* DefaultTriangleMeshSet::GetParentConstraint() const
{
	return nullptr;
}

SYNKRO_INLINE ILookAtConstraint* DefaultTriangleMeshSet::GetLookAtConstraint() const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::GetWorldTransform( math::Matrix4x4& transform, Bool ignoreOrientation ) const
{
	math::Matrix4x4 parentTransform;
	if ( _parent != nullptr )
	{
		_parent->GetWorldTransform( parentTransform, ignoreOrientation );
	}

	math::Matrix4x4 nodeTransform;
	GetTransform( nodeTransform, ignoreOrientation );

	transform = parentTransform * nodeTransform;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::GetWorldTransform( math::Matrix4x4& transform ) const
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

SYNKRO_INLINE void DefaultTriangleMeshSet::GetTransform( math::Matrix4x4& transform, Bool ignoreOrientation ) const
{
	math::Matrix4x4 transPosition;
	transPosition.SetTranslation( _translation );
	math::Matrix4x4 transScale;
	transScale.SetScale( _scale );
	if ( ignoreOrientation )
	{
		transform = transPosition;
	}
	else
	{
		math::Matrix4x4 transOrientation;
		transOrientation.SetOrientation( _orientation );
		transform = transPosition * transOrientation;
	}
	transform = transform * transScale;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::GetTransform( math::Matrix4x4& transform ) const
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

SYNKRO_INLINE void DefaultTriangleMeshSet::GetPosition( math::Vector3& position ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetPositionX() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetPositionY() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetPositionZ() const
{
	return 0.0f;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::GetOrientation( math::Quaternion& orientation ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetOrientationYaw() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetOrientationPitch() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetOrientationRoll() const
{
	return 0.0f;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::GetScale( math::Vector3& scale ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetScaleX() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetScaleY() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetScaleZ() const
{
	return 0.0f;
}

SYNKRO_INLINE ICurve* DefaultTriangleMeshSet::GetPath() const
{
	return nullptr;
}

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetPathPhase() const
{
	return 0.0f;
}

SYNKRO_INLINE INode* DefaultTriangleMeshSet::GetParent() const
{
	return nullptr;
}

SYNKRO_INLINE INode* DefaultTriangleMeshSet::GetNode( const lang::String& name ) const
{
	return nullptr;
}

SYNKRO_INLINE ISceneEx* DefaultTriangleMeshSet::GetSceneEx() const
{
	return nullptr;
}

SYNKRO_INLINE lang::String DefaultTriangleMeshSet::GetName() const
{
	return lang::String::Empty;
}

SYNKRO_INLINE IBillboard* DefaultTriangleMeshSet::AsBillboard() const
{
	return nullptr;
}

SYNKRO_INLINE ICamera* DefaultTriangleMeshSet::AsCamera() const
{
	return nullptr;
}

SYNKRO_INLINE ILight* DefaultTriangleMeshSet::AsLight() const
{
	return nullptr;
}

SYNKRO_INLINE IMesh* DefaultTriangleMeshSet::AsMesh() const
{
	return nullptr;
}

SYNKRO_INLINE ISound* DefaultTriangleMeshSet::AsSound() const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::Show( Bool show )
{
	for ( UInt i = 0; i < _subsets.Size(); ++i )
	{
		_subsets[i]->Show( show );
	}
}

SYNKRO_INLINE UInt DefaultTriangleMeshSet::GetSubsetCount() const
{
	return _subsets.Size();
}

SYNKRO_INLINE lang::String DefaultTriangleMeshSet::GetSubsetName( UInt index ) const
{
	return lang::String::Empty;
}

SYNKRO_INLINE IPrimitive* DefaultTriangleMeshSet::GetSubset( UInt index ) const
{
	assert( index < _subsets.Size() );

	return _subsets[index];
}

SYNKRO_INLINE IPrimitive* DefaultTriangleMeshSet::GetSubset( const lang::String& name ) const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::GetCenter( math::Vector3& center ) const
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

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetBoundSphere() const
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

SYNKRO_INLINE Bool DefaultTriangleMeshSet::IsVisible() const
{
	return (_subsets.Size() > 0) && _subsets[0]->IsVisible();
}

SYNKRO_INLINE IPointMesh* DefaultTriangleMeshSet::AsPoint() const
{
	return nullptr;
}

SYNKRO_INLINE ILineMesh* DefaultTriangleMeshSet::AsLine() const
{
	return nullptr;
}


SYNKRO_INLINE ITriangleMesh* DefaultTriangleMeshSet::AsTriangle() const
{
	return (ITriangleMesh*)this;
}

SYNKRO_INLINE ISkeleton* DefaultTriangleMeshSet::GetSkeleton() const
{
	return nullptr;
}

SYNKRO_INLINE mat::IVisualMaterial* DefaultTriangleMeshSet::GetMaterial() const
{
	return _material;
}

SYNKRO_INLINE phys::IActor* DefaultTriangleMeshSet::GetActor() const
{
	return nullptr;
}

SYNKRO_INLINE IScene* DefaultTriangleMeshSet::GetScene() const
{
	return _scene;
}

SYNKRO_INLINE ITriangleMeshBatch* DefaultTriangleMeshSet::AsBatch() const
{
	return nullptr;
}

SYNKRO_INLINE ITriangleMeshSet* DefaultTriangleMeshSet::AsSet() const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::SetMinimumLevelSize( UInt index, Float size )
{
}

SYNKRO_INLINE UInt DefaultTriangleMeshSet::GetLevelCount() const
{
	return 0;
}

SYNKRO_INLINE Float DefaultTriangleMeshSet::GetMinimumLevelSize( UInt index ) const
{
	return 0.0f;
}

SYNKRO_INLINE void DefaultTriangleMeshSet::AdjustAngle( Float& angle )
{
	Float delta = math::Math::Abs( angle ) - math::Math::TwoPi;
	if ( delta > 0.0f )
	{
		angle = math::Math::Sign( angle ) * delta;
	}
}
