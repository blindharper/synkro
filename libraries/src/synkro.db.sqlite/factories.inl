using namespace synkro::db;

#include <db/Sqlite/SqliteDatabaseSystemFactory.h>

static SqliteDatabaseSystemFactory _factSqliteDatabaseSystem;

static synkro::core::IFactory* _factories[] =
{
	//--------------------------------------------------------------------------
	// Database systems.
	//--------------------------------------------------------------------------
	&_factSqliteDatabaseSystem,
};
