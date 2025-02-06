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
// Purpose: Implements logical SELECT query.
//==============================================================================
#ifndef _SYNKRO_DB_SELECTQUERY_
#define _SYNKRO_DB_SELECTQUERY_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/ISelectQuery.h>
#include <db/IDataCursor.h>
#include "BaseDatabaseQueryImpl.h"
#include "BaseDatabaseQuery.h"


namespace synkro
{


namespace db
{


// Logical SELECT query implementation.
class SelectQuery :
	public core::ObjectImpl<ISelectQuery>,
	public BaseDatabaseQueryImpl<BaseDatabaseQuery>
{
public:
	// Constructor.
	SelectQuery( IDataTable* table, ISelectQuery* query );

	// IDatabaseQuery methods.
	void													Execute();
	void													Reset();

	// ISelectQuery methods.
	void													SelectAll();
	void													SelectCount();
	void													SelectUnique( Bool unique );
	void													Select( const lang::String& column );
	void													Sort( const lang::String& column, const SortOrder& order );
	void													SetFilter( IDataFilter* filter );
	IDataFilter*											GetFilter() const;
	IDataCursor*											GetCursor() const;

private:
	P(ISelectQuery)											_query;
	mutable P(IDataCursor)									_cursor;
};


#include "SelectQuery.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_SELECTQUERY_
