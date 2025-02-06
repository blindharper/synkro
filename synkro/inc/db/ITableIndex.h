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
// Purpose: Defines database table index.
//==============================================================================
#ifndef _SYNKRO_DB_ITABLEINDEX_
#define _SYNKRO_DB_ITABLEINDEX_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>


namespace synkro
{


namespace db
{


/**
 * Table index.
 */
iface ITableIndex :
	public core::IObject
{
public:
	/**
	 * Removes index from the table.
	 */
	virtual void											Delete() = 0;

	/**
	 * Retrieves the total number of columns comprising the index.
	 */
	virtual UInt											GetColumnCount() const = 0;

	/**
	 * Retrieves column by index.
	 * @param index Index of the column to retrieve.
	 * @return Requested column name.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual lang::String									GetColumn( UInt index ) const = 0;

	/**
	 * Retrieves owner table.
	 */
	virtual IDataTable*										GetTable() const = 0;

	/**
	 * Retrieves index name.
	 */
	virtual lang::String									GetName() const = 0;

	/**
	 * Retrieves index's unique status.
	 */
	virtual Bool											IsUnique() const = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_ITABLEINDEX_
