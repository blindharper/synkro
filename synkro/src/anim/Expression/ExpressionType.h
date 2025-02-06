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
// Purpose: Defines expression type.
//==============================================================================
#ifndef _SYNKRO_ANIM_EXPRESSIONTYPE_
#define _SYNKRO_ANIM_EXPRESSIONTYPE_


#include "config.h"


namespace synkro
{


namespace anim
{


// Expression type.
enum ExpressionType
{
	EXPRESSION_NONE = 0,
	EXPRESSION_RETURN,
	EXPRESSION_TOKEN,
	EXPRESSION_IDENTIFIER,
	EXPRESSION_FLOAT,
	EXPRESSION_COLOR,
	EXPRESSION_VECTOR3,
	EXPRESSION_MATRIX4X4,
	EXPRESSION_CONSTANT,
	EXPRESSION_VARIABLE,
	EXPRESSION_UNARY,
	EXPRESSION_BINARY,
	EXPRESSION_FUNCTION,
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_EXPRESSIONTYPE_
