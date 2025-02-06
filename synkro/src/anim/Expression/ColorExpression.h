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
#ifndef _SYNKRO_ANIM_COLOREXPRESSION_
#define _SYNKRO_ANIM_COLOREXPRESSION_


#include "config.h"
#include "SimpleExpression.h"
#include <img/Color.h>


namespace synkro
{


namespace anim
{


// Color constant expression.
class ColorExpression : 
	public SimpleExpression
{
public:
	// Constructors.
	ColorExpression( const img::Color& value, const Token& token );
	ColorExpression( const ColorExpression& other );
	ColorExpression();

	Expression*												Clone( BaseExpressionScript* script ) const;
	void													GetValue( Float* value );

	img::Color												Value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_COLOREXPRESSION_
