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
#ifndef _SYNKRO_SCRIPT_LUASCRIPTMACHINE_
#define _SYNKRO_SCRIPT_LUASCRIPTMACHINE_


#include "config.h"
#include <script/ScriptMachineImpl.h>
#include <script/IScriptMachine.h>
#include "Lua.h"


namespace synkro
{


namespace script
{


// Lua-based script machine implementation.
class LuaScriptMachine :
	public ScriptMachineImpl<IScriptMachine>,
	public Logger
{
public:
	// Constructor & destructor.
	LuaScriptMachine( const lang::String& name, io::IStreamSystem* streamSystem, diag::ILog* log );
	~LuaScriptMachine();

	// IScriptMachine methods.
	void													Execute( io::IStream* script );
	void													Execute( const lang::String& script );
	IScriptObject*											CreateObject( void* object, io::IStream* script, const ScriptMethod** methods, UInt methodCount );
	void													SetContext( IScriptObject* context );

private:
	lua_State*												_lua;
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_LUASCRIPTMACHINE_
