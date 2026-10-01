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
// Purpose: Triangle mesh set implementation.
//==============================================================================
SYNKRO_INLINE void TriangleMeshSet::SetTransform( const math::Matrix4x4& transform )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetTransform( transform );

	_meshSet->SetTransform( transform );
}

SYNKRO_INLINE void TriangleMeshSet::SetPosition( const math::Vector3& position )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetPosition( position );

	_meshSet->SetPosition( position );
}

SYNKRO_INLINE void TriangleMeshSet::SetPositionX( Float x )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetPositionX( x );

	_meshSet->SetPositionX( x );
}

SYNKRO_INLINE void TriangleMeshSet::SetPositionY( Float y )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetPositionY( y );

	_meshSet->SetPositionY( y );
}

SYNKRO_INLINE void TriangleMeshSet::SetPositionZ( Float z )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetPositionZ( z );

	_meshSet->SetPositionZ( z );
}

SYNKRO_INLINE void TriangleMeshSet::SetOrientation( const math::Quaternion& orientation )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetOrientation( orientation );

	_meshSet->SetOrientation( orientation );
}

SYNKRO_INLINE void TriangleMeshSet::SetOrientationYaw( Float yaw )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetOrientationYaw( yaw );

	_meshSet->SetOrientationYaw( yaw );
}

SYNKRO_INLINE void TriangleMeshSet::SetOrientationPitch( Float pitch )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetOrientationPitch( pitch );

	_meshSet->SetOrientationPitch( pitch );
}

SYNKRO_INLINE void TriangleMeshSet::SetOrientationRoll( Float roll )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetOrientationRoll( roll );

	_meshSet->SetOrientationRoll( roll );
}

SYNKRO_INLINE void TriangleMeshSet::LookAt( const math::Vector3& target )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::LookAt( target );

	_meshSet->LookAt( target );
}

SYNKRO_INLINE void TriangleMeshSet::SetScale( const math::Vector3& scale )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetScale( scale );

	_meshSet->SetScale( scale );
}

SYNKRO_INLINE void TriangleMeshSet::SetScale( Float scale )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetScale( scale );

	_meshSet->SetScale( scale );
}

SYNKRO_INLINE void TriangleMeshSet::SetScaleX( Float scale )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetScaleX( scale );

	_meshSet->SetScaleX( scale );
}

SYNKRO_INLINE void TriangleMeshSet::SetScaleY( Float scale )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetScaleY( scale );

	_meshSet->SetScaleY( scale );
}

SYNKRO_INLINE void TriangleMeshSet::SetScaleZ( Float scale )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetScaleZ( scale );

	_meshSet->SetScaleZ( scale );
}

SYNKRO_INLINE void TriangleMeshSet::SetParent( INode* parent )
{
	// Call base implementation.
	MeshImpl<ITriangleMeshSet>::SetParent( parent );

	_meshSet->SetParent( parent );
}

SYNKRO_INLINE ITriangleMesh* TriangleMeshSet::AsTriangle() const
{
	return (ITriangleMesh*)this;
}

SYNKRO_INLINE ISkeleton* TriangleMeshSet::GetSkeleton() const
{
	return nullptr;
}

SYNKRO_INLINE mat::IVisualMaterial* TriangleMeshSet::GetMaterial() const
{
	return _meshSet->GetMaterial();
}

SYNKRO_INLINE phys::IActor* TriangleMeshSet::GetActor() const
{
	return _actor;
}

SYNKRO_INLINE IScene* TriangleMeshSet::GetScene() const
{
	return _scene;
}

SYNKRO_INLINE ITriangleMeshBatch* TriangleMeshSet::AsBatch() const
{
	return nullptr;
}

SYNKRO_INLINE ITriangleMeshSet* TriangleMeshSet::AsSet() const
{
	return (ITriangleMeshSet*)this;
}

SYNKRO_INLINE void TriangleMeshSet::SetMinimumLevelSize( UInt index, Float size )
{
	assert( index < _levels.Size() );

	if ( index >= _levels.Size() )
		throw lang::OutOfRangeException( index, _levels.Size() );

	_levels[index] = size;
}

SYNKRO_INLINE UInt TriangleMeshSet::GetLevelCount() const
{
	return _levels.Size();
}

SYNKRO_INLINE Float TriangleMeshSet::GetMinimumLevelSize( UInt index ) const
{
	assert( index < _levels.Size() );

	if ( index >= _levels.Size() )
		throw lang::OutOfRangeException( index, _levels.Size() );

	return _levels[index];
}
