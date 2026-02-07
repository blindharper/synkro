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
// Purpose: PhysX collision shape implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE PhysxShapeImpl<T>::PhysxShapeImpl( physx::PxPhysics* physics, physx::PxGeometry& geometry, IPhysicsMaterial* material )
{
	_shape = physics->createShape( geometry, *AsPhysxBaseMaterial(material)->AsPhysxMaterial(), true );
}

template <class T>
SYNKRO_INLINE PhysxShapeImpl<T>::~PhysxShapeImpl()
{
	_shape->release();
}

template <class T>
SYNKRO_INLINE void PhysxShapeImpl<T>::SetContactOffset( Float offset )
{
	_shape->setContactOffset( offset );
}

template <class T>
SYNKRO_INLINE void PhysxShapeImpl<T>::SetRestOffset( Float offset )
{
	_shape->setRestOffset( offset );
}

template <class T>
SYNKRO_INLINE void PhysxShapeImpl<T>::SetLocalTransform( const math::Matrix4x4& transform )
{
	_shape->setLocalPose( Physx::Convert(transform) );
}

template <class T>
SYNKRO_INLINE Float PhysxShapeImpl<T>::GetContactOffset() const
{
	return _shape->getContactOffset();
}

template <class T>
SYNKRO_INLINE Float PhysxShapeImpl<T>::GetRestOffset() const
{
	return _shape->getRestOffset();
}

template <class T>
SYNKRO_INLINE void PhysxShapeImpl<T>::GetLocalTransform( math::Matrix4x4& transform ) const
{
	physx::PxTransform trans = _shape->getLocalPose();
	math::Matrix4x4 matPosition; matPosition.SetTranslation( math::Vector3(trans.p.x, trans.p.y, trans.p.z) );
	math::Matrix4x4 matOrientation; matOrientation.SetOrientation( math::Quaternion(trans.q.x, trans.q.y, trans.q.z, trans.q.w) );
	transform = matPosition * matOrientation;
}

template <class T>
SYNKRO_INLINE void PhysxShapeImpl<T>::GetTransform( math::Matrix4x4& transform ) const
{
	transform = _transform;
}
