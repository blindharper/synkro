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
// Purpose: Abstract floating-point function.
//==============================================================================
#ifndef _SYNKRO_ANIM_FLOATFUNCTION_
#define _SYNKRO_ANIM_FLOATFUNCTION_


#include "config.h"
#include "Function.h"
#include "FloatExpression.h"


namespace synkro
{


namespace anim
{


// Abstract floating-point function.
class FloatFunction :
	public Function
{
public:
	FloatFunction( const lang::String& name );
	virtual ~FloatFunction();

	AnimationDataType										DeduceType( ExpressionList* arguments ) override;

protected:
	FloatExpression											_value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_FLOATFUNCTION_
