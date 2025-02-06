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
// Purpose: Defines INSERT database query.
//==============================================================================
#ifndef _SYNKRO_DB_IINSERTQUERY_
#define _SYNKRO_DB_IINSERTQUERY_


#include "config.h"
#include <db/IDatabaseQuery.h>
#include <lang/Variant.h>


namespace synkro
{


namespace db
{


/**
 * INSERT query.
 */
iface IInsertQuery :
	public IDatabaseQuery
{
public:
	/**
	 * Specifies cell value to insert.
	 * @param column Column name.
	 * @param value Cell value.
	 */
	virtual void											SetValue( const lang::String& column, const lang::Variant& value ) = 0;

	/**
	 * Retrieves identifier of the inserted row. Only meaningful after calling Execute().
	 */
	virtual UInt											GetRowID() const = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_IINSERTQUERY_
