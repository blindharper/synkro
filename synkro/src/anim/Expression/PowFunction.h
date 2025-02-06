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
// Purpose: 'pow' function.
//==============================================================================
#ifndef _SYNKRO_ANIM_POWFUNCTION_
#define _SYNKRO_ANIM_POWFUNCTION_


#include "config.h"
#include "FloatFunction.h"


namespace synkro
{


namespace anim
{


// 'pow' function.
class PowFunction :
	public FloatFunction
{
public:
	PowFunction();

	Expression*												Call( ExpressionList* arguments ) override;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_POWFUNCTION_
