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
// Purpose: Lua-based script machine implementation.
//==============================================================================
#include "config.h"
#include "LuaScriptMachine.h"
#include "LuaScriptObject.h"
#include <script/ScriptException.h>
#include <io/BinaryReader.h>
#include <io/TextReader.h>


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace script
{


LuaScriptMachine::LuaScriptMachine( const String& name, IStreamSystem* streamSystem, ILog* log ) :
	ScriptMachineImpl<IScriptMachine>( name ),
	Logger( log, LogFacility::ScriptSystem ),
	_lua( 0 )
{
	// Create LUA virtual machine.
	if ( (_lua = lua_open()) == 0 )
		throw ScriptException( L"Failed to initialize LUA." );

	// Initialize standard LUA libraries.
	luaL_openlibs( _lua );
}

LuaScriptMachine::~LuaScriptMachine()
{
	if ( _lua != 0 )
	{
		lua_close( _lua );
		_lua = 0;
	}
}

void LuaScriptMachine::Execute( IStream* script )
{
	TextReader rd( script );
	String text = rd.ReadToEnd();
	Execute( text );
}

void LuaScriptMachine::Execute( const String& script )
{
	// Read script.
	Vector<Byte> data( A(Byte) );
	data.SetSize( script.Length() );
	script.GetBytes( data.Begin(), data.Size() );
	data.Add( 0 );

	// Execute script.
	int ret = luaL_dostring( _lua, (const char*)data.Begin() );

	// Signal error, if any.
	if ( ret != 0 )
	{
		size_t len;
		const char *msg = lua_tolstring(_lua, -1, &len );
		throw ScriptException( String(msg) );
	}
}

IScriptObject* LuaScriptMachine::CreateObject( void* object, IStream* script, const ScriptMethod** methods, UInt methodCount )
{
	return new LuaScriptObject( this, _lua, object, script, methods, methodCount );
}

void LuaScriptMachine::SetContext( IScriptObject* context )
{
	// Call base implementation.
	ScriptMachineImpl<IScriptMachine>::SetContext( context );

	LuaScriptObject* ctx = (LuaScriptObject*)context;
	lua_getref( _lua, ctx->_ref );
	lua_setglobal( _lua, "this" );
}


} // script


} // synkro
