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
// Purpose: 'sqrt' function.
//==============================================================================
#ifndef _SYNKRO_ANIM_SQRTFUNCTION_
#define _SYNKRO_ANIM_SQRTFUNCTION_


#include "config.h"
#include "FloatFunction.h"


namespace synkro
{


namespace anim
{


// 'sqrt' function.
class SqrtFunction :
	public FloatFunction
{
public:
	SqrtFunction();

	Expression*												Call( ExpressionList* arguments ) override;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_SQRTFUNCTION_
