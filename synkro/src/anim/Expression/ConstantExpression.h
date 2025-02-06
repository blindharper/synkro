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
#ifndef _SYNKRO_ANIM_CONSTANTEXPRESSION_
#define _SYNKRO_ANIM_CONSTANTEXPRESSION_


#include "config.h"
#include "SimpleExpression.h"
#include "Constant.h"


namespace synkro
{


namespace anim
{


// Constant expression.
class ConstantExpression : 
	public SimpleExpression
{
public:
	ConstantExpression( Constant* value, const Token& token );
	ConstantExpression( const ConstantExpression& other );

	Expression*												Clone( BaseExpressionScript* script ) const;
	void													GetValue( Float* value );

	Constant*												Value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_CONSTANTEXPRESSION_
