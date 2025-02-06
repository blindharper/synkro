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
// Purpose: Generic data cursor implementation.
//==============================================================================
#ifndef _SYNKRO_DB_DATACURSORIMPL_
#define _SYNKRO_DB_DATACURSORIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/DatabaseException.h>
#include <db/TableColumn.h>
#include <lang/Variant.h>
#include <lang/Vector.h>
#include <lang/Map.h>


namespace synkro
{


namespace db
{


// Generic data cursor implementation.
template <class T>
class DataCursorImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructor & destructor.
	DataCursorImpl( const lang::Vector<TableColumn>& columns );
	virtual ~DataCursorImpl();

	// IDataCursor methods.
	virtual lang::Variant									GetValue( const lang::String& column ) const;

protected:
	typedef lang::MapPair<lang::String, lang::Variant>		ValueEntry;

	lang::Vector<TableColumn>								_columns;
	lang::MapCI<lang::String, lang::Variant>				_record;
};


#include "DataCursorImpl.inl"


} // db


} // synkro


#endif // _SYNKRO_DB_DATACURSORIMPL_
