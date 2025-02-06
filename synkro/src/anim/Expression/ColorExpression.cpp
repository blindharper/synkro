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
// Purpose: Color constant expression.
//==============================================================================
#include "config.h"
#include "ColorExpression.h"
#include <internal/Copy.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::img;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


ColorExpression::ColorExpression( const Color& value, const Token& token ) :
	SimpleExpression( EXPRESSION_COLOR, AnimationDataType::Color, token ),
	Value( value )
{
}

ColorExpression::ColorExpression( const ColorExpression& other ) :
	SimpleExpression( EXPRESSION_COLOR, AnimationDataType::Color, other.TokenValue ),
	Value( other.Value.R, other.Value.G, other.Value.B )
{
}

ColorExpression::ColorExpression() :
	SimpleExpression( EXPRESSION_COLOR, AnimationDataType::Color, Token() ),
	Value( Color::Black )
{
}

Expression* ColorExpression::Clone( BaseExpressionScript* script ) const
{
	return new ColorExpression( *this );
}

void ColorExpression::GetValue( Float* value )
{
	Copy( value, &Value.R, 3 );
}


} // anim


} // synkro
