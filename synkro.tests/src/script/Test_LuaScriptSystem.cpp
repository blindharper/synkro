#include "ScriptSystemTest.h"
#include <script/ScriptException.h>
#include <script/Lua/LuaScriptSystemFactory.h>

using namespace synkro;

int main( int argc, char* argv[] )
{
	try
	{
		MemoryManager::Initialize( 0, false );
		LuaScriptSystemFactory factScriptSys;

		ScriptSystemTest tst( L"LUA Script System Test", "../../data/script/test.lua", &factScriptSys );
		tst.Run();
	}
	catch ( script::ScriptException& ex )
	{
		Char msg[1024];
		ex.ToString().GetChars( 0, 1024, msg );
		wprintf( L"%s\n", msg );
	}
	catch ( lang::Exception& ex )
	{
		Char msg[1024];
		ex.ToString().GetChars( 0, 1024, msg );
		wprintf( L"%s\n", msg );
	}

	return 0;
}
