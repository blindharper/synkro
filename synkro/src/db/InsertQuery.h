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
// Purpose: Implements logical INSERT query.
//==============================================================================
#ifndef _SYNKRO_DB_INSERTQUERY_
#define _SYNKRO_DB_INSERTQUERY_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/IInsertQuery.h>
#include "BaseDatabaseQueryImpl.h"
#include "BaseDatabaseQuery.h"


namespace synkro
{


namespace db
{


// Logical INSERT query implementation.
class InsertQuery :
	public core::ObjectImpl<IInsertQuery>,
	public BaseDatabaseQueryImpl<BaseDatabaseQuery>
{
public:
	// Constructor.
	InsertQuery( IDataTable* table, IInsertQuery* query );

	// IDatabaseQuery methods.
	void													Execute();
	void													Reset();

	// IInsertQuery methods.
	void													SetValue( const lang::String& column, const lang::Variant& value );
	UInt													GetRowID() const;

private:
	P(IInsertQuery)											_query;
};


#include "InsertQuery.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_INSERTQUERY_
