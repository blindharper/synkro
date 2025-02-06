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
// Purpose: Defines database table column.
//==============================================================================
#ifndef _SYNKRO_DB_TABLECOLUMN_
#define _SYNKRO_DB_TABLECOLUMN_


#include "config.h"
#include <lang/DataType.h>


namespace synkro
{


namespace db
{


/** 
 * Database table column.
 */
class SYNKRO_API TableColumn
{
public:
	/**
	 * Creates column with the given properties.
	 * @param name Column name.
	 * @param type Column data type.
	 * @param unique Indicates whether the column data should be unique.
	 * @param nullable Indicates whether the column data can be NULL.
	 * @param primary Indicates whether the column is a part of the primary key.
	 * @param foreignTable Optional foreign table name.
	 * @param foreignColumn Optional foreign table column name.
	 */
	TableColumn( const lang::String& name, const lang::DataType& type, Bool unique, Bool nullable, Bool primary, const lang::String& foreignTable, const lang::String& foreignColumn );

	/**
	 * Creates column with the given properties.
	 * @param name Column name.
	 * @param type Column data type.
	 * @param unique Indicates whether the column data should be unique.
	 * @param nullable Indicates whether the column data can be NULL.
	 * @param primary Indicates whether the column is a part of the primary key.
	 */
	TableColumn( const lang::String& name, const lang::DataType& type, Bool unique, Bool nullable, Bool primary );

	/**
	 * Creates non-key column with the given properties.
	 * @param name Column name.
	 * @param type Column data type.
	 * @param unique Indicates whether the column data should be unique.
	 * @param nullable Indicates whether the column data can be NULL.
	 */
	TableColumn( const lang::String& name, const lang::DataType& type, Bool unique, Bool nullable );

	/**
	 * Creates nullable non-key column with the given properties.
	 * @param name Column name.
	 * @param type Column data type.
	 * @param unique Indicates whether the column data should be unique.
	 */
	TableColumn( const lang::String& name, const lang::DataType& type, Bool unique );

	/**
	 * Creates non-unique nullable non-key column with the given properties.
	 * @param name Column name.
	 * @param type Column data type.
	 */
	TableColumn( const lang::String& name, const lang::DataType& type );

	/** Creates default column. */
	TableColumn();

	/** Column name. */
	lang::String											Name;

	/** Column data type. */
	lang::DataType											Type;

	/** Indicates if the column is unique. */
	Bool													Unique;

	/** Indicates if the column is nullable. */
	Bool													Nullable;

	/** Indicates if the column is a part of primary key. */
	Bool													Primary;

	/** Referenced table name. */
	lang::String											ForeignTable;

	/** Referenced table column name. */
	lang::String											ForeignColumn;
};


} // db


} // synkro


#endif // _SYNKRO_DB_TABLECOLUMN_
