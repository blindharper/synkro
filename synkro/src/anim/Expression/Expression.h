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
// Purpose: Abstract expression.
//==============================================================================
#ifndef _SYNKRO_ANIM_EXPRESSION_
#define _SYNKRO_ANIM_EXPRESSION_


#include "config.h"
#include <anim/AnimationDataType.h>
#include "ExpressionType.h"


namespace synkro
{


namespace anim
{


class BaseExpressionScript;


// Abstract expression.
class Expression
{
public:
	Expression( ExpressionType type, const AnimationDataType& valueType );
	Expression( ExpressionType type );
	virtual ~Expression();

	virtual void											GetValue( Float* value );
	virtual Expression*										Clone( BaseExpressionScript* script ) const = 0;
	virtual Bool											ReferencesVariable( const lang::String& name ) const;

	ExpressionType											Type;
	AnimationDataType										ValueType;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_EXPRESSION_
