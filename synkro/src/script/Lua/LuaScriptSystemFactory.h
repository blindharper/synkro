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
// Purpose: Lua scripting system factory.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_LUASCRIPTSYSTEMFACTORY_
#define _SYNKRO_SCRIPT_LUASCRIPTSYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <script/IScriptSystemFactory.h>
#include <script/ScriptSystem.h>
#include "LuaScriptSystem.h"


namespace synkro
{


namespace script
{


// Lua scripting system factory.
SYNKRO_FACTORY_BEGIN( LuaScriptSystemFactory, IScriptSystemFactory, ScriptSystem, ScriptSystem::Lua )
	IScriptSystem*	Create( diag::ILog* log ) { return new LuaScriptSystem(null, log); }
SYNKRO_FACTORY_END()


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_LUASCRIPTSYSTEMFACTORY_
