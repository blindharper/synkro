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
// Purpose: Implements expression script.
//==============================================================================
#include "config.h"
#include "ExpressionScript.h"
#include "ReturnStatement.h"
#include "VariableDeclaration.h"
#include "Vector3Expression.h"
#include "Matrix4x4Expression.h"
#include <anim/ExpressionException.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


ExpressionScript::ExpressionScript( ExpressionCompiler* compiler, const String& text ) :
	_compiler( compiler ),
	_params( A(ParamEntry) ),
	_variables( A(VariableEntry) ),
	_statements( A(ExpressionStatement*) ),
	_text( text ),
	_type( AnimationDataType::Unknown )
{
}

ExpressionScript::ExpressionScript( const ExpressionScript& other ) :
	_compiler( other._compiler ),
	_params( A(ParamEntry) ),
	_variables( A(VariableEntry) ),
	_statements( A(ExpressionStatement*) ),
	_text( other._text ),
	_type( other._type )
{
	// Clone parameters.
	MapIterator<String, ExpressionParamEx*> itParam = other._params.Begin();
	MapIterator<String, ExpressionParamEx*> itParamEnd = other._params.End();
	for ( ; itParam != itParamEnd; ++itParam )
	{
		Variable* var = itParam.Value()->Value;
		DeclareParam( var->Name, var->Type );
	}

	// Clone statements.
	for ( UInt i = 0; i < other._statements.Size(); ++i )
	{
		ExpressionStatement* statement = other._statements[i];
		_statements.Add( statement->Clone(this) );
	}
}

ExpressionScript::~ExpressionScript()
{
	// Delete statements.
	for ( UInt i = 0; i < _statements.Size(); ++i )
	{
		delete _statements[i];
	}

	// Delete parameters.
	MapIterator<String, ExpressionParamEx*> itParam = _params.Begin();
	MapIterator<String, ExpressionParamEx*> itParamEnd = _params.End();
	for ( ; itParam != itParamEnd; ++itParam )
	{
		delete itParam.Value();
	}
}

void ExpressionScript::Prepare()
{
	// Build translation tree, if unprepared.
	if ( _type == AnimationDataType::Unknown )
	{
		_compiler->Compile( this, _text );
	}
}

ExpressionParam* ExpressionScript::DeclareParam( const String& name, const AnimationDataType& type )
{
	// Make sure name is unique.
	if ( GetParam(name) != nullptr )
		throw BadArgumentException( L"Parameter already declared", L"name", name );

	// Create parameter.
	ExpressionParamEx* param = new ExpressionParamEx( new Variable(name, type) );
	_params[name] = param;
	return param;
}

void ExpressionScript::SetParamValue( const ExpressionParam* param, Float value )
{
	ValidateParam( param, AnimationDataType::Float );
	ExpressionParamEx* p = (ExpressionParamEx*)param;
	FloatExpression* val = (FloatExpression*)p->Value->Value;
	val->Value = value;
}

void ExpressionScript::SetParamValue( const ExpressionParam* param, const Color& value )
{
	ValidateParam( param, AnimationDataType::Color );
	ExpressionParamEx* p = (ExpressionParamEx*)param;
	ColorExpression* val = (ColorExpression*)p->Value->Value;
	val->Value = value;
}

void ExpressionScript::SetParamValue( const ExpressionParam* param, const Vector3& value )
{
	ValidateParam( param, AnimationDataType::Vector3 );
	ExpressionParamEx* p = (ExpressionParamEx*)param;
	Vector3Expression* val = (Vector3Expression*)p->Value->Value;
	val->Value = value;
}

void ExpressionScript::SetParamValue( const ExpressionParam* param, const Matrix4x4& value )
{
	ValidateParam( param, AnimationDataType::Vector3 );
	ExpressionParamEx* p = (ExpressionParamEx*)param;
	Matrix4x4Expression* val = (Matrix4x4Expression*)p->Value->Value;
	val->Value = value;
}

ExpressionParam* ExpressionScript::GetParam( const String& name ) const
{
	return _params.ContainsKey( name ) ? _params[name] : nullptr;
}

void ExpressionScript::GetParamValue( const ExpressionParam* param, Float& value ) const
{
	ValidateParam( param, AnimationDataType::Float );
	ExpressionParamEx* p = (ExpressionParamEx*)param;
	FloatExpression* val = (FloatExpression*)p->Value->Value;
	value = val->Value;
}

void ExpressionScript::GetParamValue( const ExpressionParam* param, Color& value ) const
{
	ValidateParam( param, AnimationDataType::Color );
	ExpressionParamEx* p = (ExpressionParamEx*)param;
	ColorExpression* val = (ColorExpression*)p->Value->Value;
	value = val->Value;
}

void ExpressionScript::GetParamValue( const ExpressionParam* param, Vector3& value ) const
{
	ValidateParam( param, AnimationDataType::Vector3 );
	ExpressionParamEx* p = (ExpressionParamEx*)param;
	Vector3Expression* val = (Vector3Expression*)p->Value->Value;
	value = val->Value;
}

void ExpressionScript::GetParamValue( const ExpressionParam* param, Matrix4x4& value ) const
{
	ValidateParam( param, AnimationDataType::Vector3 );
	ExpressionParamEx* p = (ExpressionParamEx*)param;
	Matrix4x4Expression* val = (Matrix4x4Expression*)p->Value->Value;
	value = val->Value;
}

void ExpressionScript::Validate()
{
	Vector<VariableDeclaration*> declarations( A(VariableDeclaration*) );
	Vector<VariableDeclaration*> declarationsToRemove( A(VariableDeclaration*) );

	// Find the first 'return' statement and use its data type.
	for ( UInt i = 0; i < _statements.Size(); ++i )
	{
		ExpressionStatement* statement = _statements[i];

		if ( statement->IsDeclaration() )
		{
			VariableDeclaration* decl = (VariableDeclaration*)statement;
			declarations.Add( decl );
		}
		else if ( statement->IsReturn() )
		{
			ReturnStatement* ret = (ReturnStatement*)statement;
			_type = ret->Value->Value->ValueType;

			// Detect unreferenced variables.
			for ( UInt d = 0; d < declarations.Size(); ++d )
			{
				VariableDeclaration* decl = declarations[d];
				if ( !ret->ReferencesVariable(decl->Var->Name) )
				{
					_compiler->EmitWarning( String::Format(L"Unreferenced variable: {0}.", decl->Var->Name) );
					declarationsToRemove.Add( decl );
				}
			}

			// If return statement is not the last, emit warning.
			if ( i != _statements.Size()-1 )
			{
				_compiler->EmitWarning( L"Unreachable code detected" );
			}
			break;
		}
	}

	// Report an error if no return statment found.
	if ( _type == AnimationDataType::Unknown )
		throw ExpressionException( L"No return statement found", 0, 0 );

	// Remove unreferenced variables declarations.
	for ( UInt i = 0; i < declarationsToRemove.Size(); ++i )
	{
		_statements.Remove( declarationsToRemove[i] );
	}
}

void ExpressionScript::DeclareVariable( Variable* var )
{
	// Make sure name is unique.
	if ( _variables.ContainsKey(var->Name) )
		throw ExpressionException( String::Format(L"Variable {0,q} already declared", var->Name), 0, 0 );

	_variables[var->Name] = var;
}

void ExpressionScript::SetReturnValue( Expression* value )
{
	value->GetValue( _value );
}

void ExpressionScript::AddStatement( ExpressionStatement* statement )
{
	_statements.Add( statement );
}

ExpressionParam* ExpressionScript::GetParameter( const String& name ) const
{
	return GetParam( name );
}

Variable* ExpressionScript::CloneVariable( const String& name ) const
{
	// Find variable in parameters.
	ExpressionParamEx* param = (ExpressionParamEx*)GetParam( name );
	if ( param != nullptr )
	{
		return param->Value;
	}
	else
	{
		// Find variable in declarations.
		for ( UInt i = 0; i < _statements.Size(); ++i )
		{
			ExpressionStatement* statement = _statements[i];
			if ( statement->IsDeclaration() )
			{
				VariableDeclaration* decl = (VariableDeclaration*)statement;
				if ( decl->Var->Name == name )
				{
					return decl->Var;
				}
			}
		}
	}
	return nullptr;
}

Bool ExpressionScript::Call( ExpressionStatement* statement ) const
{
	statement->Execute( (BaseExpressionScript*)this );
	return (!statement->IsReturn());
}

void ExpressionScript::Evaluate() const
{
	SynkroProfile( "ExpressionScript.Evaluate" );

	_variables.Clear();
	_statements.Each( *this );
}

void ExpressionScript::ValidateParam( const ExpressionParam* param, const AnimationDataType& type ) const
{
	assert( param != nullptr );
	if ( param == nullptr )
		throw BadArgumentException( L"Parameter is null.", L"param", L"nullptr" );

	ExpressionParamEx* p = (ExpressionParamEx*)param;
	assert( p->Value->Type == type );
	if ( p->Value->Type != type )
		throw InvalidOperationException( L"Invalid parameter value type." );
}


} // anim


} // synkro
