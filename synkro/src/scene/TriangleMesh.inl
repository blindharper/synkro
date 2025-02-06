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
// Purpose: Triangle mesh implementation.
//==============================================================================
SYNKRO_INLINE void TriangleMesh::SetTransform( const math::Matrix4x4& transform )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetTransform( transform );

	_mesh->SetTransform( transform );
}

SYNKRO_INLINE void TriangleMesh::SetPosition( const math::Vector3& position )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetPosition( position );

	_mesh->SetPosition( position );
}

SYNKRO_INLINE void TriangleMesh::SetPositionX( Float x )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetPositionX( x );

	_mesh->SetPositionX( x );
}

SYNKRO_INLINE void TriangleMesh::SetPositionY( Float y )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetPositionY( y );

	_mesh->SetPositionY( y );
}

SYNKRO_INLINE void TriangleMesh::SetPositionZ( Float z )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetPositionZ( z );

	_mesh->SetPositionZ( z );
}

SYNKRO_INLINE void TriangleMesh::SetOrientation( const math::Quaternion& orientation )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetOrientation( orientation );

	_mesh->SetOrientation( orientation );
}

SYNKRO_INLINE void TriangleMesh::SetOrientationYaw( Float yaw )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetOrientationYaw( yaw );

	_mesh->SetOrientationYaw( yaw );
}

SYNKRO_INLINE void TriangleMesh::SetOrientationPitch( Float pitch )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetOrientationPitch( pitch );

	_mesh->SetOrientationPitch( pitch );
}

SYNKRO_INLINE void TriangleMesh::SetOrientationRoll( Float roll )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetOrientationRoll( roll );

	_mesh->SetOrientationRoll( roll );
}

SYNKRO_INLINE void TriangleMesh::LookAt( const math::Vector3& target )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::LookAt( target );

	_mesh->LookAt( target );
}

SYNKRO_INLINE void TriangleMesh::SetScale( const math::Vector3& scale )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetScale( scale );

	_mesh->SetScale( scale );
}

SYNKRO_INLINE void TriangleMesh::SetScale( Float scale )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetScale( scale );

	_mesh->SetScale( scale );
}

SYNKRO_INLINE void TriangleMesh::SetScaleX( Float scale )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetScaleX( scale );

	_mesh->SetScaleX( scale );
}

SYNKRO_INLINE void TriangleMesh::SetScaleY( Float scale )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetScaleY( scale );

	_mesh->SetScaleY( scale );
}

SYNKRO_INLINE void TriangleMesh::SetScaleZ( Float scale )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetScaleZ( scale );

	_mesh->SetScaleZ( scale );
}

SYNKRO_INLINE void TriangleMesh::SetParent( INode* parent )
{
	// Call base implementation.
	MeshImpl<ITriangleMesh>::SetParent( parent );

	_mesh->SetParent( parent );
}

SYNKRO_INLINE ITriangleMesh* TriangleMesh::AsTriangle() const
{
	return (ITriangleMesh*)this;
}

SYNKRO_INLINE ISkeleton* TriangleMesh::GetSkeleton() const
{
	return _skeleton;
}

SYNKRO_INLINE mat::IVisualMaterial* TriangleMesh::GetMaterial() const
{
	return _mesh->GetMaterial();
}

SYNKRO_INLINE IScene* TriangleMesh::GetScene() const
{
	return _scene;
}

SYNKRO_INLINE ITriangleMeshBatch* TriangleMesh::AsBatch() const
{
	return nullptr;
}
