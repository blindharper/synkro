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
// Purpose: Implements logical UPDATE query.
//==============================================================================
#ifndef _SYNKRO_DB_UPDATEQUERY_
#define _SYNKRO_DB_UPDATEQUERY_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/IUpdateQuery.h>
#include "BaseDatabaseQueryImpl.h"
#include "BaseDatabaseQuery.h"


namespace synkro
{


namespace db
{


// Logical UPDATE query implementation.
class UpdateQuery :
	public core::ObjectImpl<IUpdateQuery>,
	public BaseDatabaseQueryImpl<BaseDatabaseQuery>
{
public:
	// Constructor.
	UpdateQuery( IDataTable* table, IUpdateQuery* query );

	// IDatabaseQuery methods.
	void													Execute();
	void													Reset();

	// IUpdateQuery methods.
	void													SetValue( const lang::String& column, const lang::Variant& value );
	void													SetFilter( IDataFilter* filter );
	IDataFilter*											GetFilter() const;

private:
	P(IUpdateQuery)											_query;
};


#include "UpdateQuery.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_UPDATEQUERY_
