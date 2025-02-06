#include "config.h"
#include "Tester.h"
#include <mem/MemoryManager.h>


int main( int argc, char* argv[] )
{
	// Run all registered tests.
	synkro::mem::MemoryManager::Initialize( "synkro.mem", false );
	Tester::RunTests();
	synkro::mem::MemoryManager::SaveReport( "results/tests.mem", false, true );
	return 0;
}
