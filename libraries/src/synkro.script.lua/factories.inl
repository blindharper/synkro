using namespace synkro::script;

#include <script/Lua/LuaScriptSystemFactory.h>

static LuaScriptSystemFactory _factLuaScriptSystem;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Scripting systems.
	//--------------------------------------------------------------------------
	&_factLuaScriptSystem,
};
