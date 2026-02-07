#include "PhysicsSystemTest.h"
#include <lang/Exception.h>
#include <phys/Physx/PhysxPhysicsSystemFactory.h>

using namespace synkro::lang;
using namespace synkro::mem;
using namespace synkro;

int main( int argc, char* argv[] )
{
	try
	{
		MemoryManager::Initialize( 0, false );
		PhysxPhysicsSystemFactory factPhysicsSys;

		PhysicsSystemTest tst( L"PhysX Physics System Test", &factPhysicsSys );
		tst.Run();
	}
	catch ( Exception& ex )
	{
		Char msg[1024];
		ex.ToString().GetChars( 0, 1024, msg );
		wprintf( L"%s\n", msg );
	}

	return 0;
}
