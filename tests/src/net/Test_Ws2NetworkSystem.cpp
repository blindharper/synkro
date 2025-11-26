#include "NetworkSystemTest.h"
#include <net/NetworkException.h>
#include <net/Ws2/Ws2NetworkSystemFactory.h>

using namespace synkro;

int main( int argc, char* argv[] )
{
	Char msg[1024];

	try
	{
		MemoryManager::Initialize( 0, false );
		Ws2NetworkSystemFactory factNetworkSys;

		NetworkSystemTest tst( L"Ws2 Network System Test", &factNetworkSys );
		tst.Run();
	}
	catch ( net::NetworkException& ex )
	{
		ex.ToString().GetChars( 0, 1024, msg );
		wprintf( L"Network Exception: %s\n", msg );
	}
	catch ( lang::BadArgumentException& ex )
	{
		ex.ToString().GetChars( 0, 1024, msg );
		wprintf( L"Bad Argument Exception: %s\n", msg );
	}
	catch ( lang::Exception& ex )
	{
		ex.ToString().GetChars( 0, 1024, msg );
		wprintf( L"Exception: %s\n", msg );
	}

	return 0;
}
