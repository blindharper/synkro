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
// Purpose: Expression representing compile-time constant.
//==============================================================================
#include "config.h"
#include "SimpleExpression.h"


namespace synkro
{


namespace anim
{


SimpleExpression::SimpleExpression( ExpressionType expressionType, const AnimationDataType& valueType, const Token& tokenValue ) :
	Expression( expressionType, valueType ),
	TokenValue( tokenValue )
{
}

SimpleExpression::~SimpleExpression()
{
}


} // anim


} // synkro
