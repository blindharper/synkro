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
#include "config.h"
#include "StaticActor.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


StaticActor::StaticActor( IPhysicsEnvironment* environment, IStaticActor* actor, IShape* shape ) :
	_environment( environment ),
	_actor( actor ),
	_shape( shape )
{
}

IPhysicsEnvironment* StaticActor::GetEnvironment() const
{
	return _environment;
}

IRigidActor* StaticActor::AsRigid() const
{
	return (IRigidActor*)this;
}

void StaticActor::SetWorldTransform( const Matrix4x4& transform )
{
	_actor->SetWorldTransform( transform );
}

void StaticActor::GetWorldTransform( Matrix4x4& transform ) const
{
	_actor->GetWorldTransform( transform );
}

IShape* StaticActor::GetShape() const
{
	return _shape;
}

IRigidBody* StaticActor::AsBody() const
{
	return nullptr;
}


} // phys


} // synkro
