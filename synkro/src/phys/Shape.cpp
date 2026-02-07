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
// Purpose: Wrapper collision shape.
//=============================================================================
#include "config.h"
#include "Shape.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace phys
{


Shape::Shape( IShape* shape ) :
	_shape( shape )
{
}

void Shape::SetContactOffset( Float offset )
{
	_shape->SetContactOffset( offset );
}

void Shape::SetRestOffset( Float offset )
{
	_shape->SetRestOffset( offset );
}

void Shape::SetLocalTransform( const Matrix4x4& transform )
{
	_shape->SetLocalTransform( transform );
}

Float Shape::GetContactOffset() const
{
	return _shape->GetContactOffset();
}

Float Shape::GetRestOffset() const
{
	return _shape->GetRestOffset();
}

void Shape::GetLocalTransform( Matrix4x4& transform ) const
{
	_shape->GetLocalTransform( transform );
}

void Shape::GetTransform( Matrix4x4& transform ) const
{
	_shape->GetTransform( transform );
}


} // phys


} // synkro
