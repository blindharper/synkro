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
// Purpose: Default triangle mesh node instance implementation.
//==============================================================================
SYNKRO_INLINE void DefaultTriangleMeshInstance::SetTransform( const math::Matrix4x4& transform )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetPosition( const math::Vector3& position )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetPositionX( Float x )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetPositionY( Float y )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetPositionZ( Float z )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetOrientation( const math::Quaternion& orientation )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetOrientationYaw( Float yaw )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetOrientationPitch( Float pitch )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetOrientationRoll( Float roll )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::LookAt( const math::Vector3& target )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetScale( const math::Vector3& scale )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetScale( Float scale )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetScaleX( Float scale )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetScaleY( Float scale )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetScaleZ( Float scale )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetPath( ICurve* path )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetPathPhase( Float phase )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetParent( INode* parent )
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::ShowGizmo( Bool show )
{
	// Do nothing.
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::SetGizmoSize( Float size )
{
	// Do nothing.
}

SYNKRO_INLINE IParentConstraint* DefaultTriangleMeshInstance::GetParentConstraint() const
{
	return nullptr;
}

SYNKRO_INLINE ILookAtConstraint* DefaultTriangleMeshInstance::GetLookAtConstraint() const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::GetWorldTransform( math::Matrix4x4& transform ) const
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::GetTransform( math::Matrix4x4& transform ) const
{
	// TODO:
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::GetPosition( math::Vector3& position ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMeshInstance::GetPositionX() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshInstance::GetPositionY() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshInstance::GetPositionZ() const
{
	return 0.0f;
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::GetOrientation( math::Quaternion& orientation ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMeshInstance::GetOrientationYaw() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshInstance::GetOrientationPitch() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshInstance::GetOrientationRoll() const
{
	return 0.0f;
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::GetScale( math::Vector3& scale ) const
{
	// Do nothing.
}

SYNKRO_INLINE Float DefaultTriangleMeshInstance::GetScaleX() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshInstance::GetScaleY() const
{
	return 0.0f;
}

SYNKRO_INLINE Float DefaultTriangleMeshInstance::GetScaleZ() const
{
	return 0.0f;
}

SYNKRO_INLINE ICurve* DefaultTriangleMeshInstance::GetPath() const
{
	return nullptr;
}

SYNKRO_INLINE Float DefaultTriangleMeshInstance::GetPathPhase() const
{
	return 0.0f;
}

SYNKRO_INLINE INode* DefaultTriangleMeshInstance::GetParent() const
{
	return nullptr;
}

SYNKRO_INLINE INode* DefaultTriangleMeshInstance::GetNode( const lang::String& name ) const
{
	return nullptr;
}

SYNKRO_INLINE ISceneEx* DefaultTriangleMeshInstance::GetSceneEx() const
{
	return nullptr;
}

SYNKRO_INLINE lang::String DefaultTriangleMeshInstance::GetName() const
{
	return lang::String::Empty;
}

SYNKRO_INLINE ICamera* DefaultTriangleMeshInstance::AsCamera() const
{
	return nullptr;
}

SYNKRO_INLINE ILight* DefaultTriangleMeshInstance::AsLight() const
{
	return nullptr;
}

SYNKRO_INLINE IMesh* DefaultTriangleMeshInstance::AsMesh() const
{
	return (IMesh*)this;
}

SYNKRO_INLINE ISound* DefaultTriangleMeshInstance::AsSound() const
{
	return nullptr;
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::Show( Bool show )
{
	_visible = show;
}

SYNKRO_INLINE UInt DefaultTriangleMeshInstance::GetSubsetCount() const
{
	return _batch->GetSubsetCount();
}

SYNKRO_INLINE lang::String DefaultTriangleMeshInstance::GetSubsetName( UInt index ) const
{
	return _batch->GetSubsetName( index );
}

SYNKRO_INLINE IPrimitive* DefaultTriangleMeshInstance::GetSubset( UInt index ) const
{
	return _batch->GetSubset( index );
}

SYNKRO_INLINE IPrimitive* DefaultTriangleMeshInstance::GetSubset( const lang::String& name ) const
{
	return _batch->GetSubset( name );
}

SYNKRO_INLINE void DefaultTriangleMeshInstance::GetCenter( math::Vector3& center ) const
{
	_batch->GetCenter( center );
}

SYNKRO_INLINE Float DefaultTriangleMeshInstance::GetBoundSphere() const
{
	return _batch->GetBoundSphere();
}

SYNKRO_INLINE Bool DefaultTriangleMeshInstance::IsVisible() const
{
	return _visible;
}

SYNKRO_INLINE ILineMesh* DefaultTriangleMeshInstance::AsLine() const
{
	return nullptr;
}

SYNKRO_INLINE IPointMesh* DefaultTriangleMeshInstance::AsPoint() const
{
	return nullptr;
}

SYNKRO_INLINE ITriangleMesh* DefaultTriangleMeshInstance::AsTriangle() const
{
	return (ITriangleMesh*)this;
}

SYNKRO_INLINE ITriangleSet* DefaultTriangleMeshInstance::CreateTriangleList( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform )
{
	return _batch->CreateTriangleList( name, vertexCount, indexCount, adjacency, transform );
}

SYNKRO_INLINE ITriangleSet* DefaultTriangleMeshInstance::CreateTriangleStrip( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform )
{
	return _batch->CreateTriangleStrip( name, vertexCount, indexCount, adjacency, transform );
}

SYNKRO_INLINE ITriangleSet* DefaultTriangleMeshInstance::CreateTriangleSet( const lang::String& name, const lang::Range& range )
{
	return _batch->CreateTriangleSet( name, range );
}

SYNKRO_INLINE ISkeleton* DefaultTriangleMeshInstance::GetSkeleton() const
{
	return _skeleton;
}

SYNKRO_INLINE mat::IVisualMaterial* DefaultTriangleMeshInstance::GetMaterial() const
{
	return _material;
}

SYNKRO_INLINE IScene* DefaultTriangleMeshInstance::GetScene() const
{
	return nullptr;
}

SYNKRO_INLINE ITriangleMeshBatch* DefaultTriangleMeshInstance::AsBatch() const
{
	return nullptr;
}
