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
// Purpose: Variable expression.
//==============================================================================
#ifndef _SYNKRO_ANIM_VARIABLEEXPRESSION_
#define _SYNKRO_ANIM_VARIABLEEXPRESSION_


#include "config.h"
#include "ComplexExpression.h"
#include "Variable.h"


namespace synkro
{


namespace anim
{


// Variable expression.
class VariableExpression : 
	public ComplexExpression
{
public:
	VariableExpression( Variable* var );
	VariableExpression( const VariableExpression& other, BaseExpressionScript* script );

	void													GetValue( Float* value );
	Expression*												Clone( BaseExpressionScript* script ) const;
	Bool													ReferencesVariable( const lang::String& name ) const;

	Variable*												Var;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_VARIABLEEXPRESSION_
