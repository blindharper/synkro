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
// Purpose: Generic UPDATE query implementation.
//==============================================================================
#ifndef _SYNKRO_DB_UPDATEQUERYIMPL_
#define _SYNKRO_DB_UPDATEQUERYIMPL_


#include "config.h"
#include "DatabaseQueryImpl.h"
#include <lang/Map.h>


namespace synkro
{


namespace db
{


// Generic UPDATE query implementation.
template <class T>
class UpdateQueryImpl :
	public DatabaseQueryImpl<T>
{
public:
	// Constructor & destructor.
	UpdateQueryImpl( IDataTable* table );
	virtual ~UpdateQueryImpl();

	// IDatabaseQuery methods.
	virtual void											Reset();

	// IUpdateQuery methods.
	virtual void											SetValue( const lang::String& column, const lang::Variant& value );
	virtual void											SetFilter( IDataFilter* filter );
	virtual IDataFilter*									GetFilter() const;

protected:
	typedef lang::MapPair<lang::String, lang::Variant>		ValueEntry;

	lang::MapCI<lang::String, lang::Variant>				_values;
};


#include "UpdateQueryImpl.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_UPDATEQUERYIMPL_
