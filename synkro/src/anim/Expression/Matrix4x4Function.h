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
// Purpose: 4x4 matrix constructor.
//==============================================================================
#ifndef _SYNKRO_ANIM_MATRIX4X4FUNCTION_
#define _SYNKRO_ANIM_MATRIX4X4FUNCTION_


#include "config.h"
#include "Function.h"
#include "Matrix4x4Expression.h"


namespace synkro
{


namespace anim
{


// 4x4 matrix constructor.
class Matrix4x4Function :
	public Function
{
public:
	Matrix4x4Function();

	AnimationDataType										DeduceType( ExpressionList* arguments ) override;
	Expression*												Call( ExpressionList* arguments ) override;

protected:
	Matrix4x4Expression										_value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_MATRIX4X4FUNCTION_
