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
// Purpose: Wrapper static actor.
//=============================================================================
#ifndef _SYNKRO_PHYS_STATICACTOR_
#define _SYNKRO_PHYS_STATICACTOR_


#include "config.h"
#include <core/ObjectImpl.h>
#include <phys/IStaticActor.h>
#include <phys/IShape.h>


namespace synkro
{


namespace phys
{


// Wrapper static actor.
class StaticActor :
	public core::ObjectImpl<IStaticActor>
{
public:
	// Constructor.
	StaticActor( IPhysicsEnvironment* environment, IStaticActor* actor, IShape* shape );

	// IActor methods.
	IPhysicsEnvironment*									GetEnvironment() const;
	IRigidActor*											AsRigid() const;

	// IRigidActor methods.
	void													SetWorldTransform( const math::Matrix4x4& transform );
	void													GetWorldTransform( math::Matrix4x4& transform ) const;
	IShape*													GetShape() const;

private:
	IPhysicsEnvironment*									_environment;
	P(IStaticActor)											_actor;
	P(IShape)												_shape;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_STATICACTOR_
