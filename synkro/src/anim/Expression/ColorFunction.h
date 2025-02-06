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
// Purpose: Color type constructor.
//==============================================================================
#ifndef _SYNKRO_ANIM_COLORFUNCTION_
#define _SYNKRO_ANIM_COLORFUNCTION_


#include "config.h"
#include "Function.h"
#include "ColorExpression.h"


namespace synkro
{


namespace anim
{


// Color type constructor.
class ColorFunction :
	public Function
{
public:
	ColorFunction();

	AnimationDataType										DeduceType( ExpressionList* arguments ) override;
	Expression*												Call( ExpressionList* arguments ) override;

protected:
	ColorExpression											_value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_COLORFUNCTION_
