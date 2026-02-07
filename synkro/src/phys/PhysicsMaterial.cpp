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
// Purpose: Wrapper physics material.
//=============================================================================
#include "config.h"
#include "PhysicsMaterial.h"


//------------------------------------------------------------------------------

using namespace synkro::core;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


PhysicsMaterial::PhysicsMaterial( IPhysicsMaterial* material ) :
	_material( material )
{
}

void PhysicsMaterial::SetStaticFriction( Float friction )
{
	assert( friction >= 0.0f );

	_material->SetStaticFriction( friction );
}

void PhysicsMaterial::SetDynamicFriction( Float friction )
{
	assert( friction >= 0.0f );

	_material->SetDynamicFriction( friction );
}

void PhysicsMaterial::SetRestitution( Float restitution )
{
	assert( restitution >= 0.0f );

	_material->SetRestitution( restitution );
}

Float PhysicsMaterial::GetStaticFriction() const
{
	return _material->GetStaticFriction();
}

Float PhysicsMaterial::GetDynamicFriction() const
{
	return _material->GetDynamicFriction();
}

Float PhysicsMaterial::GetRestitution() const
{
	return _material->GetRestitution();
}


} // phys


} // synkro
