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
#include "config.h"
#include "ControlExpression.h"


namespace synkro
{


namespace anim
{


ControlExpression::ControlExpression( ExpressionType type ) :
	Expression( type )
{
}

ControlExpression::~ControlExpression()
{
}


} // anim


} // synkro
