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
// Purpose: Sqlite-based db system implementation.
//==============================================================================
#include "config.h"
#include "SqliteDatabaseSystem.h"
#include "SqliteDatabase.h"


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::io;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


SqliteDatabaseSystem::SqliteDatabaseSystem( ILog* log ) :
	Logger( log, LogFacility::DatabaseSystem )
{
}

SqliteDatabaseSystem::~SqliteDatabaseSystem()
{
}

Bool SqliteDatabaseSystem::Update( Double delta )
{
	return true;
}

IDatabase* SqliteDatabaseSystem::CreateDatabase( IStream* stream )
{
	return new SqliteDatabase( stream );
}


} // db


} // synkro
