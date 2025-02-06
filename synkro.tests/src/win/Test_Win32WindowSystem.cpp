#include "WindowSystemTest.h"
#include <win/Win32/Win32WindowSystemFactory.h>


int main( int argc, char* argv[] )
{
	MemoryManager::Initialize( 0, false );
	Win32WindowSystemFactory factWinSys;

	WindowSystemTest tst( (Pointer)::GetModuleHandle(NULL), L"Win32 Window System Test", &factWinSys );
	tst.Run();
	return 0;
}
