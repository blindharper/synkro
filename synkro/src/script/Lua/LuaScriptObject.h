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
#ifndef _SYNKRO_SCRIPT_LUASCRIPTOBJECT_
#define _SYNKRO_SCRIPT_LUASCRIPTOBJECT_


#include "config.h"
#include <script/ScriptObjectImpl.h>
#include <script/IScriptObject.h>
#include "Lua.h"


namespace synkro
{


namespace script
{


// Lua-based script object implementation.
class LuaScriptObject :
	public ScriptObjectImpl<IScriptObject>
{
public:
	// Constructor & destructor.
	LuaScriptObject( IScriptMachine* machine, lua_State* lua, void* object, io::IStream* script, const ScriptMethod** methods, UInt methodCount );
	~LuaScriptObject();

	// IScriptObject methods.
	void													Execute( io::IStream* script );
	void													AddMethods( const ScriptMethod** methods, UInt methodCount );

private:
	friend class LuaScriptMachine;

	lua_State*												_lua;
	int														_ref;
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_LUASCRIPTOBJECT_
