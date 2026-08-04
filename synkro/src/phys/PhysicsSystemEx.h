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
// Purpose: Extended physics system.
//==============================================================================
#ifndef _SYNKRO_PHYS_PHYSICSSYSTEMEX_
#define _SYNKRO_PHYS_PHYSICSSYSTEMEX_


#include "config.h"
#include <core/ObjectImpl.h>
#include <lang/Vector.h>
#include <phys/IPhysicsSystemEx.h>
#include <phys/IPhysicsEnvironment.h>


namespace synkro
{


namespace phys
{


// Extended physics system.
class PhysicsSystemEx :
	public core::ObjectImpl<IPhysicsSystemEx>,
	public Logger
{
public:
	// Constructor & destructor.
	PhysicsSystemEx( diag::ILog* log );
	~PhysicsSystemEx();

	// ISystem methods.
	Bool													Update( Double delta );

	// IPhysicsSystem methods.
	IPhysicsEnvironment*									CreateEnvironment( const lang::String& name );
	IPhysicsMaterial*										CreateMaterial( Float staticFriction, Float dynamicFriction, Float restitution );
	IShape*													CreatePlaneShape( IPhysicsMaterial* material, const math::Vector3& normal, Float distance );
	IShape*													CreateBoxShape( IPhysicsMaterial* material, Float width, Float depth, Float height );

	// IPhysicsSystemEx methods.
	ULong													GetEnvironmentCount() const;
	IPhysicsEnvironment*									GetEnvironment( ULong index ) const;
	IPhysicsEnvironment*									GetEnvironment( const lang::String& name ) const;

	// Other methods.
	void													Initialize( IPhysicsSystemFactory* factory, Float speed );
	void													Finalize();

private:
	IPhysicsSystemFactory*									_factory;
	P(IPhysicsSystem)										_physicsSystem;
	lang::Vector<P(IPhysicsEnvironment)>					_environments;
};


#include "PhysicsSystemEx.inl"


} // phys


} // synkro


#endif // _SYNKRO_PHYS_PHYSICSSYSTEMEX_
