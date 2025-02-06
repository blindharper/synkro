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
// Purpose: Lua-based script object implementation.
//==============================================================================
#include "config.h"
#include "LuaScriptObject.h"
#include "LuaRestoreStack.h"
#include "Lua.h"
#include <script/ScriptException.h>
#include <script/ScriptMethod.h>
#include <lang/Formatter.h>
#include <lang/Map.h>
#include <io/BinaryReader.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::io;

//------------------------------------------------------------------------------


namespace synkro
{


namespace script
{


class ObjectTable
{
public:
	typedef MapPair<int, LuaScriptObject*> ObjectEntry;

	ObjectTable() :
		Objects( A(ObjectEntry) )
	{
	}
	Map<int, LuaScriptObject*> Objects;
};

class ReferenceTable
{
public:
	typedef MapPair<UInt, int> ReferenceEntry;

	ReferenceTable() :
		References( A(ReferenceEntry) )
	{
	}
	Map<UInt, int> References;
};


static Map<Pointer, ObjectTable >& Objs()
{
	typedef MapPair<Pointer, ObjectTable> TableEntry;

	static Map<Pointer, ObjectTable> _objs( A(TableEntry) );
	return _objs;
}

static Map<UInt, ReferenceTable>& Refs()
{
	typedef MapPair<UInt, ReferenceTable> TableEntry;

	static Map<UInt, ReferenceTable> _refs( A(TableEntry) );
	return _refs;
}

static void RegisterObject( lua_State* lua, int ref, LuaScriptObject* obj )
{
	Pointer key = (Pointer)lua;
	if ( !Objs().ContainsKey(key) )
	{
		Objs()[key] = ObjectTable();
	}
	ObjectTable& tblObj = Objs()[key];
	tblObj.Objects[ref] = obj;

	if ( !Refs().ContainsKey(key) )
	{
		Refs()[key] = ReferenceTable();
	}
	ReferenceTable& tblRef = Refs()[key];
	tblRef.References[obj->ID()] = ref;
}

static void UnregisterObject( lua_State* lua, int ref, LuaScriptObject* obj )
{
	Pointer key = (Pointer)lua;
	if ( Objs().ContainsKey(key) )
	{
		ObjectTable& tbl = Objs()[key];
		tbl.Objects.Remove( ref );
	}
	if ( Refs().ContainsKey(key) )
	{
		ReferenceTable& tbl = Refs()[key];
		tbl.References.Remove( obj->ID() );
	}
}

static LuaScriptObject* Ref2Obj( lua_State* lua, int ref )
{
	Pointer key = (Pointer)lua;
	if ( Objs().ContainsKey(key) )
	{
		ObjectTable& tbl = Objs()[key];
		return tbl.Objects[ref];
	}
	return nullptr;
}

static int Obj2Ref( lua_State* lua, UInt objID )
{
	Pointer key = (Pointer)lua;
	if ( Refs().ContainsKey(key) )
	{
		ReferenceTable& tbl = Refs()[key];
		return tbl.References[objID];
	}
	return -1;
}

// Script function call dispatcher.
static int CallMethod( lua_State* lua )
{
	int type = 0;
	int args = lua_gettop( lua );

	// Make sure the table is passed to the function.
	type = lua_type( lua, 1 );
	if ( type != LUA_TTABLE )
		throw ScriptException( L"Missing 'this' table when calling C++ function from Lua" );

	// get C++ object pointer from Lua 'this' table index 0
	lua_rawgeti( lua, 1, 0 );
	type = lua_type( lua, -1 );
	if ( type != LUA_TLIGHTUSERDATA )
		throw ScriptException( L"Invalid 'object' when calling C++ function from Lua" );

	void* object = (void*)lua_touserdata( lua, -1 );
	lua_getupvalue( lua, -args-2, 1 );
	ScriptMethod* method = (ScriptMethod*)lua_touserdata( lua, -1 );
	
	// Remove 'this' and upvalue from stack.
	lua_pop( lua, 2 );

	// Prepare input and output parameters.
	static Vector<ScriptParam> inParams( A(ScriptParam) );
	UInt inputSignatureLength = CastUInt( strlen(method->InputSignature) );
	if ( inParams.Size() < inputSignatureLength )
	{
		inParams.SetSize( inputSignatureLength );
	}
	static Vector<ScriptParam> outParams( A(ScriptParam) );
	UInt outputSignatureLength = CastUInt( strlen(method->OutputSignature) );
	if ( outParams.Size() < outputSignatureLength )
	{
		outParams.SetSize( outputSignatureLength );
	}

	// Get parameters from stack and pass them to method.
	UInt argCount = lua_gettop( lua ) - 1;
	for ( UInt i = 0; i < inputSignatureLength; ++i )
	{
		int idx = i+2;
		type = (i < argCount) ? lua_type( lua, idx ) : LUA_TNONE;
		switch ( method->InputSignature[i] )
		{
			case 'b':
				if ( (i < argCount) && (type != LUA_TBOOLEAN) )
				{
					throw ScriptException( String::Format(L"Invalid input parameter type '{0}' when calling method '{1}'. Expected boolean.", Lua::ToString(type), method->Name) );
				}
				inParams[i] = ScriptParam( (i < argCount) ? (lua_toboolean(lua, idx) != 0) : false );
				break;

			case 'n':
				if ( (i < argCount) && (type != LUA_TNUMBER) )
				{
					throw ScriptException( String::Format(L"Invalid input parameter type '{0}' when calling method '{1}'. Expected number.", Lua::ToString(type), method->Name) );
				}
				inParams[i] = ScriptParam( (i < argCount) ? lua_tonumber(lua, idx) : 0.0 );
				break;

			case 's':
				if ( (i < argCount) && (type != LUA_TSTRING) )
				{
					throw ScriptException( String::Format(L"Invalid input parameter type '{0}' when calling method '{1}'. Expected string.", Lua::ToString(type), method->Name) );
				}
				inParams[i] = ScriptParam( (i < argCount) ? lua_tostring(lua, idx) : "" );
				break;

			case 'o':
				if ( (i < argCount) && (type != LUA_TTABLE) )
				{
					throw ScriptException( String::Format(L"Invalid input parameter type '{0}' when calling method '{1}'. Expected object.", Lua::ToString(type), method->Name) );
				}
				if ( i < argCount )
				{
					lua_pushvalue( lua, idx );
					inParams[i] = ScriptParam( Ref2Obj(lua, lua_ref(lua, true)) );
				}
				else
				{
					inParams[i] = ScriptParam( (IScriptObject*)nullptr );
				}
				break;

			default:
				throw ScriptException( String::Format(L"Unknown character '{0}' in input signature of method '{1}'.", method->InputSignature[i], method->Name) );
		}
	}

	for ( UInt i = 0; i < outputSignatureLength; ++i )
	{
		switch ( method->OutputSignature[i] )
		{
			case 'b':	outParams[i] = ScriptParam( false ); break;
			case 'n':	outParams[i] = ScriptParam( 0.0 ); break;
			case 's':	outParams[i] = ScriptParam( "" ); break;
			case 'o':	outParams[i] = ScriptParam( (IScriptObject*)nullptr ); break;
			default:	throw ScriptException( String::Format(L"Unknown character '{0}' in output signature of method '{1}'.", method->OutputSignature[i], method->Name) );
		}
	}

	// Call method.
	method->Call( object, inParams.Begin(), outParams.Begin() );
	
	// Push output parameters to stack.
	for ( UInt i = 0; i < outputSignatureLength; ++i )
	{
		switch ( method->OutputSignature[i] )
		{
			case 'b':	lua_pushboolean( lua, outParams[i].GetBoolean() ); break;
			case 'n':	lua_pushnumber( lua, outParams[i].GetNumber() ); break;
			case 's':	lua_pushstring( lua, outParams[i].GetString() ); break;
			case 'o':	lua_getref( lua, Obj2Ref(lua, outParams[i].GetObject()->ID()) ); break;
		}
	}

	return (int)outputSignatureLength;
}

LuaScriptObject::LuaScriptObject( IScriptMachine* machine, lua_State* lua, void* object, IStream* script, const ScriptMethod** methods, UInt methodCount ) :
	ScriptObjectImpl<IScriptObject>( machine ),
	_lua( lua ),
	_ref( 0 )
{
	assert( methods != nullptr );

	// Create new table.
	lua_newtable( _lua );
	_ref = lua_ref( _lua, true );

	// Remember object pointer at index 0.
	{
		LuaRestoreStack rs( _lua );

		lua_getref( _lua, _ref );
		lua_pushlightuserdata( _lua, (void*)object );
		lua_rawseti( _lua, -2, 0 );
	}

	// Register methods.
	AddMethods( methods, methodCount );

	// Register ourselves in lookup tables.
	RegisterObject( _lua, _ref, this );

	// Perform initialization.
	if ( script != nullptr )
	{
		Execute( script );
	}
}

LuaScriptObject::~LuaScriptObject()
{
	UnregisterObject( _lua, _ref, this );
}

void LuaScriptObject::Execute( IStream* script )
{
	// Read script.
	BinaryReader rd( script );
	Vector<Byte> data( A(Byte) );
	rd.ReadBytes( data, script->GetLength() );
	data.Add( 0 );

	lua_getglobal( _lua, "this" );
	int old = lua_ref( _lua, true );

	lua_getref( _lua, _ref );
	lua_setglobal( _lua, "this" );

	// Execute script.
	int ret = luaL_dostring( _lua, (const char*)data.Begin() );

	lua_getref( _lua, old );
	lua_setglobal( _lua, "this" );
	lua_unref( _lua, old );

	// Signal error, if any.
	if ( ret != 0 )
	{
		size_t len;
		const char *msg = lua_tolstring(_lua, -1, &len );
		throw ScriptException( String(msg) );
	}
}

void LuaScriptObject::AddMethods( const ScriptMethod** methods, UInt methodCount )
{
	for ( UInt i = 0; i < methodCount; ++i )
	{
		LuaRestoreStack rs( _lua );

		lua_getref( _lua, _ref );
		lua_pushstring( _lua, methods[i]->Name );
		lua_pushlightuserdata( _lua, (void*)methods[i] );
		lua_pushcclosure( _lua, CallMethod, 1 );
		assert( lua_istable(_lua,-3) );
		lua_settable( _lua, -3 );
	}
}


} // script


} // synkro
