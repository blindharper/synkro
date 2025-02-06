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
// Purpose: 3-component vector constructor.
//==============================================================================
#ifndef _SYNKRO_ANIM_VECTOR3FUNCTION_
#define _SYNKRO_ANIM_VECTOR3FUNCTION_


#include "config.h"
#include "Function.h"
#include "Vector3Expression.h"


namespace synkro
{


namespace anim
{


// 3-component vector constructor.
class Vector3Function :
	public Function
{
public:
	Vector3Function();

	AnimationDataType										DeduceType( ExpressionList* arguments ) override;
	Expression*												Call( ExpressionList* arguments ) override;

protected:
	Vector3Expression										_value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_VECTOR3FUNCTION_
