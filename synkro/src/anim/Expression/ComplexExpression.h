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
#ifndef _SYNKRO_ANIM_COMPLEXEXPRESSION_
#define _SYNKRO_ANIM_COMPLEXEXPRESSION_


#include "config.h"
#include "Expression.h"


namespace synkro
{


namespace anim
{


// Abstract calculated expression.
class ComplexExpression : 
	public Expression
{
public:
	ComplexExpression( ExpressionType expressionType, const AnimationDataType& valueType );
	virtual ~ComplexExpression();
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_COMPLEXEXPRESSION_
