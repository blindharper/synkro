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
// Purpose: Defines extended expression parameter.
//==============================================================================
#ifndef _SYNKRO_ANIM_EXPRESSIONPARAMEX_
#define _SYNKRO_ANIM_EXPRESSIONPARAMEX_


#include "config.h"
#include <anim/ExpressionParam.h>
#include "Variable.h"


namespace synkro
{


namespace anim
{


// Extended expression parameter.
class ExpressionParamEx :
	public ExpressionParam
{
public:
	// Constructors & destructor.
	ExpressionParamEx( Variable* value );
	ExpressionParamEx();
	~ExpressionParamEx();

	Variable*												Value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_EXPRESSIONPARAMEX_
