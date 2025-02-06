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
// Purpose: Binary expression.
//==============================================================================
#ifndef _SYNKRO_ANIM_BINARYEXPRESSION_
#define _SYNKRO_ANIM_BINARYEXPRESSION_


#include "config.h"
#include "ComplexExpression.h"
#include "BinaryOperatorType.h"


namespace synkro
{


namespace anim
{


// Binary expression.
class BinaryExpression :
	public ComplexExpression
{
public:
	BinaryExpression( BinaryOperatorType op, Expression* left, Expression* right );
	BinaryExpression( const BinaryExpression& other, BaseExpressionScript* script );
	~BinaryExpression();

	void													GetValue( Float* value );
	Expression*												Clone( BaseExpressionScript* script ) const;
	Bool													ReferencesVariable( const lang::String& name ) const;
	
	BinaryOperatorType										Operator;
	Expression*												Left;
	Expression*												Right;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_BINARYEXPRESSION_
