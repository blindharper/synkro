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
// Purpose: Generic database query implementation.
//==============================================================================
#ifndef _SYNKRO_DB_DATABASEQUERYIMPL_
#define _SYNKRO_DB_DATABASEQUERYIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/IDataTable.h>
#include <db/IDataFilter.h>
#include <db/DatabaseException.h>
#include <lang/Variant.h>


namespace synkro
{


namespace db
{


// Generic database query implementation.
template <class T>
class DatabaseQueryImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	DatabaseQueryImpl( IDataTable* table );
	virtual ~DatabaseQueryImpl();

	// IDatabaseQuery methods.
	virtual void											Execute();
	virtual void											Reset();

protected:
	IDataTable*												_table;
	P(IDataFilter)											_filter;
	Bool													_dirty;
};


#include "DatabaseQueryImpl.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_DATABASEQUERYIMPL_
