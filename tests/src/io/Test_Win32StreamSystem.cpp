#include "StreamSystemTest.h"
#include <io/Win32/Win32StreamSystemFactory.h>


int main( int argc, char* argv[] )
{
	MemoryManager::Initialize( 0, false );
	Win32StreamSystemFactory factStreamSys;

	synkro::io::Path path( argv[0] );
	StreamSystemTest tst( path.GetParent(), &factStreamSys );
	tst.Run();
	return 0;
}
