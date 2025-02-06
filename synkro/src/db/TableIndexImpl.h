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
// Purpose: Generic database table index implementation.
//==============================================================================
#ifndef _SYNKRO_DB_TABLEINDEXIMPL_
#define _SYNKRO_DB_TABLEINDEXIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/IDataTable.h>
#include <db/DatabaseException.h>
#include <lang/Vector.h>


namespace synkro
{


namespace db
{


// Generic database table index implementation.
template <class T>
class TableIndexImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	TableIndexImpl( IDataTable* table, const lang::String& name, Bool unique, const lang::String* columns, UInt count );
	virtual ~TableIndexImpl();

	// ITableIndex methods.
	virtual UInt											GetColumnCount() const;
	virtual lang::String									GetColumn( UInt index ) const;
	virtual IDataTable*										GetTable() const;
	virtual lang::String									GetName() const;
	virtual Bool											IsUnique() const;

protected:
	lang::Vector<lang::String>								_columns;
	IDataTable*												_table;
	lang::String											_name;
	Bool													_unique;
};


#include "TableIndexImpl.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_TABLEINDEXIMPL_
