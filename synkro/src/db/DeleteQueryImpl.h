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
// Purpose: Generic DELETE query implementation.
//==============================================================================
#ifndef _SYNKRO_DB_DELETEQUERYIMPL_
#define _SYNKRO_DB_DELETEQUERYIMPL_


#include "config.h"
#include "DatabaseQueryImpl.h"


namespace synkro
{


namespace db
{


// Generic DELETE query implementation.
template <class T>
class DeleteQueryImpl :
	public DatabaseQueryImpl<T>
{
public:
	// Constructor & destructor.
	DeleteQueryImpl( IDataTable* table );
	virtual ~DeleteQueryImpl();

	// IDatabaseQuery methods.
	virtual void											Reset();

	// IDeleteQuery methods.
	virtual void											SetFilter( IDataFilter* filter );
	virtual IDataFilter*									GetFilter() const;
};


#include "DeleteQueryImpl.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_DELETEQUERYIMPL_
