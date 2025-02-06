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
// Purpose: Abstract statement.
//==============================================================================
#ifndef _SYNKRO_ANIM_EXPRESSIONSTATEMENT_
#define _SYNKRO_ANIM_EXPRESSIONSTATEMENT_


#include "config.h"
#include "BaseExpressionScript.h"


namespace synkro
{


namespace anim
{


// Abstract statement.
class ExpressionStatement
{
public:
	virtual ~ExpressionStatement() {};
	virtual void											Execute( BaseExpressionScript* script ) = 0;
	virtual Bool											IsReturn() const { return false; };
	virtual Bool											IsDeclaration() const { return false; };
	virtual ExpressionStatement*							Clone( BaseExpressionScript* script ) const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_EXPRESSIONSTATEMENT_
