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
// Purpose: Expression variable.
//==============================================================================
#ifndef _SYNKRO_ANIM_VARIABLE_
#define _SYNKRO_ANIM_VARIABLE_


#include "config.h"
#include "Expression.h"


namespace synkro
{


namespace anim
{


// Variable description.
class Variable
{
public:
	Variable( const lang::String& name, const AnimationDataType& type, Expression* value );
	Variable( const lang::String& name, const AnimationDataType& type );
	~Variable();

	lang::String											Name;
	AnimationDataType										Type;
	Expression*												Value;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_VARIABLE_
