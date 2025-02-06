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
// Purpose: Defines SELECT database query.
//==============================================================================
#ifndef _SYNKRO_DB_ISELECTQUERY_
#define _SYNKRO_DB_ISELECTQUERY_


#include "config.h"
#include <db/IDatabaseQuery.h>
#include <db/SortOrder.h>


namespace synkro
{


namespace db
{


/**
 * SELECT query.
 */
iface ISelectQuery :
	public IDatabaseQuery
{
public:
	/**
	 * Indicates that the query should select all database table columns.
	 */
	virtual void											SelectAll() = 0;

	/**
	 * Indicates that the query should return the total number of table records.
	 */
	virtual void											SelectCount() = 0;

	/**
	 * Specifies whether to skip duplicate rows.
	 * @param unique True to select only unique rows, false to select all rows matching filter.
	 */
	virtual void											SelectUnique( Bool unique ) = 0;

	/**
	 * Specifies database table column to select.
	 * @param column Column name.
	 */
	virtual void											Select( const lang::String& column ) = 0;

	/**
	 * Sets records sort order.
	 * @param column Name of the column on which to perform sorting.
	 * @param order Sort order.
	 */
	virtual void											Sort( const lang::String& column, const SortOrder& order ) = 0;

	/**
	 * Sets data filter. Set to null to disable filtering.
	 * @param filter Filter used to select records.
	 */
	virtual void											SetFilter( IDataFilter* filter ) = 0;

	/**
	 * Retrieves data filter.
	 */
	virtual IDataFilter*									GetFilter() const = 0;
	
	/**
	 * Retrieves data cursor. The cursor is available after the query execution.
	 */
	virtual IDataCursor*									GetCursor() const = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_ISELECTQUERY_
