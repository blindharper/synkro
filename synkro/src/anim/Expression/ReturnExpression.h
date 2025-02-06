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
// Purpose: RETURN expression.
//==============================================================================
#ifndef _SYNKRO_ANIM_RETURNEXPRESSION_
#define _SYNKRO_ANIM_RETURNEXPRESSION_


#include "config.h"
#include "ControlExpression.h"
#include "Expression.h"
#include "Token.h"


namespace synkro
{


namespace anim
{


// RETURN expression.
class ReturnExpression : 
	public ControlExpression
{
public:
	ReturnExpression( Expression* value, const Token& tokenValue );
	ReturnExpression( const ReturnExpression& other, BaseExpressionScript* script );
	~ReturnExpression();

	Expression*												Clone( BaseExpressionScript* script ) const;
	Bool													ReferencesVariable( const lang::String& name ) const;
	
	Expression*												Value;
	Token													TokenValue;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_RETURNEXPRESSION_
