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
// Purpose: Generic physical material implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE PhysicsMaterialImpl<T>::PhysicsMaterialImpl( Float staticFriction, Float dynamicFriction, Float restitution ) :
	_staticFriction( staticFriction ),
	_dynamicFriction( dynamicFriction ),
	_restitution( restitution )
{
}

template <class T>
SYNKRO_INLINE PhysicsMaterialImpl<T>::~PhysicsMaterialImpl()
{
}

template <class T>
SYNKRO_INLINE void PhysicsMaterialImpl<T>::SetStaticFriction( Float friction )
{
	_staticFriction = friction;
}

template <class T>
SYNKRO_INLINE void PhysicsMaterialImpl<T>::SetDynamicFriction( Float friction )
{
	_dynamicFriction = friction;
}

template <class T>
SYNKRO_INLINE void PhysicsMaterialImpl<T>::SetRestitution( Float restitution )
{
	_restitution = restitution;
}

template <class T>
SYNKRO_INLINE Float PhysicsMaterialImpl<T>::GetStaticFriction() const
{
	return _staticFriction;
}

template <class T>
SYNKRO_INLINE Float PhysicsMaterialImpl<T>::GetDynamicFriction() const
{
	return _dynamicFriction;
}

template <class T>
SYNKRO_INLINE Float PhysicsMaterialImpl<T>::GetRestitution() const
{
	return _restitution;
}
