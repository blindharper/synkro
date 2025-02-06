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
// Purpose: Defines database.
//==============================================================================
#ifndef _SYNKRO_DB_IDATABASE_
#define _SYNKRO_DB_IDATABASE_


#include "config.h"
#include <core/IObject.h>
#include <db/TableColumn.h>


namespace synkro
{


namespace db
{


/**
 * Database.
 */
iface IDatabase :
	public core::IObject
{
public:
	/**
	 * Creates table in the database.
	 * @param name Table name.
	 * @param columns Collection of table column descriptions.
	 * @param count Number of columns in the collection.
	 * @return Created table.
	 */
	virtual IDataTable*										CreateTable( const lang::String& name, const TableColumn* columns, UInt count ) = 0;

	/**
	 * Retrieves the total number of tables contained in the database.
	 */
	virtual UInt											GetTableCount() const = 0;

	/**
	 * Retrieves table by index.
	 * @param index Index of the table to retrieve.
	 * @return Requested table.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IDataTable*										GetTable( UInt index ) const = 0;

	/**
	 * Retrieves table by name.
	 * @param name Table name.
	 * @return Requested table, if found, nullptr otherwise.
	 */
	virtual IDataTable*										GetTable( const lang::String& name ) const = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_IDATABASE_
