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
#include "config.h"
#include "UnaryExpression.h"
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


UnaryExpression::UnaryExpression( UnaryOperatorType op, Expression* operand ) :
	ComplexExpression( EXPRESSION_UNARY, (operand->ValueType == AnimationDataType::Float) ? operand->ValueType : AnimationDataType::Unknown ),
	Operator( op ),
	Operand( operand )
{
}

UnaryExpression::UnaryExpression( const UnaryExpression& other, BaseExpressionScript* script ) :
	ComplexExpression( EXPRESSION_UNARY, (other.Operand->ValueType == AnimationDataType::Float) ? other.Operand->ValueType : AnimationDataType::Unknown ),
	Operator( other.Operator ),
	Operand( other.Operand->Clone(script) )
{
}

UnaryExpression::~UnaryExpression()
{
	SafeDelete( Operand );
}

void UnaryExpression::GetValue( Float* value )
{
	Operand->GetValue( value );
	*value *= -1.0f;
}

Expression* UnaryExpression::Clone( BaseExpressionScript* script ) const
{
	return new UnaryExpression( *this, script );
}

Bool UnaryExpression::ReferencesVariable( const String& name ) const
{
	return Operand->ReferencesVariable( name );
}


} // anim


} // synkro
