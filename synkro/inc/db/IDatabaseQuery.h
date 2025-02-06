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
// Purpose: Defines abstract database query.
//==============================================================================
#ifndef _SYNKRO_DB_IDATABASEQUERY_
#define _SYNKRO_DB_IDATABASEQUERY_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace db
{


/**
 * Database query.
 */
iface IDatabaseQuery :
	public core::IObject
{
public:
	/**
	 * Performs database operation.
	 */
	virtual void											Execute() = 0;

	/**
	 * Discards all changes made since the query creation.
	 */
	virtual void											Reset() = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_IDATABASEQUERY_
