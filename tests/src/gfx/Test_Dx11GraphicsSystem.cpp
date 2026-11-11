#include "GraphicsSystemTest.h"
#include <input/Di8/Di8InputSystemFactory.h>
#include <io/Win32/Win32StreamSystemFactory.h>
#include <win/Win32/Win32WindowSystemFactory.h>
#include <gfx/Dx11/Dx11GraphicsSystemFactory.h>


int main( int argc, char* argv[] )
{
	try
	{
		synkro::mem::MemoryManager::Initialize( 0, false );
		synkro::core::CallStack::Initialize();
		synkro::io::Win32StreamSystemFactory factStreamSys;
		Win32WindowSystemFactory factWinSys;
		Di8InputSystemFactory factInputSys;
		Dx11GraphicsSystemFactory factGfxSys;

		synkro::io::Path path( argv[0] );
		GraphicsSystemTest tst( path.GetParent(), &factStreamSys, &factWinSys, &factInputSys, &factGfxSys );
		tst.Run();
	}
	catch ( synkro::gfx::GraphicsException& ex )
	{
		Char msg[1024]; Char det[1024]; Char code[1024];

		ex.Message().GetChars( 0, 1024, msg );
		ex.Details().GetChars( 0, 1024, det );
		ex.Code().GetChars( 0, 1024, code );
		wprintf( L"Graphics Exception: %s Details: %s. Code: %s\n", msg, det, code );
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
