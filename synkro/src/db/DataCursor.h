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
// Purpose: Implements logical data cursor.
//==============================================================================
#ifndef _SYNKRO_DB_DATACURSOR_
#define _SYNKRO_DB_DATACURSOR_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/IDataCursor.h>


namespace synkro
{


namespace db
{


// Logical data cursor implementation.
class DataCursor :
	public core::ObjectImpl<IDataCursor>
{
public:
	// Constructor.
	DataCursor( IDataCursor* cursor );

	// IDataCursor methods.
	Bool													Read();
	lang::Variant											GetValue( const lang::String& column ) const;

private:
	P(IDataCursor)											_cursor;
};


#include "DataCursor.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_DATACURSOR_
