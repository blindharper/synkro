#include "config.h"
#include "Test.h"
#include <mem/StdMemoryManager.h>


//------------------------------------------------------------------------------

using namespace synkro::mem;

//------------------------------------------------------------------------------


class TestStdMemoryManager :
	public Test
{
public:
	TestStdMemoryManager() : Test( "TestStdMemoryManager", 0 ) {}

	void Run()
	{
		void* group1 = StdMemoryManager::GroupCreate( "group1" );
		void* group2 = StdMemoryManager::GroupCreate( "group2" );

		char* p11 = (char*)StdMemoryManager::Allocate( group1, 24 );
		char* p12 = (char*)StdMemoryManager::Allocate( group1, 256 );
		
		Assert( StdMemoryManager::GroupBytesUsed(group1) == 280 );
		Assert( StdMemoryManager::GroupBlocksUsed(group1) == 2 );

		char* p21 = (char*)StdMemoryManager::Allocate( group2, 512 );
		char* p22 = (char*)StdMemoryManager::Allocate( group2, 1024 );
		char* p23 = (char*)StdMemoryManager::Allocate( group2, 64 );
		
		Assert( StdMemoryManager::GroupBytesUsed(group2) == 1600 );
		Assert( StdMemoryManager::GroupBlocksUsed(group2) == 3 );

		StdMemoryManager::Free( p11 );
		StdMemoryManager::Free( p12 );
		Assert( StdMemoryManager::GroupBytesUsed(group1) == 0 );
		Assert( StdMemoryManager::GroupBlocksUsed(group1) == 0 );

		StdMemoryManager::Free( p22 );
		StdMemoryManager::Free( p23 );
		Assert( StdMemoryManager::GroupBytesUsed(group2) == 512 );
		Assert( StdMemoryManager::GroupBlocksUsed(group2) == 1 );

		Assert( StdMemoryManager::BytesTotal() == 1880 );
		Assert( StdMemoryManager::BlocksTotal() == 5 );

		StdMemoryManager::SaveReport( "../../data/mem/StdMemReport.txt", false, true );
	}

} _tst;
