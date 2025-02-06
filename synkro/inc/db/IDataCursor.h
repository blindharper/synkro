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
// Purpose: Defines data cursor.
//==============================================================================
#ifndef _SYNKRO_DB_IDATACURSOR_
#define _SYNKRO_DB_IDATACURSOR_


#include "config.h"
#include <core/IObject.h>
#include <lang/Variant.h>


namespace synkro
{


namespace db
{


/**
 * Database records reader.
 */
iface IDataCursor :
	public core::IObject
{
public:
	/**
	 * Proceeds to the next record.
	 * @return True if not reached the last record, false otherwise.
	 */
	virtual Bool											Read() = 0;

	/**
	 * Retrieves the value of the specified column from the current record.
	 * @param column Column name.
	 * @return Requested cell value.
	 */
	virtual lang::Variant									GetValue( const lang::String& column ) const = 0;
};


} // db


} // synkro


#endif // _SYNKRO_DB_IDATACURSOR_
