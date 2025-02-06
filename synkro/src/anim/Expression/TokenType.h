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
// Purpose: Defines expression token types.
//==============================================================================
#ifndef _SYNKRO_ANIM_TOKENTYPE_
#define _SYNKRO_ANIM_TOKENTYPE_


#include "config.h"


namespace synkro
{


namespace anim
{


// All possible expression tokens.
enum TokenType
{
	TOKEN_NONE = 0,
	TOKEN_SEPARATOR,
	TOKEN_STATEMENT_END,
	TOKEN_DATA_TYPE,
	TOKEN_KEYWORD,
	TOKEN_OPERATOR_ASSIGN,
	TOKEN_OPERATOR_UNARY,
	TOKEN_OPERATOR_BINARY,
	TOKEN_NUMBER,
	TOKEN_CONSTANT,
	TOKEN_PARAMETER,
	TOKEN_VARIABLE,
	TOKEN_FUNCTION,
	TOKEN_IDENTIFIER,
	TOKEN_EXPRESSION_BEGIN,
	TOKEN_EXPRESSION_END,
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_TOKENTYPE_
