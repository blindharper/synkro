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
// Purpose: Abstract floating-point function.
//==============================================================================
#include "config.h"
#include "FloatFunction.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


FloatFunction::FloatFunction( const String& name ) :
	Function( name ),
	_value( 0.0f, Token() )
{
	_arguments.Add( AnimationDataType::Float );
}

FloatFunction::~FloatFunction()
{
}

AnimationDataType FloatFunction::DeduceType( ExpressionList* arguments )
{
	return AnimationDataType::Float;
}


} // anim


} // synkro
