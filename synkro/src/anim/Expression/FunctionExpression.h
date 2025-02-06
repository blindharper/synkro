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
// Purpose: Function expression.
//==============================================================================
#ifndef _SYNKRO_ANIM_FUNCTIONEXPRESSION_
#define _SYNKRO_ANIM_FUNCTIONEXPRESSION_


#include "config.h"
#include "ComplexExpression.h"
#include "ExpressionList.h"
#include "Function.h"


namespace synkro
{


namespace anim
{


// Function expression.
class FunctionExpression :
	public ComplexExpression
{
public:
	FunctionExpression( Function* prototype );
	FunctionExpression( const FunctionExpression& other, BaseExpressionScript* script );
	~FunctionExpression();

	void													GetValue( Float* value ) override;
	Expression*												Clone( BaseExpressionScript* script ) const;
	Bool													ReferencesVariable( const lang::String& name ) const;
	void													SetArguments( ExpressionList* arguments );
	
	Function*												Prototype;

private:
	ExpressionList*											_arguments;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_FUNCTIONEXPRESSION_
