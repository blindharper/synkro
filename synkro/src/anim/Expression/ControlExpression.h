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
// Purpose: Expression representing execution flow.
//==============================================================================
#ifndef _SYNKRO_ANIM_CONTROLEXPRESSION_
#define _SYNKRO_ANIM_CONTROLEXPRESSION_


#include "config.h"
#include "Expression.h"


namespace synkro
{


namespace anim
{


// Expression representing execution flow.
class ControlExpression : 
	public Expression
{
public:
	ControlExpression( ExpressionType type );
	virtual ~ControlExpression();
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_CONTROLEXPRESSION_
