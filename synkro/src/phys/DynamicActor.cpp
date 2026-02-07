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
// Purpose: Wrapper dynamic actor.
//=============================================================================
#include "config.h"
#include "DynamicActor.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


DynamicActor::DynamicActor( IPhysicsEnvironment* environment, IDynamicActor* actor, IShape* shape ) :
	_environment( environment ),
	_actor( actor ),
	_shape( shape )
{
}

IPhysicsEnvironment* DynamicActor::GetEnvironment() const
{
	return _environment;
}

IRigidActor* DynamicActor::AsRigid() const
{
	return (IRigidActor*)this;
}

void DynamicActor::SetWorldTransform( const Matrix4x4& transform )
{
	_actor->SetWorldTransform( transform );
}

void DynamicActor::GetWorldTransform( Matrix4x4& transform ) const
{
	_actor->GetWorldTransform( transform );
}

IShape* DynamicActor::GetShape() const
{
	return _shape;
}

void DynamicActor::AddForce( const ForceMode& mode, const Vector3& force )
{
	_actor->AddForce( mode, force );
}

void DynamicActor::AddTorque( const ForceMode& mode, const Vector3& torque )
{
	_actor->AddTorque( mode, torque );
}

void DynamicActor::ClearForce( const ForceMode& mode )
{
	_actor->ClearForce( mode );
}

void DynamicActor::ClearTorque( const ForceMode& mode )
{
	_actor->ClearTorque( mode );
}

void DynamicActor::SetMass( Float mass )
{
	_actor->SetMass( mass );
}

void DynamicActor::SetInertia( const Vector3& inertia )
{
	_actor->SetInertia( inertia );
}

void DynamicActor::SetMaximumLinearVelocity( Float velocity )
{
	_actor->SetMaximumLinearVelocity( velocity );
}

void DynamicActor::SetMaximumAngularVelocity( Float velocity )
{
	_actor->SetMaximumAngularVelocity( velocity );
}

Float DynamicActor::GetMass() const
{
	return _actor->GetMass();
}

void DynamicActor::GetInertia( Vector3& inertia ) const
{
	_actor->GetInertia( inertia );
}

Float DynamicActor::GetMaximumLinearVelocity() const
{
	return _actor->GetMaximumLinearVelocity();
}

Float DynamicActor::GetMaximumAngularVelocity() const
{
	return _actor->GetMaximumAngularVelocity();
}

void DynamicActor::SetLinearVelocity( const Vector3& velocity )
{
	_actor->SetLinearVelocity( velocity );
}

void DynamicActor::SetAngularVelocity( const Vector3& velocity )
{
	_actor->SetAngularVelocity( velocity );
}

void DynamicActor::GetLinearVelocity( Vector3& velocity ) const
{
	_actor->GetLinearVelocity( velocity );
}

void DynamicActor::GetAngularVelocity( Vector3& velocity ) const
{
	_actor->GetAngularVelocity( velocity );
}


} // phys


} // synkro
