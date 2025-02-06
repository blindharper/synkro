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
#include "config.h"
#include "VariableExpression.h"
#include "BaseExpressionScript.h"


namespace synkro
{


namespace anim
{


VariableExpression::VariableExpression( Variable* var ) :
	ComplexExpression( EXPRESSION_VARIABLE, var->Type ),
	Var( var )
{
}

VariableExpression::VariableExpression( const VariableExpression& other, BaseExpressionScript* script ) :
	ComplexExpression( EXPRESSION_VARIABLE, other.Var->Type ),
	Var( script->CloneVariable(other.Var->Name) )
{
}

void VariableExpression::GetValue( Float* value )
{
	Var->Value->GetValue( value );
}

Expression* VariableExpression::Clone( BaseExpressionScript* script ) const
{
	return new VariableExpression( *this, script );
}

Bool VariableExpression::ReferencesVariable( const lang::String& name ) const
{
	return (Var->Name == name) || Var->Value->ReferencesVariable( name );
}


} // anim


} // synkro
