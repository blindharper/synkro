#include "AudioSystemTest.h"
#include <win/Win32/Win32WindowSystemFactory.h>
#include <audio/Winmm/WinmmAudioSystemFactory.h>


int main( int argc, char* argv[] )
{
	synkro::mem::MemoryManager::Initialize( 0, false );
	Win32WindowSystemFactory factWinSys;
	WinmmAudioSystemFactory factAudioSys;

	AudioSystemTest tst( (Pointer)::GetModuleHandle(NULL), L"Winmm Audio System Test", &factWinSys, &factAudioSys );
	tst.Run();
	return 0;
}
