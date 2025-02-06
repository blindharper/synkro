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
// Purpose: Generic database table implementation.
//==============================================================================
#ifndef _SYNKRO_DB_DATATABLEIMPL_
#define _SYNKRO_DB_DATATABLEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/ITableIndex.h>
#include <db/TableColumn.h>
#include <lang/Map.h>
#include <lang/Vector.h>


namespace synkro
{


namespace db
{


// Generic database table implementation.
template <class T>
class DataTableImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	DataTableImpl( const lang::String& name );
	virtual ~DataTableImpl();

	// IDataTable methods.
	virtual void											Delete();
	virtual UInt											GetColumnCount() const;
	virtual void											GetColumn( UInt index, TableColumn& column ) const;
	virtual void											GetColumn( const lang::String& name, TableColumn& column ) const;
	virtual UInt											GetIndexCount() const;
	virtual ITableIndex*									GetIndex( UInt index ) const;
	virtual ITableIndex*									GetIndex( const lang::String& name ) const;
	virtual lang::String									GetName() const;

protected:
	typedef lang::MapPair<lang::String, UInt>				IndexEntry;

	lang::Vector<TableColumn>								_columns;
	lang::MapCI<lang::String, UInt>							_columnIndices;

	lang::Vector<P(ITableIndex)>							_indexes;
	lang::MapCI<lang::String, UInt>							_indexIndices;

	lang::String											_name;
};


#include "DataTableImpl.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_DATATABLEIMPL_
