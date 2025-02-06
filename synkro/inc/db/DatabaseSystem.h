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
// Purpose: Defines database system types.
//==============================================================================
#ifndef _SYNKRO_DB_DATABASESYSTEM_
#define _SYNKRO_DB_DATABASESYSTEM_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace db
{


/**
 * Database system types.
 */
SYNKRO_ENUM_BEGIN( DatabaseSystem )
	/** Custom database system. */
	SYNKRO_ENUM_CONST( DatabaseSystem, Custom )

	/** Sqlite based database system. */
	SYNKRO_ENUM_CONST( DatabaseSystem, Sqlite )
SYNKRO_ENUM_END()


} // db


} // synkro


#endif // _SYNKRO_DB_DATABASESYSTEM_
