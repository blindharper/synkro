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
// Purpose: Abstract calculated expression.
//==============================================================================
#include "config.h"
#include "ComplexExpression.h"


namespace synkro
{


namespace anim
{


ComplexExpression::ComplexExpression( ExpressionType expressionType, const AnimationDataType& valueType ) :
	Expression( expressionType, valueType )
{
}

ComplexExpression::~ComplexExpression()
{
}


} // anim


} // synkro
