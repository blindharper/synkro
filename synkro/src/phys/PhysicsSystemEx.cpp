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
#include <config.h>
#include "PhysicsSystemEx.h"
#include "PhysicsMaterial.h"
#include "PhysicsEnvironment.h"
#include "Shape.h"
#include <phys/IPhysicsSystemFactory.h>


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::io;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


PhysicsSystemEx::PhysicsSystemEx( ILog* log ) :
	_factory( nullptr ),
	_environments( A(P(IPhysicsEnvironment)) ),
	Logger( log, LogFacility::PhysicsSystem )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating physics system...") );
}

PhysicsSystemEx::~PhysicsSystemEx()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying physics system...") );
}

Bool PhysicsSystemEx::Update( Double delta )
{
	SynkroProfile( "PhysicsSystemEx.Update" );

	for ( UInt i = 0; i < _environments.Size(); ++i )
	{
		_environments[i]->Update( delta );
	}

	return true;
}

IPhysicsEnvironment* PhysicsSystemEx::CreateEnvironment( const String& name )
{
	IPhysicsEnvironment* environment = new PhysicsEnvironment( _physicsSystem->CreateEnvironment(name) );
	_environments.Add( environment );
	return environment;
}

IPhysicsMaterial* PhysicsSystemEx::CreateMaterial( Float staticFriction, Float dynamicFriction, Float restitution )
{
	return new PhysicsMaterial( _physicsSystem->CreateMaterial(staticFriction, dynamicFriction, restitution) );
}

IShape* PhysicsSystemEx::CreatePlaneShape( IPhysicsMaterial* material, const Vector3& normal, Float distance )
{
	return new Shape( _physicsSystem->CreatePlaneShape(((PhysicsMaterial*)material)->_material, normal, distance) );
}

IShape* PhysicsSystemEx::CreateBoxShape( IPhysicsMaterial* material, Float width, Float depth, Float height )
{
	return new Shape( _physicsSystem->CreateBoxShape(((PhysicsMaterial*)material)->_material, width, depth, height) );
}

void PhysicsSystemEx::Initialize( IPhysicsSystemFactory* factory, Float speed )
{
	if ( factory != _factory )
	{
		_factory = factory;
		_physicsSystem = nullptr;
		_physicsSystem = factory->Create( speed, _log );
	}
}

void PhysicsSystemEx::Finalize()
{
	_environments.Clear();
	_physicsSystem = nullptr;
	_factory = nullptr;
}


} // phys


} // synkro
