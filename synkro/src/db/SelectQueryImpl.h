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
// Purpose: Generic SELECT query implementation.
//==============================================================================
#ifndef _SYNKRO_DB_SELECTQUERYIMPL_
#define _SYNKRO_DB_SELECTQUERYIMPL_


#include "config.h"
#include "DatabaseQueryImpl.h"
#include <db/IDataCursor.h>
#include <db/SortOrder.h>
#include <lang/Map.h>
#include <lang/Set.h>


namespace synkro
{


namespace db
{


// Generic SELECT query implementation.
template <class T>
class SelectQueryImpl :
	public DatabaseQueryImpl<T>
{
public:
	// Constructor & destructor.
	SelectQueryImpl( IDataTable* table );
	virtual ~SelectQueryImpl();

	// IDatabaseQuery methods.
	virtual void											Reset();

	// ISelectQuery methods.
	virtual void											SelectAll();
	virtual void											SelectCount();
	virtual void											SelectUnique( Bool unique );
	virtual void											Select( const lang::String& column );
	virtual void											Sort( const lang::String& column, const SortOrder& order );
	virtual void											SetFilter( IDataFilter* filter );
	virtual IDataFilter*									GetFilter() const;
	virtual IDataCursor*									GetCursor() const;

protected:
	typedef lang::SetItem<lang::String>						ColumnEntry;
	typedef lang::MapPair<lang::String, SortOrder>			SortColumnEntry;

	lang::SetCI<lang::String>								_columns;
	lang::MapCI<lang::String, SortOrder>					_sortColumns;
	P(IDataCursor)											_cursor;
	Bool													_unique;
};


#include "SelectQueryImpl.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_SELECTQUERYIMPL_
