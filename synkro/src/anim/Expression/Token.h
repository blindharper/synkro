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
// Purpose: Defines token.
//==============================================================================
#ifndef _SYNKRO_ANIM_TOKEN_
#define _SYNKRO_ANIM_TOKEN_


#include "config.h"
#include <lang/String.h>
#include <anim/AnimationDataType.h>
#include "TokenType.h"
#include "KeywordType.h"
#include "Variable.h"
#include "BinaryOperatorType.h"
#include "UnaryOperatorType.h"


namespace synkro
{


namespace anim
{


// Token.
class Token
{
public:
	Token( TokenType type, const lang::String& value, UInt line, UInt symbol );
	Token( TokenType type, UInt line, UInt symbol );
	Token( KeywordType type, UInt line, UInt symbol );
	Token( BinaryOperatorType op, UInt line, UInt symbol );
	Token( UnaryOperatorType op, UInt line, UInt symbol );
	Token( Variable* var, UInt line, UInt symbol );
	Token( const AnimationDataType& type, const lang::String& value, UInt line, UInt symbol );
	Token();

	TokenType												Type;
	KeywordType												Keyword;
	BinaryOperatorType										BinaryOperator;
	UnaryOperatorType										UnaryOperator;
	AnimationDataType										DataType;
	lang::String											Value;
	Variable*												Var;
	UInt													Line;
	UInt													Symbol;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_TOKEN_
