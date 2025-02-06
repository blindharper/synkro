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
// Purpose: Unary expression.
//==============================================================================
#ifndef _SYNKRO_ANIM_UNARYEXPRESSION_
#define _SYNKRO_ANIM_UNARYEXPRESSION_


#include "config.h"
#include "ComplexExpression.h"
#include "UnaryOperatorType.h"


namespace synkro
{


namespace anim
{


// Unary expression.
class UnaryExpression :
	public ComplexExpression
{
public:
	UnaryExpression( UnaryOperatorType op, Expression* operand );
	UnaryExpression( const UnaryExpression& other, BaseExpressionScript* script );
	~UnaryExpression();

	void													GetValue( Float* value );
	Expression*												Clone( BaseExpressionScript* script ) const;
	Bool													ReferencesVariable( const lang::String& name ) const;
	
	UnaryOperatorType										Operator;
	Expression*												Operand;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_UNARYEXPRESSION_
