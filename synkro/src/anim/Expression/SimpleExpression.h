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
#ifndef _SYNKRO_ANIM_SIMPLEEXPRESSION_
#define _SYNKRO_ANIM_SIMPLEEXPRESSION_


#include "config.h"
#include "Expression.h"
#include "Token.h"


namespace synkro
{


namespace anim
{


// Expression representing compile-time constant.
class SimpleExpression : 
	public Expression
{
public:
	SimpleExpression( ExpressionType expressionType, const AnimationDataType& valueType, const Token& tokenValue );
	virtual ~SimpleExpression();

	Token													TokenValue;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_SIMPLEEXPRESSION_
