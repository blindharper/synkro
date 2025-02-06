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
// Purpose: Implements Sqlite data cursor.
//==============================================================================
#include "config.h"
#include "SqliteDataCursor.h"
#include <lang/DataTypeConst.h>


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


SqliteDataCursor::SqliteDataCursor( sqlite3_stmt* stmt, const Vector<TableColumn>& columns ) :
	DataCursorImpl<IDataCursor>( columns ),
	_stmt( stmt )
{
}

Bool SqliteDataCursor::Read()
{
	int rc = sqlite3_step( _stmt );
	if ( rc == SQLITE_ROW )
	{
		UInt size = 0;
		Int valueInt = 0;
		Float valueFloat = 0.0f;
		const void* buffer = nullptr;
		Variant var; IStream* blob = nullptr;
		for ( UInt i = 0; i < _columns.Size(); ++i )
		{
			String name = _columns[i].Name;
			if ( sqlite3_column_type(_stmt, i) == SQLITE_NULL )
			{
				_record[name] = Variant::Null;
				continue;
			}

			switch ( _columns[i].Type )
			{
				case DATA_TYPE_INTEGER:
					valueInt = CastLong( sqlite3_column_int(_stmt, i) );
					_record[name] = Variant( valueInt );
					break;

				case DATA_TYPE_FLOAT:
					valueFloat = CastFloat( sqlite3_column_double(_stmt, i) );
					_record[name] = Variant( valueFloat );
					break;

				case DATA_TYPE_STRING:
					buffer = sqlite3_column_text( _stmt, i );
					size = CastUInt( sqlite3_column_bytes(_stmt, i) );
					_record[name] = Variant( String(buffer, size, "ASCII-7") );
					break;

				case DATA_TYPE_BLOB:
					blob = (IStream*)_record[name];
					if ( blob != nullptr )
					{
						blob->Close();
					}
					buffer = sqlite3_column_blob( _stmt, i );
					size = CastUInt( sqlite3_column_bytes(_stmt, i) );
					var = Variant( (const Byte*)buffer, size );
					((IStream*)var)->Open( OpenMode::Read );
					_record[name] = var;
					break;
			}
		}
		return true;
	}
	else if ( rc == SQLITE_DONE )
	{
		_record.Clear();
	}
	return false;
}


} // db


} // synkro
