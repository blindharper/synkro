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
#ifndef _SYNKRO_ANIM_METAEXPRESSION_
#define _SYNKRO_ANIM_METAEXPRESSION_


#include "config.h"
#include "Expression.h"


namespace synkro
{


namespace anim
{


// Expression representing object description.
class MetaExpression : 
	public Expression
{
public:
	MetaExpression( ExpressionType type );

	Expression*												Clone( BaseExpressionScript* script ) const;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_METAEXPRESSION_
