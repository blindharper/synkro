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
// Purpose: Defines UPDATE database query.
//==============================================================================
#ifndef _SYNKRO_DB_IUPDATEQUERY_
#define _SYNKRO_DB_IUPDATEQUERY_


#include "config.h"
#include <db/IDatabaseQuery.h>
#include <lang/Variant.h>


namespace synkro
{


namespace db
{


/**
 * UPDATE query.
 */
iface IUpdateQuery :
	public IDatabaseQuery
{
public:
	/**
	 * Specifies new cell value.
	 * @param column Column name.
	 * @param value Cell value.
	 */
	virtual void											SetValue( const lang::String& column, const lang::Variant& value ) = 0;

	/**
	 * Sets data filter. Set to null to disable filtering.
	 * @param filter Filter used to update records.
	 */
	virtual void											SetFilter( IDataFilter* filter ) = 0;

	/**
	 * Retrieves data filter.
	 */
	virtual IDataFilter*									GetFilter() const = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_IUPDATEQUERY_
