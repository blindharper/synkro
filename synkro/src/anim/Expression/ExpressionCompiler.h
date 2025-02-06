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
// Purpose: Expression compiler.
//==============================================================================
#ifndef _SYNKRO_ANIM_EXPRESSIONCOMPILER_
#define _SYNKRO_ANIM_EXPRESSIONCOMPILER_


#include "config.h"
#include "TokenExpression.h"
#include "BinaryExpression.h"
#include "Constant.h"
#include "Function.h"
#include "ParseMode.h"
#include "BaseExpressionScript.h"
#include <anim/IExpressionScript.h>
#include <lang/Formatter.h>
#include <lang/Vector.h>
#include <lang/Stack.h>
#include <lang/Map.h>
#include <internal/Logger.h>


namespace synkro
{


namespace anim
{


// Expression compiler.
class ExpressionCompiler :
	public Logger
{
public:
	// Constructor & destructor.
	ExpressionCompiler( diag::ILog* log );
	~ExpressionCompiler();

	// Methods.
	void													EmitWarning( const lang::String& message );
	void													Compile( BaseExpressionScript* script, const lang::String& text );

private:
	typedef lang::MapPair<lang::String, KeywordType>		KeywordTypeEntry;
	typedef lang::MapPair<lang::String, AnimationDataType>	DataTypeEntry;
	typedef lang::MapPair<lang::String, Constant*>			ConstantEntry;
	typedef lang::MapPair<lang::String, Variable*>			VariableEntry;
	typedef lang::MapPair<lang::String, Function*>			FunctionEntry;
	typedef lang::MapPair<lang::String, Function*>			FunctionEntry;
	typedef lang::MapPair<UInt, UInt>						PriorityEntry;

	lang::Map<lang::String, KeywordType>					_keywords;
	lang::Map<lang::String, AnimationDataType>				_dataTypes;
	lang::Map<lang::String, Constant*>						_constants;
	lang::Map<lang::String, Variable*>						_variables;
	lang::Map<lang::String, Function*>						_functions;
	lang::Map<UInt, UInt>									_operatorPriorities;
	lang::Vector<Expression*>								_garbage;
	lang::Stack<Expression*>								_stack;
	lang::Stack<ParseMode>									_modes;
	lang::String											_abc;
	lang::String											_text;
	lang::Vector<Char>										_buffer;
	UInt													_pos;
	UInt													_line;
	UInt													_symbol;

	void													Init();
	void													RegisterConstant( const lang::String& name, Float value );
	void													RegisterConstant( const lang::String& name, const img::Color& value );
	void													RegisterFunction( Function* func );
	void													Reset();
	void													Cleanup();
	void													Collect( Expression* expression );
	Bool													GetToken( BaseExpressionScript* script, Token& token );
	Bool													GetToken( Char c, Token& token );
	Bool													Return( TokenType type, Token& token );
	Bool													Return( BinaryOperatorType op, Token& token );
	Bool													ReturnToken( BaseExpressionScript* script, const lang::String& text, Bool putBack, Token& token );
	Bool													GetToken( BaseExpressionScript* script, const lang::String& text, Token& token );
	void													PushExpression( Expression* expression );
	KeywordType												ToKeywordType( const lang::String& text ) const;
	AnimationDataType										ToDataType( const lang::String& text ) const;
	Bool													IsConstant( const lang::String& text ) const;
	Bool													IsVariable( const lang::String& text ) const;
	Bool													IsFunction( const lang::String& text ) const;
	Bool													IsNumber( const lang::String& text ) const;
	Bool													IsIdentifierChar( Char c ) const;
	Char													GetChar();
	void													EndStatement( BaseExpressionScript* script );
	void													BeginExpression( const Token& context );
	void													EndExpression( const Token& context );
	void													HandleIdentifier( const Token& name );
	void													HandleFunction( const Token& function );
	ExpressionList*											AssembleExpressionList();
	Expression*												AssembleExpression();
	Expression*												AssembleExpression( Expression* value, Bool& insideParenthesis, TokenType& exitBy );
	BinaryExpression*										DoOperator( BinaryOperatorType op, Expression* right, Bool& insideParenthesis, TokenType& exitBy );
	Expression*												GetLeftExpression( BinaryOperatorType opRight, Bool& insideParenthesis, TokenType& exitBy );
	Expression*												PopValue( const lang::String& error, TokenType type = TOKEN_NONE );
	TokenExpression*										PopToken( const lang::String& error, TokenType type = TOKEN_NONE );
	Expression*												DoPop( const lang::String& error );
	Expression*												PeekExpression();
	Expression*												PopExpression();
	ParseMode												PeekMode();
	ParseMode												PopMode();
	void													Verify( Bool valid, const lang::String& error );
	void													Error( const lang::String& message, UInt line, UInt symbol );
	void													Error( const lang::String& message, const Token& token );
	lang::String											GetBuffer();
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_EXPRESSIONCOMPILER_
