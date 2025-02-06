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
#ifndef _SYNKRO_DB_SQLITEDATABASESYSTEM_
#define _SYNKRO_DB_SQLITEDATABASESYSTEM_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/IDatabaseSystem.h>


namespace synkro
{


namespace db
{


// Sqlite-based db system implementation.
class SqliteDatabaseSystem :
	public core::ObjectImpl<IDatabaseSystem>,
	public Logger
{
public:
	// Constructor & destructor.
	SqliteDatabaseSystem( diag::ILog* log );
	~SqliteDatabaseSystem();

	// ISystem methods.
	Bool													Update( Double delta );

	// IDatabaseSystem methods.
	IDatabase*												CreateDatabase( io::IStream* stream );
};


} // db


} // synkro


#endif // _SYNKRO_DB_SQLITEDATABASESYSTEM_
