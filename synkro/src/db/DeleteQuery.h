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
// Purpose: Implements logical DELETE query.
//==============================================================================
#ifndef _SYNKRO_DB_DELETEQUERY_
#define _SYNKRO_DB_DELETEQUERY_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/IDeleteQuery.h>
#include "BaseDatabaseQueryImpl.h"
#include "BaseDatabaseQuery.h"


namespace synkro
{


namespace db
{


// Logical DELETE query implementation.
class DeleteQuery :
	public core::ObjectImpl<IDeleteQuery>,
	public BaseDatabaseQueryImpl<BaseDatabaseQuery>
{
public:
	// Constructor.
	DeleteQuery( IDataTable* table, IDeleteQuery* query );

	// IDatabaseQuery methods.
	void													Execute();
	void													Reset();

	// IDeleteQuery methods.
	void													SetFilter( IDataFilter* filter );
	IDataFilter*											GetFilter() const;

private:
	P(IDeleteQuery)											_query;
};


#include "DeleteQuery.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_DELETEQUERY_
