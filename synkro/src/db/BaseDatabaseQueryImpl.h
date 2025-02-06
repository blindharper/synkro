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
// Purpose: Generic base database query implementation.
//=============================================================================
#ifndef _SYNKRO_DB_BASEDATABASEQUERYIMPL_
#define _SYNKRO_DB_BASEDATABASEQUERYIMPL_


#include "config.h"
#include <db/IDataTable.h>
#include <db/IDataFilter.h>


namespace synkro
{


namespace db
{


// Generic base database query implementation.
template <class T>
class BaseDatabaseQueryImpl :
	public T
{
public:
	// Constructor and destructor.
	BaseDatabaseQueryImpl( IDataTable* table );
	virtual ~BaseDatabaseQueryImpl();
	
	// BaseDatabaseQuery methods.
	virtual void											ValidateColumn( const lang::String& name );
	virtual void											ValidateFilter( IDataFilter* filter );

protected:
	IDataTable*												_table;
};


#include "BaseDatabaseQueryImpl.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_BASEDATABASEQUERYIMPL_
