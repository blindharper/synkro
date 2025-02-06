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
// Purpose: 3-component vector expression.
//==============================================================================
#include "config.h"
#include "Vector3Expression.h"
#include <internal/Copy.h>


namespace synkro
{


namespace anim
{


Vector3Expression::Vector3Expression( const Vector3Expression& other ) :
	SimpleExpression( EXPRESSION_VECTOR3, AnimationDataType::Vector3, Token() ),
	Value( other.Value )
{
}

Vector3Expression::Vector3Expression() :
	SimpleExpression( EXPRESSION_VECTOR3, AnimationDataType::Vector3, Token() ),
	Value( math::Vector3::Origin )
{
}

void Vector3Expression::GetValue( Float* value )
{
	Copy( value, &Value.x, 3 );
}

Expression* Vector3Expression::Clone( BaseExpressionScript* script ) const
{
	return new Vector3Expression( *this );
}


} // anim


} // synkro
