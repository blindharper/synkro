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
// Purpose: Lua-based script system implementation.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_LUASCRIPTSYSTEM_
#define _SYNKRO_SCRIPT_LUASCRIPTSYSTEM_


#include "config.h"
#include <script/ScriptSystemImpl.h>
#include <script/IScriptSystem.h>
#include "Lua.h"


namespace synkro
{


namespace script
{


// Lua-based script system implementation.
class LuaScriptSystem :
	public ScriptSystemImpl<IScriptSystem>
{
public:
	// Constructor & destructor.
	LuaScriptSystem( io::IStreamSystem* streamSystem, diag::ILog* log );
	~LuaScriptSystem();

	// IScriptSystem methods.
	IScriptMachine*											CreateMachine( const lang::String& name );

private:
	io::IStreamSystem*										_streamSystem;
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_LUASCRIPTSYSTEM_
