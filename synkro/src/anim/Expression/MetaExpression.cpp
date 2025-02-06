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
// Purpose: Expression representing object description.
//==============================================================================
#include "config.h"
#include "MetaExpression.h"


namespace synkro
{


namespace anim
{


MetaExpression::MetaExpression( ExpressionType type ) :
	Expression( type )
{
}

Expression* MetaExpression::Clone( BaseExpressionScript* script ) const
{
	return nullptr;
}


} // anim


} // synkro
