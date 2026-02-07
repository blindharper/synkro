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
#include <core/ObjectImpl.h>
#include <phys/IPhysicsEnvironment.h>


namespace synkro
{


namespace phys
{


// Wrapper physics environment.
class PhysicsEnvironment :
	public core::ObjectImpl<IPhysicsEnvironment>
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

private:
	P(IPhysicsEnvironment)									_environment;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSICSENVIRONMENT_
