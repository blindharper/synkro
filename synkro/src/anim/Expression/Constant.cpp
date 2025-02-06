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
// Purpose: Expression constant.
//==============================================================================
#include "config.h"
#include "Constant.h"
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


Constant::Constant( const String& name, FloatExpression* value ) :
	Name( name ),
	Value( value )
{
}

Constant::Constant( const String& name, ColorExpression* value ) :
	Name( name ),
	Value( value )
{
}

Constant::Constant() :
	Value( nullptr )
{
}

Constant::~Constant()
{
	SafeDelete( Value );
}


} // anim


} // synkro
