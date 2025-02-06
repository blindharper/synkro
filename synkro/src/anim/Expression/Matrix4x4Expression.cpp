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
// Purpose: 4x4 matrix expression.
//==============================================================================
#include "config.h"
#include "Matrix4x4Expression.h"
#include <internal/Copy.h>


namespace synkro
{


namespace anim
{


Matrix4x4Expression::Matrix4x4Expression( const Matrix4x4Expression& other ) :
	SimpleExpression( EXPRESSION_MATRIX4X4, AnimationDataType::Matrix4x4, Token() ),
	Value( other.Value )
{

}

Matrix4x4Expression::Matrix4x4Expression() :
	SimpleExpression( EXPRESSION_MATRIX4X4, AnimationDataType::Matrix4x4, Token() ),
	Value( math::Matrix4x4::Identity )
{
}

void Matrix4x4Expression::GetValue( Float* value )
{
	Copy( value, &Value.d[0], 16 );
}

Expression* Matrix4x4Expression::Clone( BaseExpressionScript* script ) const
{
	return new Matrix4x4Expression( *this );
}


} // anim


} // synkro
