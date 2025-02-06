
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
// Purpose: Token wrapper.
//==============================================================================
#ifndef _SYNKRO_ANIM_TOKENEXPRESSION_
#define _SYNKRO_ANIM_TOKENEXPRESSION_


#include "config.h"
#include "MetaExpression.h"
#include "Token.h"


namespace synkro
{


namespace anim
{


// Token wrapper.
class TokenExpression : 
	public MetaExpression
{
public:
	TokenExpression( const Token& tokenValue );

	Token													TokenValue;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_TOKENEXPRESSION_
