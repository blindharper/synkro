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
// Purpose: Expression constant.
//==============================================================================
#ifndef _SYNKRO_ANIM_CONSTANT_
#define _SYNKRO_ANIM_CONSTANT_


#include "config.h"
#include "FloatExpression.h"
#include "ColorExpression.h"


namespace synkro
{


namespace anim
{


// Constant description.
class Constant
{
public:
	Constant( const lang::String& name, FloatExpression* value );
	Constant( const lang::String& name, ColorExpression* value );
	Constant();
	~Constant();

	lang::String											Name;
	SimpleExpression*										Value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_CONSTANT_
