#include "InputSystemTest.h"
#include <win/Win32/Win32WindowSystemFactory.h>
#include <input/Win32/Win32InputSystemFactory.h>


int main( int argc, char* argv[] )
{
	try
	{
		MemoryManager::Initialize( 0, false );
		Win32WindowSystemFactory factWinSys;
		Win32InputSystemFactory factInputSys;

		InputSystemTest tst( (Pointer)::GetModuleHandle(NULL), L"Win32 Input System Test", &factWinSys, &factInputSys );
		tst.Run();
	}
	catch ( synkro::input::InputException& ex )
	{
		Char msg[1024]; Char det[1024]; Char code[1024];

		ex.Message().GetChars( 0, 1024, msg );
		ex.Details().GetChars( 0, 1024, det );
		ex.Code().GetChars( 0, 1024, code );
		wprintf( L"Input Exception: %s Details: %s. Code: %s\n", msg, det, code );
	}
	catch ( synkro::lang::BadArgumentException& ex )
	{
		Char msg[1024]; Char arg[1024]; Char val[1024];

		ex.Message().GetChars( 0, 1024, msg );
		ex.Argument().GetChars( 0, 1024, arg );
		ex.Value().GetChars( 0, 1024, val );
		wprintf( L"Bad Argument Exception: %s Argument: %s. Value: %s\n", msg, arg, val );
	}
	catch ( synkro::lang::Exception& ex )
	{
		Char msg[1024];
		ex.Message().GetChars( 0, 1024, msg );
		wprintf( L"Exception: %s\n", msg );
	}

	return 0;
}
