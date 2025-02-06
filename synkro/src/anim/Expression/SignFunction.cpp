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
// Purpose: 'sign' function.
//==============================================================================
#include "config.h"
#include "SignFunction.h"
#include <math/Math.h>


//------------------------------------------------------------------------------

using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


SignFunction::SignFunction() :
	FloatFunction( L"sign" )
{
}

Expression* SignFunction::Call( ExpressionList* arguments )
{
	Float arg = 0.0f;
	arguments->Get( 0 )->GetValue( &arg );
	_value.Value = Math::Sign( arg );
	return &_value;
}


} // anim


} // synkro
