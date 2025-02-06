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
#include "config.h"
#include "ReturnExpression.h"
#include <internal/SafeDelete.h>


namespace synkro
{


namespace anim
{


ReturnExpression::ReturnExpression( Expression* value, const Token& tokenValue ) :
	ControlExpression( EXPRESSION_RETURN ),
	Value( value ),
	TokenValue( tokenValue )
{
}

ReturnExpression::ReturnExpression( const ReturnExpression& other, BaseExpressionScript* script ) :
	ControlExpression( EXPRESSION_RETURN ),
	Value( other.Value->Clone(script) ),
	TokenValue( other.TokenValue )
{
}

ReturnExpression::~ReturnExpression()
{
	SafeDelete( Value );
}

Expression* ReturnExpression::Clone( BaseExpressionScript* script ) const
{
	return new ReturnExpression( *this, script );
}

Bool ReturnExpression::ReferencesVariable( const lang::String& name ) const
{
	return Value->ReferencesVariable( name );
}


} // anim


} // synkro
