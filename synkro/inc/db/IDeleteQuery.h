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
// Purpose: Defines DELETE database query.
//==============================================================================
#ifndef _SYNKRO_DB_IDELETEQUERY_
#define _SYNKRO_DB_IDELETEQUERY_


#include "config.h"
#include <db/IDatabaseQuery.h>


namespace synkro
{


namespace db
{


/**
 * DELETE query.
 */
iface IDeleteQuery :
	public IDatabaseQuery
{
public:
	/**
	 * Sets data filter. Set to null to disable filtering.
	 * @param filter Filter used to delete records.
	 */
	virtual void											SetFilter( IDataFilter* filter ) = 0;

	/**
	 * Retrieves data filter.
	 */
	virtual IDataFilter*									GetFilter() const = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_IDELETEQUERY_
