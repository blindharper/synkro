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
// Purpose: 'pow' function.
//==============================================================================
#include "config.h"
#include "PowFunction.h"
#include <math/Math.h>


//------------------------------------------------------------------------------

using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


PowFunction::PowFunction() :
	FloatFunction( L"pow" )
{
	_arguments.Add( AnimationDataType::Float );
}

Expression* PowFunction::Call( ExpressionList* arguments )
{
	Float value = 0.0f; Float power = 0.0f;
	arguments->Get( 0 )->GetValue( &value );
	arguments->Get( 1 )->GetValue( &power );
	_value.Value = Math::Pow( value, power );
	return &_value;
}


} // anim


} // synkro
