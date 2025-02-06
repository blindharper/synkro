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
#include "config.h"
#include "LuaScriptSystem.h"
#include "LuaScriptMachine.h"


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace script
{


LuaScriptSystem::LuaScriptSystem( IStreamSystem* streamSystem, ILog* log ) :
	ScriptSystemImpl<IScriptSystem>( log ),
	_streamSystem( streamSystem )
{
}

LuaScriptSystem::~LuaScriptSystem()
{
}

IScriptMachine* LuaScriptSystem::CreateMachine( const String& name )
{
	return new LuaScriptMachine( name, _streamSystem, _log );
}


} // script


} // synkro
