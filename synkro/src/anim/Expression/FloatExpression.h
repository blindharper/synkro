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
#ifndef _SYNKRO_ANIM_FLOATEXPRESSION_
#define _SYNKRO_ANIM_FLOATEXPRESSION_


#include "config.h"
#include "SimpleExpression.h"


namespace synkro
{


namespace anim
{


// Floating-point constant expression.
class FloatExpression : 
	public SimpleExpression
{
public:
	// Constructors.
	FloatExpression( Float value, const Token& token );
	FloatExpression( const FloatExpression& other );
	FloatExpression();

	Expression*												Clone( BaseExpressionScript* script ) const;
	void													GetValue( Float* value );

	Float													Value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_FLOATEXPRESSION_
