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
// Purpose: Abstract function description.
//==============================================================================
#ifndef _SYNKRO_ANIM_FUNCTION_
#define _SYNKRO_ANIM_FUNCTION_


#include "config.h"
#include <anim/AnimationDataType.h>
#include "ExpressionList.h"


namespace synkro
{


namespace anim
{


// Abstract function description.
class Function
{
public:
	Function( const lang::String& name );

	UInt													GetArgumentCount() const;
	AnimationDataType										GetArgumentType( UInt index ) const;
	virtual AnimationDataType								DeduceType( ExpressionList* arguments ) = 0;
	virtual Expression*										Call( ExpressionList* arguments ) = 0;

	lang::String											Name;

protected:
	lang::Vector<AnimationDataType>							_arguments;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_FUNCTION_
