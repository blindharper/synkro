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
// Purpose: Generic database implementation.
//==============================================================================
#ifndef _SYNKRO_DB_DATABASEIMPL_
#define _SYNKRO_DB_DATABASEIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/IDataTable.h>
#include <db/DatabaseException.h>
#include <lang/Map.h>
#include <lang/Vector.h>


namespace synkro
{


namespace db
{


// Generic database implementation.
template <class T>
class DatabaseImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	DatabaseImpl();
	virtual ~DatabaseImpl();

	// IDatabase methods.
	virtual UInt											GetTableCount() const;
	virtual IDataTable*										GetTable( UInt index ) const;
	virtual IDataTable*										GetTable( const lang::String& name ) const;

protected:
	typedef lang::MapPair<lang::String, UInt>				IndexEntry;

	lang::Vector<P(IDataTable)>								_tables;
	lang::MapCI<lang::String, UInt>							_tableIndices;
};


#include "DatabaseImpl.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_DATABASEIMPL_
