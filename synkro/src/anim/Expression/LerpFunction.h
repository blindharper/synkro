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
// Purpose: 'lerp' function.
//==============================================================================
#ifndef _SYNKRO_ANIM_LERPFUNCTION_
#define _SYNKRO_ANIM_LERPFUNCTION_


#include "config.h"
#include "Function.h"
#include "FloatExpression.h"
#include "ColorExpression.h"


namespace synkro
{


namespace anim
{


// 'lerp' function.
class LerpFunction :
	public Function
{
public:
	LerpFunction();

	AnimationDataType										DeduceType( ExpressionList* arguments ) override;
	Expression*												Call( ExpressionList* arguments ) override;

private:
	FloatExpression											_valueFloat;
	ColorExpression											_valueColor;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_LERPFUNCTION_
