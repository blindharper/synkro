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
// Purpose: Defines database table.
//==============================================================================
#ifndef _SYNKRO_DB_IDATATABLE_
#define _SYNKRO_DB_IDATATABLE_


#include "config.h"
#include <core/IObject.h>
#include <db/TableColumn.h>


namespace synkro
{


namespace db
{


/**
 * Data table.
 */
iface IDataTable :
	public core::IObject
{
public:
	/**
	 * Creates an index on this table.
	 * @param name Index name.
	 * @param unique Indicates whether the index is unique.
	 * @param columns Collection of table column descriptions.
	 * @param count Number of columns in the collection.
	 */
	virtual ITableIndex*									CreateIndex( const lang::String& name, Bool unique, const lang::String* columns, UInt count ) = 0;

	/**
	 * Creates INSERT query on this table.
	 * @return Created query.
	 */
	virtual IInsertQuery*									CreateInsertQuery() = 0;

	/**
	 * Creates UPDATE query on this table.
	 * @return Created query.
	 */
	virtual IUpdateQuery*									CreateUpdateQuery() = 0;

	/**
	 * Creates SELECT query on this table.
	 * @return Created query.
	 */
	virtual ISelectQuery*									CreateSelectQuery() = 0;

	/**
	 * Creates DELETE query on this table.
	 * @return Created query.
	 */
	virtual IDeleteQuery*									CreateDeleteQuery() = 0;

	/**
	 * Removes table from the database.
	 * @exception DatabaseException Table is referenced by another table.
	 */
	virtual void											Delete() = 0;

	/**
	 * Retrieves the total number of rows contained in the table.
	 */
	virtual UInt											GetRowCount() = 0;

	/**
	 * Retrieves the total number of columns contained in the table.
	 */
	virtual UInt											GetColumnCount() const = 0;

	/**
	 * Retrieves table column by index.
	 * @param index Index of the column to retrieve.
	 * @param [out] column Requested column.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											GetColumn( UInt index, TableColumn& column ) const = 0;

	/**
	 * Retrieves table column by name.
	 * @param name Column name.
	 * @param [out] column Requested column.
	 * @exception BadArgumentException Unknown column name.
	 */
	virtual void											GetColumn( const lang::String& name, TableColumn& column ) const = 0;

	/**
	 * Retrieves the total number of indexes contained in the table.
	 */
	virtual UInt											GetIndexCount() const = 0;

	/**
	 * Retrieves table index by index.
	 * @param index Index of the table index to retrieve.
	 * @return Requested table index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual ITableIndex*									GetIndex( UInt index ) const = 0;

	/**
	 * Retrieves table index by name.
	 * @param name Table index name.
	 * @return Requested table index, if found, nullptr otherwise.
	 */
	virtual ITableIndex*									GetIndex( const lang::String& name ) const = 0;

	/**
	 * Retrieves table name.
	 */
	virtual lang::String									GetName() const = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_IDATATABLE_
