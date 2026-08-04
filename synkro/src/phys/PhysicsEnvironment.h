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
#ifndef _SYNKRO_PHYS_PHYSICSENVIRONMENT_
#define _SYNKRO_PHYS_PHYSICSENVIRONMENT_


#include "config.h"
#include <lang/Map.h>
#include <lang/Vector.h>
#include <core/ObjectImpl.h>
#include <phys/PhysicsListener.h>
#include <phys/IPhysicsEnvironmentEx.h>


namespace synkro
{


namespace phys
{


// Wrapper physics environment.
class PhysicsEnvironment :
	public core::ObjectImpl<IPhysicsEnvironmentEx>
{
public:
	// Constructor.
	PhysicsEnvironment( IPhysicsEnvironment* environment );

	// IPhysicsEnvironment methods.
	void													Update( Double delta );
	IStaticActor*											CreateStaticActor( const math::Matrix4x4& transform, IShape* shape );
	IDynamicActor*											CreateDynamicActor( const math::Matrix4x4& transform, IShape* shape, Float density );
	void													SetGravity( const math::Vector3& gravity );
	void													GetGravity( math::Vector3& gravity ) const;
	lang::String											GetName() const;
	UInt													GetAwakenActorCount() const;
	IDynamicActor*											GetAwakenActor( UInt index ) const;
	UInt													GetPutToSleepActorCount() const;
	IDynamicActor*											GetPutToSleepActor( UInt index ) const;

	// IPhysicsEnvironmentEx methods.
	void													Listen( PhysicsListener* listener );

private:
	typedef lang::MapPair<UInt, IDynamicActor*>				ActorIdEntry;

	lang::Vector<PhysicsListener*>							_listeners;
	lang::Map<UInt, IDynamicActor*>							_actorIds;
	P(IPhysicsEnvironment)									_environment;

	void													FireAwakeEvents();
	void													FireSleepEvents();
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSICSENVIRONMENT_
