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
// Purpose: Defines database system factory.
//==============================================================================
#ifndef _SYNKRO_DB_IDATABASESYSTEMFACTORY_
#define _SYNKRO_DB_IDATABASESYSTEMFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace db
{


/**
 * Database system factory.
 */
iface IDatabaseSystemFactory :
	public core::IFactory
{
public:
	/**
	 * Creates database system.
	 * @param log Log to write debug messages to.
	 * @return Created database system.
	 */
	virtual IDatabaseSystem*								Create( diag::ILog* log ) = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_IDATABASESYSTEMFACTORY_
