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
#include "config.h"
#include "TokenExpression.h"


namespace synkro
{


namespace anim
{


TokenExpression::TokenExpression( const Token& tokenValue ) :
	MetaExpression( EXPRESSION_TOKEN ),
	TokenValue( tokenValue )
{
}


} // anim


} // synkro
