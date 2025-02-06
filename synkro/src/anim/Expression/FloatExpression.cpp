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
// Purpose: Floating-point constant expression.
//==============================================================================
#include "config.h"
#include "FloatExpression.h"


namespace synkro
{


namespace anim
{


FloatExpression::FloatExpression( Float value, const Token& token ) :
	SimpleExpression( EXPRESSION_FLOAT, AnimationDataType::Float, token ),
	Value( value )
{
}

FloatExpression::FloatExpression( const FloatExpression& other ) :
	SimpleExpression( EXPRESSION_FLOAT, AnimationDataType::Float, other.TokenValue ),
	Value( other.Value )
{
}

FloatExpression::FloatExpression() :
	SimpleExpression( EXPRESSION_FLOAT, AnimationDataType::Float, Token() ),
	Value( 0.0f )
{
}

Expression* FloatExpression::Clone( BaseExpressionScript* script ) const
{
	return new FloatExpression( *this );
}

void FloatExpression::GetValue( Float* value )
{
	*value = Value;
}


} // anim


} // synkro
