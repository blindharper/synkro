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
#include "config.h"
#include "ExpressionCompiler.h"
#include "Expression.h"
#include "ExpressionParamEx.h"
#include "TokenExpression.h"
#include "FloatExpression.h"
#include "FunctionExpression.h"
#include "ConstantExpression.h"
#include "ReturnStatement.h"
#include "VariableDeclaration.h"
#include "VariableExpression.h"
#include "UnaryExpression.h"
#include "Identifier.h"
#include "AbsFunction.h"
#include "SignFunction.h"
#include "CeilFunction.h"
#include "FloorFunction.h"
#include "SqrtFunction.h"
#include "ExpFunction.h"
#include "SinFunction.h"
#include "CosFunction.h"
#include "PowFunction.h"
#include "MinFunction.h"
#include "MaxFunction.h"
#include "LerpFunction.h"
#include "ColorFunction.h"
#include "Vector3Function.h"
#include "Matrix4x4Function.h"
#include <math/Math.h>
#include <anim/ExpressionException.h>
#include <mem/OperatorNew.h>
#include <prf/Profiler.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


ExpressionCompiler::ExpressionCompiler( ILog* log ) :
	Logger( log, LogFacility::AnimationSystem ),
	_keywords( A(KeywordTypeEntry) ),
	_dataTypes( A(DataTypeEntry) ),
	_constants( A(ConstantEntry) ),
	_variables( A(VariableEntry) ),
	_functions( A(FunctionEntry) ),
	_operatorPriorities( A(PriorityEntry) ),
	_garbage( A(Expression*) ),
	_stack( A(Expression*) ),
	_modes( A(ParseMode) ),
	_buffer( A(Char) )
{
	Init();
	Reset();
}

ExpressionCompiler::~ExpressionCompiler()
{
	Cleanup();

	MapIterator<String, Constant*> itConstant = _constants.Begin();
	MapIterator<String, Constant*> itConstantEnd = _constants.End();
	for ( ; itConstant != itConstantEnd; ++itConstant )
	{
		delete itConstant.Value();
	}

	MapIterator<String, Function*> itFunction = _functions.Begin();
	MapIterator<String, Function*> itFunctionEnd = _functions.End();
	for ( ; itFunction != itFunctionEnd; ++itFunction )
	{
		delete itFunction.Value();
	}
}

void ExpressionCompiler::EmitWarning( const String& message )
{
	LogWarning( MessagePriority::AboveNormal, message );
}

void ExpressionCompiler::Compile( BaseExpressionScript* script, const String& text )
{
	SynkroProfile( "ExpressionCompiler.Compile" );

	LogInfo( MessagePriority::Normal, Formatter::Format(L"Compiling script {0,q}", text) );

	assert( text.Length() > 0 );
	if ( text.Length() == 0 )
		throw Exception( L"Script is empty." );

	Reset();
	_text = text;

	Token token;
	TokenExpression* tokenExp = nullptr;
	while ( GetToken(script, token) )
	{
		switch ( token.Type )
		{
			case TOKEN_NUMBER:
				PushExpression( new FloatExpression(token.Value.ToDecimal(), token) );
				break;

			case TOKEN_VARIABLE:
				PushExpression( new VariableExpression(token.Var) );
				break;

			case TOKEN_CONSTANT:
				PushExpression( new ConstantExpression(_constants[token.Value], token) );
				break;

			case TOKEN_IDENTIFIER:
				HandleIdentifier( token );
				break;

			case TOKEN_KEYWORD:
				tokenExp = new TokenExpression( token );
				Collect( tokenExp );
				PushExpression( tokenExp );
				break;

			case TOKEN_STATEMENT_END:
				EndStatement( script );
				break;

			case TOKEN_EXPRESSION_BEGIN:
				BeginExpression( token );
				break;

			case TOKEN_EXPRESSION_END:
				EndExpression( token );
				break;

			case TOKEN_FUNCTION:
				HandleFunction( token );
				break;

			case TOKEN_DATA_TYPE:
			case TOKEN_OPERATOR_ASSIGN:
			case TOKEN_OPERATOR_BINARY:
			case TOKEN_SEPARATOR:
				tokenExp = new TokenExpression( token );
				Collect( tokenExp );
				PushExpression( tokenExp );
				break;

			default:
				// This should never happen.
				Error( String::Format(L"Unexpected token: {0,q}", token.Value), token );
		}
	}

	// Let the script determine its data type.
	script->Validate();

	LogInfo( MessagePriority::Normal, Formatter::Format(L"Script successfully compiled.") );
}

void ExpressionCompiler::Init()
{
	_abc = L"_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	// Register keywords.
	_keywords["return"]			= KEYWORD_RETURN;

	// Register data types.
	_dataTypes[L"color"]		= AnimationDataType::Color;
	_dataTypes[L"float"]		= AnimationDataType::Float;
	_dataTypes[L"matrix4x4"]	= AnimationDataType::Matrix4x4;
	_dataTypes[L"vector3"]		= AnimationDataType::Vector3;

	// Register binary operator priorities.
	_operatorPriorities[BINARY_OPERATOR_MULTIPLY]		= 9;
	_operatorPriorities[BINARY_OPERATOR_DIVIDE]			= 9;
	_operatorPriorities[BINARY_OPERATOR_ADD]			= 8;
	_operatorPriorities[BINARY_OPERATOR_SUBTRACT]		= 8;

	// Register numeric constants.
	RegisterConstant( L"E",				Math::E );
	RegisterConstant( L"PI",			Math::Pi );
	RegisterConstant( L"TWO_PI",		Math::TwoPi );
	RegisterConstant( L"HALF_PI",		Math::HalfPi );
	RegisterConstant( L"QUARTER_PI",	Math::QuarterPi );

	// Register color constants.
	Color color; UInt index = 0;
	while ( index != none )
	{
		color = Color::GetNext( index );
		RegisterConstant( color.ToString(), color );
	}

	// Register functions.
	RegisterFunction( new AbsFunction() );
	RegisterFunction( new SignFunction() );
	RegisterFunction( new CeilFunction() );
	RegisterFunction( new FloorFunction() );
	RegisterFunction( new SqrtFunction() );
	RegisterFunction( new ExpFunction() );
	RegisterFunction( new SinFunction() );
	RegisterFunction( new CosFunction() );
	RegisterFunction( new PowFunction() );
	RegisterFunction( new MinFunction() );
	RegisterFunction( new MaxFunction() );
	RegisterFunction( new LerpFunction() );
	RegisterFunction( new ColorFunction() );
	RegisterFunction( new Vector3Function() );
	RegisterFunction( new Matrix4x4Function() );
}

void ExpressionCompiler::RegisterConstant( const String& name, Float value )
{
	_constants[name] = new Constant( name, new FloatExpression(value, Token()) );
}

void ExpressionCompiler::RegisterConstant( const String& name, const Color& value )
{
	_constants[name] = new Constant( name, new ColorExpression(value, Token()) );
}

void ExpressionCompiler::RegisterFunction( Function* func )
{
	_functions[func->Name] = func;
}

void ExpressionCompiler::Reset()
{
	Cleanup();
	_variables.Clear();
	_stack.Clear();
	_modes.Clear();
	_text = String::Empty;
	_buffer.Clear();
	_pos = 0;
	_line = 1;
	_symbol = 0;
}

void ExpressionCompiler::Cleanup()
{
	for ( UInt i = 0; i < _garbage.Size(); ++i )
	{
		delete _garbage[i];
	}
	_garbage.Clear();
}

void ExpressionCompiler::Collect( Expression* expression )
{
	if ( (expression != nullptr) && !_garbage.Contains(expression) )
	{
		_garbage.Add( expression );
	}
}

Bool ExpressionCompiler::GetToken( BaseExpressionScript* script, Token& token )
{
	Char c = L'\0';
	_buffer.Clear();

	// Scan input.
	while ( (c = GetChar()) != L'\0' )
	{
		switch ( c )
		{
			// Assemble identifiers and numbers.
			case L'0': case L'1': case L'2': case L'3': case L'4': case L'5': case L'6': case L'7': case L'8': case L'9':
			case L'A': case L'B': case L'C': case L'D': case L'E': case L'F': case L'G': case L'H': case L'I': case L'J':
			case L'K': case L'L': case L'M': case L'N': case L'O': case L'P': case L'Q': case L'R': case L'S': case L'T':
			case L'U': case L'V': case L'W': case L'X': case L'Y': case L'Z':
			case L'a': case L'b': case L'c': case L'd': case L'e': case L'f': case L'g': case L'h': case L'i': case L'j':
			case L'k': case L'l': case L'm': case L'n': case L'o': case L'p': case L'q': case L'r': case L's': case L't':
			case L'u': case L'v': case L'w': case L'x': case L'y': case L'z':
			case L'.': case L'_':
				_buffer.Add( c );
				break;

			// Return current token, if any.
			case L' ': case L'\t': case L'\r': case L'\n':
				if ( c == L'\r' )
				{
					++_line;
					_symbol = 0;
				}
				if ( ReturnToken(script, GetBuffer(), false, token) )
					return true;
				break;

			// Handle operators.
			default:
				if ( ReturnToken(script, GetBuffer(), true, token) )
					return true;

				// Return operator token.
				return GetToken( c, token );
		}
	}

	return false;
}

Bool ExpressionCompiler::GetToken( Char c, Token& token )
{
	switch ( c )
	{
		case L',':	Return( TOKEN_SEPARATOR, token ); return true;
		case L';':	Return( TOKEN_STATEMENT_END, token ); return true;
		case L'(':	Return( TOKEN_EXPRESSION_BEGIN, token ); return true;
		case L')':	Return( TOKEN_EXPRESSION_END, token ); return true;
		case L'=':	Return( TOKEN_OPERATOR_ASSIGN, token ); return true;
		case L'+':	Return( BINARY_OPERATOR_ADD, token ); return true;
		case L'-':	Return( BINARY_OPERATOR_SUBTRACT, token ); return true;
		case L'*':	Return( BINARY_OPERATOR_MULTIPLY, token ); return true;
		case L'/':	Return( BINARY_OPERATOR_DIVIDE, token ); return true;
		default:	return false;
	}
}

Bool ExpressionCompiler::Return( TokenType type, Token& token )
{
	token = Token( type, _line, _symbol );
	return true;
}

Bool ExpressionCompiler::Return( BinaryOperatorType op, Token& token )
{
	token = Token( op, _line, _symbol );
	return true;
}

Bool ExpressionCompiler::ReturnToken( BaseExpressionScript* script, const String& text, Bool putBack, Token& token )
{
	if ( text.IsEmpty() )
		return false;

	// Return current token back to input stream.
	if ( putBack )
	{
		--_pos;
		--_symbol;
	}

	return GetToken( script, text, token );
}

Bool ExpressionCompiler::GetToken( BaseExpressionScript* script, const String& text, Token& token )
{
	AnimationDataType dataType; KeywordType keyword = KEYWORD_NONE; ExpressionParam* param = nullptr;

	if ( (dataType = ToDataType(text)) != AnimationDataType::Unknown )
	{
		token = Token( dataType, text, _line, _symbol );
	}
	else if ( (keyword = ToKeywordType(text)) != KEYWORD_NONE )
	{
		token = Token( keyword, _line, _symbol );
	}
	else if ( IsConstant(text) )
	{
		token = Token( TOKEN_CONSTANT, text, _line, _symbol );
	}
	else if ( IsVariable(text) )
	{
		token = Token( _variables[text], _line, _symbol );
	}
	else if ( (param = script->GetParameter(text)) != nullptr )
	{
		token = Token( ((ExpressionParamEx*)param)->Value, _line, _symbol );
	}
	else if ( IsFunction(text) )
	{
		token = Token( TOKEN_FUNCTION, text, _line, _symbol );
	}
	else if ( IsNumber(text) )
	{
		token = Token( TOKEN_NUMBER, text, _line, _symbol );
	}
	else if ( !text.IsEmpty() )
	{
		token = Token( TOKEN_IDENTIFIER, text, _line, _symbol-text.Length() );
	}
	else
	{
		return false;
	}

	return true;
}

void ExpressionCompiler::PushExpression( Expression* expression )
{
	if ( expression != nullptr )
	{
		_stack.Push( expression );
	}
}

KeywordType ExpressionCompiler::ToKeywordType( const String& text ) const
{
	return _keywords.ContainsKey(text) ? _keywords[text] : KEYWORD_NONE;
}

AnimationDataType ExpressionCompiler::ToDataType( const String& text ) const
{
	return _dataTypes.ContainsKey(text) ? _dataTypes[text] : AnimationDataType::Unknown;
}

Bool ExpressionCompiler::IsConstant( const String& text ) const
{
	return _constants.ContainsKey( text );
}

Bool ExpressionCompiler::IsVariable( const String& text ) const
{
	return _variables.ContainsKey( text );
}

Bool ExpressionCompiler::IsFunction( const String& text ) const
{
	return _functions.ContainsKey( text );
}

Bool ExpressionCompiler::IsNumber( const String& text ) const
{
	return text.IsDecimal();
}

Bool ExpressionCompiler::IsIdentifierChar( Char c ) const
{
	return _abc.Contains( c );
}

Char ExpressionCompiler::GetChar()
{
	if ( _pos < _text.Length() )
	{
		++_symbol;
		const Char c = _text[_pos++];
		return c;
	}

	return L'\0';
}

void ExpressionCompiler::EndStatement( BaseExpressionScript* script )
{
	// Handle empty statement.
	if ( _stack.Size() == 0 )
	{
		LogWarning( MessagePriority::AboveNormal, Formatter::Format(L"Empty statement detected. Line {0}. Symbol {1}.", _line, _symbol-1) );
		return;
	}

	Expression* exp = nullptr;

	while ( (exp = PopExpression()) != nullptr )
	{
		if ( exp->Type == EXPRESSION_IDENTIFIER )
		{
			Identifier* id = (Identifier*)(MetaExpression*)exp;
			Variable* var = new Variable( id->Name, id->DataType );
			script->AddStatement( new VariableDeclaration( var ) );
			_variables[var->Name] = var;
			Collect( exp );
		}
		else if ( exp->ValueType != AnimationDataType::Unknown )
		{
			Bool insideParenthesis = true;
			TokenType exitBy = TOKEN_NONE;
			Expression* value = AssembleExpression( exp, insideParenthesis, exitBy );
			Expression* exp2 = PeekExpression();
			if ( exp2 == nullptr )
			{
				Collect( value );
			}
			else if ( exp2->Type == EXPRESSION_TOKEN )
			{
				Token token = ((TokenExpression*)(MetaExpression*)exp2)->TokenValue;
				if ( token.Type == TOKEN_KEYWORD )
				{
					if ( token.Keyword == KEYWORD_RETURN )
					{
						script->AddStatement( new ReturnStatement( new ReturnExpression(value, token) ) );
					}
				}
				else if ( token.Type == TOKEN_OPERATOR_ASSIGN )
				{
					PopExpression();
					Expression* exp3 = PeekExpression();
					if ( exp3 != nullptr )
					{
						if ( exp3->Type == EXPRESSION_IDENTIFIER )
						{
							Identifier* id = ((Identifier*)(MetaExpression*)exp3);
							Variable* var = new Variable( id->Name, id->DataType, value );
							script->AddStatement( new VariableDeclaration( var ) );
							_variables[var->Name] = var;
						}
						else
						{
							Error( L"Identifier expected", token );
						}
					}
					else
					{
						Error( L"Identifier expected", token );
					}
				}
			}
			Collect( PopExpression() );
		}
		else if ( exp->Type == EXPRESSION_TOKEN )
		{
			Token token = ((TokenExpression*)(MetaExpression*)exp)->TokenValue;
			if ( token.Type == TOKEN_KEYWORD )
			{
				if ( token.Keyword == KEYWORD_RETURN )
				{
					Error( L"Missing return value", token );
				}
			}
		}
	}
}

void ExpressionCompiler::BeginExpression( const Token& context )
{
	// If we follow a data type, convert it to a function.
	Expression* exp = PeekExpression();
	if ( exp->Type == EXPRESSION_TOKEN )
	{
		TokenExpression* texp = (TokenExpression*)exp;
		if ( texp->TokenValue.Type == TOKEN_DATA_TYPE )
		{
			PopExpression();
			String name = texp->TokenValue.Value;
			if ( IsFunction(name) )
			{
				Function* prototype = _functions[name];
				PushExpression( new FunctionExpression(prototype) );
				_modes.Push( PARSE_MODE_FUNCTION );
			}
			else
			{
				Error( String::Format(L"Unknown function: {0,q}", name), context );
			}
		}
	}

	// Save token expression to stack.
	TokenExpression* tokenExp = new TokenExpression( context );
	Collect( tokenExp );
	PushExpression( tokenExp );
}

void ExpressionCompiler::EndExpression( const Token& context )
{
	ParseMode mode = PeekMode();
	if ( mode == PARSE_MODE_FUNCTION )
	{
		ExpressionList* arguments = AssembleExpressionList();
		FunctionExpression* function = (FunctionExpression*)(ComplexExpression*)PeekExpression();

		// Make sure actual arguments match formal.
		const UInt count = function->Prototype->GetArgumentCount();
		if ( arguments->GetSize() != count )
			Error( String::Format(L"Function {0,q} accepts {1} arguments.", function->Prototype->Name, count), context );

		for ( UInt i = 0; i < count; ++i )
		{
			const AnimationDataType argType = function->Prototype->GetArgumentType( i );
			if ( argType == AnimationDataType::Unknown )
				continue;

			if ( arguments->Get(i)->ValueType != argType )
				Error( String::Format(L"Function {0,q} arguments type mismatch.", function->Prototype->Name), context );
		}

		// Set arguments to be used for function call.
		function->SetArguments( arguments );
		PopMode();

		// See if the function is able to choose the right overload.
		if ( function->ValueType == AnimationDataType::Unknown )
			Error( String::Format(L"Failed to find overload for function {0,q}.", function->Prototype->Name), context );
	}
	else
	{
		Expression* value = AssembleExpression();
		if ( value != nullptr )
		{
			// Save calculated expression to stack.
			PushExpression( value );
		}
		PopMode();
	}
}

void ExpressionCompiler::HandleIdentifier( const Token& name )
{
	TokenExpression* token = nullptr;
	if ( IsVariable(name.Value) || IsConstant(name.Value) )
		token = PopToken( String::Format(L"Token is required before {0,q}", name.Value) );
	else
		token = PopToken( String::Format(L"Data type is required before {0,q}", name.Value) );

	// Combine identifier name with data type.
	if ( token->TokenValue.Type == TOKEN_DATA_TYPE )
	{
		// Save identifier to stack.
		PushExpression( new Identifier(IDENTIFIER_VARIABLE, name.Value, token->TokenValue.DataType) );
	}

	// Report error.
	else
	{
		Error( String::Format(L"Unknown identifier: '{0}'", name.Value), name );
	}
}

void ExpressionCompiler::HandleFunction( const Token& function )
{
	Function* prototype = _functions[function.Value];
	PushExpression( new FunctionExpression(prototype) );
	_modes.Push( PARSE_MODE_FUNCTION );
}

ExpressionList* ExpressionCompiler::AssembleExpressionList()
{
	ExpressionList* list = new ExpressionList();
	Expression* exp = nullptr;

	while ( (exp = PeekExpression()) != nullptr )
	{
		if ( exp->Type == EXPRESSION_TOKEN )
		{
			TokenExpression* texp = (TokenExpression*)exp;
			if ( texp->TokenValue.Type == TOKEN_EXPRESSION_BEGIN )
			{
				PopExpression();
				break;
			}
			else if ( texp->TokenValue.Type == TOKEN_SEPARATOR )
			{
				if ( list->GetSize() == 0 )
				{
					Error( "Expression is expected after ,", texp->TokenValue );
				}
				PopExpression(); // Separator
			}
		}
		else
		{
			Bool insideParenthesis = true;
			TokenType exitBy = TOKEN_NONE;
			PopExpression();
			Expression* expValue = AssembleExpression( exp, insideParenthesis, exitBy );
			list->Prepend( expValue );
			if ( exitBy == TOKEN_SEPARATOR )
				continue;

			if ( exitBy == TOKEN_EXPRESSION_BEGIN )
				break;
		}
	}

	return list;
}

Expression* ExpressionCompiler::AssembleExpression()
{
	Expression* exp = PopExpression();
	Bool insideParenthesis = true;
	TokenType exitBy = TOKEN_NONE;
	return AssembleExpression( exp, insideParenthesis, exitBy );
}

Expression* ExpressionCompiler::AssembleExpression( Expression* value, Bool& insideParenthesis, TokenType& exitBy )
{
	Expression* expr = PeekExpression();
	Expression* expr2 = nullptr;

	if ( (expr != nullptr) && (expr->Type == EXPRESSION_TOKEN) )
	{
		const Token& token = ((TokenExpression*)(MetaExpression*)expr)->TokenValue;
		switch ( token.Type )
		{
			case TOKEN_OPERATOR_UNARY:
				PopExpression();
				expr2 = new UnaryExpression( token.UnaryOperator, value );
				return AssembleExpression( expr2, insideParenthesis, exitBy );

			case TOKEN_OPERATOR_BINARY:
				Collect( expr );
				PopExpression();
				if ( token.BinaryOperator == BINARY_OPERATOR_SUBTRACT )
				{
					// Handle unary minus.
					expr = PeekExpression();
					if ( expr->ValueType == AnimationDataType::Unknown )
					{
						return new UnaryExpression( UNARY_OPERATOR_MINUS, value );
					}
				}
				return DoOperator( token.BinaryOperator, value, insideParenthesis, exitBy );

			case TOKEN_EXPRESSION_BEGIN:
				PopExpression();
				exitBy = TOKEN_EXPRESSION_BEGIN;
				break;

			case TOKEN_KEYWORD:
				exitBy = TOKEN_EXPRESSION_BEGIN;
				break;

			case TOKEN_SEPARATOR:
				PopExpression();
				exitBy = TOKEN_SEPARATOR;
				break;
		}
	}
	else if ( (expr->Type == EXPRESSION_FLOAT) || (expr->Type == EXPRESSION_CONSTANT) || (expr->Type == EXPRESSION_VARIABLE) )
	{
		exitBy = TOKEN_EXPRESSION_BEGIN;
	}
	else if ( expr->Type == EXPRESSION_IDENTIFIER )
	{
		if ( exitBy != TOKEN_SEPARATOR )
		{
			Error( L"Operator expected", 0, 0 );
		}
	}

	return value;
}

BinaryExpression* ExpressionCompiler::DoOperator( BinaryOperatorType op, Expression* right, Bool& insideParenthesis, TokenType& exitBy )
{
	// Get left-side expression.
	Expression* left = GetLeftExpression( op, insideParenthesis, exitBy );
	if ( left == nullptr )
	{
		Error( "Left-side expression is missing.", _line, _symbol );
	}

	// Calculate binary expression.
	BinaryExpression* expr = new BinaryExpression( op, left, right );

	// Make sure expression types are compatible.
	if ( expr->ValueType == AnimationDataType::Unknown )
	{
		Error( L"Incompatible operands.", _line, _symbol );
	}

	if ( insideParenthesis )
	{
		// Return assembled expression.
		Expression* res = AssembleExpression( expr, insideParenthesis, exitBy );
		return (res->Type == EXPRESSION_BINARY) ? (BinaryExpression*)(ComplexExpression*)res : expr;
	}

	return expr;
}

Expression* ExpressionCompiler::GetLeftExpression( BinaryOperatorType opRight, Bool& insideParenthesis, TokenType& exitBy )
{
	Expression* operand = PopValue( L"Left-side operand expected" );

	// Get previous expression.
	Expression* expr = PeekExpression();
	if ( expr == nullptr )
	{
		Error( L"Incomplete expression.", _line, _symbol );
	}

	if ( expr->Type == EXPRESSION_TOKEN )
	{
		const Token& token = ((TokenExpression*)(MetaExpression*)expr)->TokenValue;
		if ( (token.Type == TOKEN_KEYWORD) || (token.Type == TOKEN_OPERATOR_UNARY) || (token.Type == TOKEN_OPERATOR_ASSIGN) )
		{
			return operand;
		}
		else if ( token.Type == TOKEN_EXPRESSION_BEGIN )
		{
			if ( insideParenthesis )
			{
				PopExpression();
				insideParenthesis = false;
			}
			exitBy = TOKEN_EXPRESSION_BEGIN;
			return operand;
		}
		else if ( token.Type == TOKEN_SEPARATOR )
		{
			exitBy = TOKEN_SEPARATOR;
			PopExpression();
			return operand;
		}
		else if ( token.Type == TOKEN_OPERATOR_BINARY )
		{
			if ( _operatorPriorities[opRight] > _operatorPriorities[token.BinaryOperator] )
			{
				return operand;
			}
			else
			{
				PopExpression();
				return DoOperator( token.BinaryOperator, operand, insideParenthesis, exitBy );
			}
		}
	}
	else if ( (expr->Type == EXPRESSION_FLOAT) || (expr->Type == EXPRESSION_CONSTANT) || (expr->Type == EXPRESSION_VARIABLE) )
	{
		exitBy = TOKEN_EXPRESSION_BEGIN;
		insideParenthesis = false;
		return operand;
	}

	Error( L"Illegal expression.", _line, _symbol );
	return nullptr;
}

Expression* ExpressionCompiler::PopValue( const String& error, TokenType type )
{
	Expression* expression = DoPop( error );
	if ( expression->ValueType == AnimationDataType::Unknown )
	{
		if ( !error.IsEmpty() )
			Error( error, _line, _symbol );
	}
	return expression;
}

TokenExpression* ExpressionCompiler::PopToken( const String& error, TokenType type )
{
	Expression* exp = DoPop( error );
	TokenExpression* token = (TokenExpression*)(MetaExpression*)exp;
	Verify( token != nullptr, error );
	Verify( (type == TOKEN_NONE) || (type == token->TokenValue.Type), error );
	return token;
}

Expression* ExpressionCompiler::DoPop( const String& error )
{
	if ( (_stack.Size() == 0) && !error.IsEmpty() )
	{
		Error( error, _line, _symbol );
	}
	Expression* exp = _stack.Top();
	_stack.Pop();
	return exp;
}

Expression* ExpressionCompiler::PeekExpression()
{
	return (_stack.Size() > 0) ? _stack.Top() : nullptr;
}

Expression* ExpressionCompiler::PopExpression()
{
	if ( _stack.Size() > 0 )
	{
		Expression* exp = _stack.Top();
		_stack.Pop();
		return exp;
	}
	return nullptr;
}

ParseMode ExpressionCompiler::PeekMode()
{
	return (_modes.Size() > 0) ? _modes.Top() : PARSE_MODE_NONE;
}

ParseMode ExpressionCompiler::PopMode()
{
	if ( _modes.Size() > 0 )
	{
		ParseMode mode = _modes.Top();
		_modes.Pop();
		return mode;
	}
	return PARSE_MODE_NONE;
}

void ExpressionCompiler::Verify( Bool valid, const String& error )
{
	if ( !valid )
		Error( error, _line, _symbol );
}

void ExpressionCompiler::Error( const String& message, UInt line, UInt symbol )
{
	throw ExpressionException( message, line, symbol );
}

void ExpressionCompiler::Error( const String& message, const Token& token )
{
	Error( message, token.Line, token.Symbol );
}

String ExpressionCompiler::GetBuffer()
{
	if ( _buffer.Size() > 0 )
	{
		if ( _buffer.LastValue() != 0 )
		{
			_buffer.Add( 0 );
		}
		return String( _buffer.Begin() );
	}
	return String::Empty;
}


} // anim


} // synkro
