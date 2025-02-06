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
// Purpose: Default triangle mesh batch implementation.
//==============================================================================
SYNKRO_INLINE void DefaultTriangleMeshBatch::SetTransform( const math::Matrix4x4& transform )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetPosition( const math::Vector3& position )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetPositionX( Float x )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetPositionY( Float y )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetPositionZ( Float z )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetOrientation( const math::Quaternion& orientation )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetOrientationYaw( Float yaw )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetOrientationPitch( Float pitch )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetOrientationRoll( Float roll )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::LookAt( const math::Vector3& target )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetScale( const math::Vector3& scale )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetScale( Float scale )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetScaleX( Float scale )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetScaleY( Float scale )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetScaleZ( Float scale )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetPath( ICurve* path )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetPathPhase( Float phase )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetParent( INode* parent )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::ShowGizmo( Bool show )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetGizmoSize( Float size )
{
	// Do nothing.
}

SYNKRO_INLINE IParentConstraint* DefaultTriangleMeshBatch::GetParentConstraint() const
{
	return nullptr;
}

SYNKRO_INLINE ILookAtConstraint* DefaultTriangleMeshBatch::GetLookAtConstraint() const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::GetWorldTransform( math::Matrix4x4& transform ) const
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::GetTransform( math::Matrix4x4& transform ) const
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::GetPosition( math::Vector3& position ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMeshBatch::GetPositionX() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshBatch::GetPositionY() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshBatch::GetPositionZ() const
{
	return 0.0f;
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::GetOrientation( math::Quaternion& orientation ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMeshBatch::GetOrientationYaw() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshBatch::GetOrientationPitch() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshBatch::GetOrientationRoll() const
{
	return 0.0f;
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::GetScale( math::Vector3& scale ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMeshBatch::GetScaleX() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshBatch::GetScaleY() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshBatch::GetScaleZ() const
{
	return 0.0f;
}

SYNKRO_INLINE ICurve* DefaultTriangleMeshBatch::GetPath() const
{
	return nullptr;
}

SYNKRO_INLINE Float DefaultTriangleMeshBatch::GetPathPhase() const
{
	return 0.0f;
}

SYNKRO_INLINE INode* DefaultTriangleMeshBatch::GetParent() const
{
	return nullptr;
}

SYNKRO_INLINE INode* DefaultTriangleMeshBatch::GetNode( const lang::String& name ) const
{
	return nullptr;
}

SYNKRO_INLINE ISceneEx* DefaultTriangleMeshBatch::GetSceneEx() const
{
	return nullptr;
}

SYNKRO_INLINE lang::String DefaultTriangleMeshBatch::GetName() const
{
	return lang::String::Empty;
}

SYNKRO_INLINE ICamera* DefaultTriangleMeshBatch::AsCamera() const
{
	return nullptr;
}

SYNKRO_INLINE ILight* DefaultTriangleMeshBatch::AsLight() const
{
	return nullptr;
}

SYNKRO_INLINE IMesh* DefaultTriangleMeshBatch::AsMesh() const
{
	return nullptr;
}

SYNKRO_INLINE ISound* DefaultTriangleMeshBatch::AsSound() const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::Show( Bool show )
{
	// Do nothing.
}

SYNKRO_INLINE UInt DefaultTriangleMeshBatch::GetSubsetCount() const
{
	return 0;
}

SYNKRO_INLINE lang::String DefaultTriangleMeshBatch::GetSubsetName( UInt index ) const
{
	return lang::String::Empty;
}

SYNKRO_INLINE IPrimitive* DefaultTriangleMeshBatch::GetSubset( UInt index ) const
{
	return nullptr;
}

SYNKRO_INLINE IPrimitive* DefaultTriangleMeshBatch::GetSubset( const lang::String& name ) const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::GetCenter( math::Vector3& center ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMeshBatch::GetBoundSphere() const
{
	return 0.0f;
}

SYNKRO_INLINE Bool DefaultTriangleMeshBatch::IsVisible() const
{
	return false;
}

SYNKRO_INLINE IPointMesh* DefaultTriangleMeshBatch::AsPoint() const
{
	return nullptr;
}

SYNKRO_INLINE ILineMesh* DefaultTriangleMeshBatch::AsLine() const
{
	return nullptr;
}

SYNKRO_INLINE ITriangleMesh* DefaultTriangleMeshBatch::AsTriangle() const
{
	return (ITriangleMesh*)this;
}

SYNKRO_INLINE ISkeleton* DefaultTriangleMeshBatch::GetSkeleton() const
{
	return _skeleton;
}

SYNKRO_INLINE mat::IVisualMaterial* DefaultTriangleMeshBatch::GetMaterial() const
{
	return _material;
}

SYNKRO_INLINE IScene* DefaultTriangleMeshBatch::GetScene() const
{
	return _scene;
}

SYNKRO_INLINE ITriangleMeshBatch* DefaultTriangleMeshBatch::AsBatch() const
{
	return (ITriangleMeshBatch*)this;
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::SetRange( const lang::Range& range )
{
	if ( range != _range )
	{
		for ( UInt i = 0; i < _subsets.Size(); ++i )
		{
			_subsets[i]->SetInstanceRange( range );
		}
		_range = range;
	}
}

SYNKRO_INLINE UInt DefaultTriangleMeshBatch::GetCapacity() const
{
	return _instances.Capacity();
}

SYNKRO_INLINE UInt DefaultTriangleMeshBatch::GetInstanceCount() const
{
	return _instances.Size();
}

SYNKRO_INLINE ITriangleMesh* DefaultTriangleMeshBatch::GetInstance( UInt index ) const
{
	assert( index < _instances.Size() );

	return _instances[index].AsPtr();
}

SYNKRO_INLINE void DefaultTriangleMeshBatch::GetRange( lang::Range& range ) const
{
	range = _range;
}
