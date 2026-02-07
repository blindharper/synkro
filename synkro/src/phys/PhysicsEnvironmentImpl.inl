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
// Purpose: Generic physical environment implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE PhysicsEnvironmentImpl<T>::PhysicsEnvironmentImpl( const lang::String& name ) :
	_name( name )
{
}

template <class T>
SYNKRO_INLINE PhysicsEnvironmentImpl<T>::~PhysicsEnvironmentImpl()
{
}

template <class T>
SYNKRO_INLINE void PhysicsEnvironmentImpl<T>::SetGravity( const math::Vector3& gravity )
{
	_gravity = gravity;
}

template <class T>
SYNKRO_INLINE void PhysicsEnvironmentImpl<T>::GetGravity( math::Vector3& gravity ) const
{
	gravity = _gravity;
}

template <class T>
SYNKRO_INLINE lang::String PhysicsEnvironmentImpl<T>::GetName() const
{
	return _name;
}
