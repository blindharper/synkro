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
// Purpose: 'min' function.
//==============================================================================
#include "config.h"
#include "MinFunction.h"
#include <math/Math.h>


//------------------------------------------------------------------------------

using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


MinFunction::MinFunction() :
	FloatFunction( L"min" )
{
	_arguments.Add( AnimationDataType::Float );
}

Expression* MinFunction::Call( ExpressionList* arguments )
{
	Float x = 0.0f; Float y = 0.0f;
	arguments->Get( 0 )->GetValue( &x );
	arguments->Get( 1 )->GetValue( &y );
	_value.Value = Math::Min( x, y );
	return &_value;
}


} // anim


} // synkro
