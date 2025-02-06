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
#include "config.h"
#include "BinaryExpression.h"
#include <anim/ExpressionException.h>
#include <internal/SafeDelete.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


BinaryExpression::BinaryExpression( BinaryOperatorType op, Expression* left, Expression* right ) :
	ComplexExpression( EXPRESSION_BINARY, (left->ValueType == right->ValueType) ? left->ValueType : AnimationDataType::Unknown ),
	Operator( op ),
	Left( left ),
	Right( right )
{
}

BinaryExpression::BinaryExpression( const BinaryExpression& other, BaseExpressionScript* script ) :
	ComplexExpression( EXPRESSION_BINARY, (other.Left->ValueType == other.Right->ValueType) ? other.Left->ValueType : AnimationDataType::Unknown ),
	Operator( other.Operator ),
	Left( other.Left->Clone(script) ),
	Right( other.Right->Clone(script) )
{
}

BinaryExpression::~BinaryExpression()
{
	SafeDelete( Left );
	SafeDelete( Right );
}

void BinaryExpression::GetValue( Float* value )
{
	Float left = 0.0f;
	Float right = 0.0f;

	Left->GetValue( &left );
	Right->GetValue( &right );

	switch ( Operator )
	{
		case BINARY_OPERATOR_ADD:
			*value = left+right;
			break;

		case BINARY_OPERATOR_SUBTRACT:
			*value = left-right;
			break;

		case BINARY_OPERATOR_MULTIPLY:
			*value = left*right;
			break;

		case BINARY_OPERATOR_DIVIDE:
			if ( right == 0.0f )
				throw ExpressionException( L"Division by zero.", 0, 0 );

			*value = left/right;
			break;
	}
}

Expression* BinaryExpression::Clone( BaseExpressionScript* script ) const
{
	return new BinaryExpression( *this, script );
}

Bool BinaryExpression::ReferencesVariable( const String& name ) const
{
	return Left->ReferencesVariable( name ) || Right->ReferencesVariable( name );
}


} // anim


} // synkro
