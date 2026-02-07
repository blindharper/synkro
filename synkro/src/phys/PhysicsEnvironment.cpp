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
	_environment( environment )
{
}

void PhysicsEnvironment::Update( Double delta )
{
	_environment->Update( delta );
}

IStaticActor* PhysicsEnvironment::CreateStaticActor( const Matrix4x4& transform, IShape* shape )
{
	return new StaticActor( _environment, _environment->CreateStaticActor(transform, ((Shape*)shape)->_shape), shape );
}

IDynamicActor* PhysicsEnvironment::CreateDynamicActor( const math::Matrix4x4& transform, IShape* shape, Float density )
{
	return new DynamicActor( _environment, _environment->CreateDynamicActor(transform, ((Shape*)shape)->_shape, density), shape );
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


} // phys


} // synkro
