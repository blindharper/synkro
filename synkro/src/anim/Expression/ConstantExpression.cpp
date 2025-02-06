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
// Purpose: Constant expression.
//==============================================================================
#include "config.h"
#include "ConstantExpression.h"


namespace synkro
{


namespace anim
{


ConstantExpression::ConstantExpression( Constant* value, const Token& token ) :
	SimpleExpression( EXPRESSION_CONSTANT, value->Value->ValueType, token ),
	Value( value )
{
}

ConstantExpression::ConstantExpression( const ConstantExpression& other ) :
	SimpleExpression( EXPRESSION_CONSTANT, other.Value->Value->ValueType, other.TokenValue ),
	Value( other.Value )
{
}

Expression* ConstantExpression::Clone( BaseExpressionScript* script ) const
{
	return new ConstantExpression( *this );
}

void ConstantExpression::GetValue( Float* value )
{
	Value->Value->GetValue( value );
}


} // anim


} // synkro
