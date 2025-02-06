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
#include "config.h"
#include "Token.h"


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


Token::Token( TokenType type, const String& value, UInt line, UInt symbol ) :
	Type( type ),
	Value( value ),
	Line( line ),
	Symbol( symbol )
{
}

Token::Token( TokenType type, UInt line, UInt symbol ) :
	Type( type ),
	Line( line ),
	Symbol( symbol )
{
}

Token::Token( KeywordType type, UInt line, UInt symbol ) :
	Type( TOKEN_KEYWORD ),
	Keyword( type ),
	Line( line ),
	Symbol( symbol )
{
}

Token::Token( BinaryOperatorType op, UInt line, UInt symbol ) :
	Type( TOKEN_OPERATOR_BINARY ),
	BinaryOperator( op ),
	Line( line ),
	Symbol( symbol )
{
}

Token::Token( UnaryOperatorType op, UInt line, UInt symbol ) :
	Type( TOKEN_OPERATOR_UNARY ),
	UnaryOperator( op ),
	Line( line ),
	Symbol( symbol )
{
}

Token::Token( Variable* var, UInt line, UInt symbol ) :
	Type( TOKEN_VARIABLE ),
	Var( var ),
	Value( var->Name ),
	Line( line ),
	Symbol( symbol )
{
}

Token::Token( const AnimationDataType& type, const String& value, UInt line, UInt symbol ) :
	Type( TOKEN_DATA_TYPE ),
	DataType( type ),
	Value( value ),
	Symbol( symbol )
{
}

Token::Token() :
	Type( TOKEN_NONE ),
	Line( 0 ),
	Symbol( 0 )
{
}


} // anim


} // synkro
