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
// Purpose: Defines database table column.
//==============================================================================
#include "config.h"
#include <db/TableColumn.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


TableColumn::TableColumn( const String& name, const DataType& type, Bool unique, Bool nullable, Bool primary, const String& foreignTable, const String& foreignColumn ) :
	Name( name ),
	Type( type ),
	Unique( unique ),
	Nullable( nullable ),
	Primary( primary ),
	ForeignTable( foreignTable ),
	ForeignColumn( foreignColumn )
{
}

TableColumn::TableColumn( const String& name, const DataType& type, Bool unique, Bool nullable, Bool primary ) :
	Name( name ),
	Type( type ),
	Unique( unique ),
	Nullable( nullable ),
	Primary( primary )
{
}

TableColumn::TableColumn( const String& name, const DataType& type, Bool unique, Bool nullable ) :
	Name( name ),
	Type( type ),
	Unique( unique ),
	Nullable( nullable ),
	Primary( false )
{
}

TableColumn::TableColumn( const String& name, const DataType& type, Bool unique ) :
	Name( name ),
	Type( type ),
	Unique( unique ),
	Nullable( true ),
	Primary( false )
{
}

TableColumn::TableColumn( const String& name, const DataType& type ) :
	Name( name ),
	Type( type ),
	Unique( false ),
	Nullable( true ),
	Primary( false )
{
}

TableColumn::TableColumn() :
	Type( DataType::Unknown ),
	Unique( false ),
	Nullable( true ),
	Primary( false )
{
}


} // db


} // synkro
