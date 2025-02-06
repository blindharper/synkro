//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: https://synkro.pro Email: mailto:blindharper70@gmail.com
//
// Purpose: Sqlite database system factory.
//==============================================================================
#ifndef _SYNKRO_DB_SQLITEDATABASESYSTEMFACTORY_
#define _SYNKRO_DB_SQLITEDATABASESYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <db/IDatabaseSystemFactory.h>
#include <db/DatabaseSystem.h>
#include "SqliteDatabaseSystem.h"


namespace synkro
{


namespace db
{


// Sqlite database system factory.
SYNKRO_FACTORY_BEGIN( SqliteDatabaseSystemFactory, IDatabaseSystemFactory, DatabaseSystem, DatabaseSystem::Sqlite )
	IDatabaseSystem*	Create( diag::ILog* log ) { return new SqliteDatabaseSystem(log); }
SYNKRO_FACTORY_END()


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITEDATABASESYSTEMFACTORY_
