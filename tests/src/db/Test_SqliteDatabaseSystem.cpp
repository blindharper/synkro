#include "DatabaseSystemTest.h"
#include <mem/MemoryManager.h>
#include <db/DatabaseException.h>
#include <db/Sqlite/SqliteDatabaseSystemFactory.h>

using namespace synkro;

int main( int argc, char* argv[] )
{
	try
	{
		mem::MemoryManager::Initialize( 0, false );
		SqliteDatabaseSystemFactory factDatabaseSys;

		DatabaseSystemTest tst( L"Sqlite Database System Test", L"../../data/db", L"test.db", &factDatabaseSys );
		tst.Run();
	}
	catch ( db::DatabaseException& ex )
	{
		Char msg[1024];
		ex.Message().GetChars( 0, 1024, msg );
		wprintf( L"Database Exception: %s\n", msg );
	}
	catch ( lang::Exception& ex )
	{
		Char msg[1024];
		ex.Message().GetChars( 0, 1024, msg );
		wprintf( L"Exception: %s\n", msg );
	}

	return 0;
}
