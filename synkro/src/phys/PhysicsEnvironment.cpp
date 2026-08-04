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
// Purpose: Wrapper physics environment.
//=============================================================================
#include "config.h"
#include "PhysicsEnvironment.h"
#include "StaticActor.h"
#include "DynamicActor.h"
#include "Shape.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


PhysicsEnvironment::PhysicsEnvironment( IPhysicsEnvironment* environment ) :
	_listeners( A(PhysicsListener*) ),
	_actorIds( A(ActorIdEntry) ),
	_environment( environment )
{
}

void PhysicsEnvironment::Update( Double delta )
{
	// Update underlying window.
	_environment->Update( delta );

	// Generate events, if needed.
	if ( !_listeners.IsEmpty() )
	{
		FireAwakeEvents();
		FireSleepEvents();
	}
}

IStaticActor* PhysicsEnvironment::CreateStaticActor( const Matrix4x4& transform, IShape* shape )
{
	return new StaticActor( _environment, _environment->CreateStaticActor(transform, ((Shape*)shape)->_shape), shape );
}

IDynamicActor* PhysicsEnvironment::CreateDynamicActor( const math::Matrix4x4& transform, IShape* shape, Float density )
{
	IDynamicActor* innerActor = _environment->CreateDynamicActor( transform, ((Shape*)shape)->_shape, density );
	IDynamicActor* actor = new DynamicActor( _environment, innerActor, shape );
	_actorIds[innerActor->ID()] = actor;
	return actor;
}

void PhysicsEnvironment::SetGravity( const Vector3& gravity )
{
	_environment->SetGravity( gravity );
}

void PhysicsEnvironment::GetGravity( Vector3& gravity ) const
{
	_environment->GetGravity( gravity );
}

String PhysicsEnvironment::GetName() const
{
	return _environment->GetName();
}

UInt PhysicsEnvironment::GetAwakenActorCount() const
{
	return 0;
}

IDynamicActor* PhysicsEnvironment::GetAwakenActor( UInt index ) const
{
	return nullptr;
}

UInt PhysicsEnvironment::GetPutToSleepActorCount() const
{
	return 0;
}

IDynamicActor* PhysicsEnvironment::GetPutToSleepActor( UInt index ) const
{
	return nullptr;
}

void PhysicsEnvironment::Listen( PhysicsListener* listener )
{
	assert( listener != nullptr );

	if ( !_listeners.Contains(listener) )
	{
		_listeners.Add( listener );
	}
}

void PhysicsEnvironment::FireAwakeEvents()
{
	const UInt actorCount = _environment->GetAwakenActorCount();
	for ( UInt a = 0; a < actorCount; ++a )
	{
		IDynamicActor* innerActor = _environment->GetAwakenActor( a );
		IDynamicActor* actor = _actorIds[innerActor->ID()];
		for ( UInt i = 0; i < _listeners.Size(); ++i )
		{
			_listeners[i]->OnPhysicsActorWake( actor );
		}
	}
}

void PhysicsEnvironment::FireSleepEvents()
{
	const UInt actorCount = _environment->GetPutToSleepActorCount();
	for ( UInt a = 0; a < actorCount; ++a )
	{
		IDynamicActor* innerActor = _environment->GetPutToSleepActor( a );
		IDynamicActor* actor = _actorIds[innerActor->ID()];
		for ( UInt i = 0; i < _listeners.Size(); ++i )
		{
			_listeners[i]->OnPhysicsActorSleep( actor );
		}
	}
}


} // phys


} // synkro
