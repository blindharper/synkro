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
// Purpose: Defines database system.
//==============================================================================
#ifndef _SYNKRO_DB_IDATABASESYSTEM_
#define _SYNKRO_DB_IDATABASESYSTEM_


#include "config.h"
#include <core/ISystem.h>


namespace synkro
{


namespace db
{


/**
 * Database system.
 */
iface IDatabaseSystem :
	public core::ISystem
{
public:
	/**
	 * Creates database from a stream.
	 * @param stream Data stream.
	 * @return Created database.
	 */
	virtual IDatabase*										CreateDatabase( io::IStream* stream ) = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_IDATABASESYSTEM_
