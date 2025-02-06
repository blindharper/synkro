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
// Purpose: Defines script method's parameter.
//==============================================================================
#include "config.h"
#include <script/ScriptParam.h>
#include <script/ScriptException.h>
#include "ScriptObject.h"


namespace synkro
{


namespace script
{


ScriptParam::ScriptParam( Bool value ) :
	Type( ScriptParamType::Boolean ),
	ValueBoolean( value ),
	ValueNumber( 0.0 ),
	ValueString( 0 ),
	ValueObject( nullptr )
{
}

ScriptParam::ScriptParam( Double value ) :
	Type( ScriptParamType::Number ),
	ValueBoolean( false ),
	ValueNumber( value ),
	ValueString( 0 ),
	ValueObject( nullptr )
{
}

ScriptParam::ScriptParam( const char* value ) :
	Type( ScriptParamType::String ),
	ValueBoolean( false ),
	ValueNumber( 0.0 ),
	ValueString( value ),
	ValueObject( nullptr )
{
}

ScriptParam::ScriptParam( IScriptObject* value ) :
	Type( ScriptParamType::Object ),
	ValueBoolean( false ),
	ValueNumber( 0.0 ),
	ValueString( 0 ),
	ValueObject( value )
{
}

ScriptParam::ScriptParam() :
	Type( ScriptParamType::Unknown ),
	ValueBoolean( false ),
	ValueNumber( 0.0 ),
	ValueString( 0 ),
	ValueObject( nullptr )
{
}

void ScriptParam::Set( Bool value )
{
	if ( Type != ScriptParamType::Boolean )
		throw ScriptException( L"Script parameter is not of type Boolean" );

	ValueBoolean = value;
}
	
void ScriptParam::Set( Double value )
{
	if ( Type != ScriptParamType::Number )
		throw ScriptException( L"Script parameter is not of type Number" );

	ValueNumber = value;
}

void ScriptParam::Set( const char* value )
{
	if ( Type != ScriptParamType::String )
		throw ScriptException( L"Script parameter is not of type String" );

	ValueString = value;
}

void ScriptParam::Set( IScriptObject* value )
{
	if ( Type != ScriptParamType::Object )
		throw ScriptException( L"Script parameter is not of type Object" );

	ScriptObject* obj = dynamic_cast<ScriptObject*>( value );
	ValueObject = (obj != nullptr) ? obj->_object : value;
}

Bool ScriptParam::GetBoolean() const
{
	if ( Type != ScriptParamType::Boolean )
		throw ScriptException( L"Script parameter is not of type Boolean" );

	return ValueBoolean;
}

Double ScriptParam::GetNumber() const
{
	if ( Type != ScriptParamType::Number )
		throw ScriptException( L"Script parameter is not of type Number" );

	return ValueNumber;
}

const char* ScriptParam::GetString() const
{
	if ( Type != ScriptParamType::String )
		throw ScriptException( L"Script parameter is not of type String" );

	return ValueString;
}

IScriptObject* ScriptParam::GetObject() const
{
	if ( Type != ScriptParamType::Object )
		throw ScriptException( L"Script parameter is not of type Object" );

	return ValueObject;
}

ScriptParamType ScriptParam::GetType() const
{
	return Type;
}


} // script


} // synkro
