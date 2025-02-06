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
// Purpose: Generic Sqlite base query implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE SqliteBaseQueryImpl<T>::SqliteBaseQueryImpl( sqlite3* db ) :
	_db( db ),
	_stmt( nullptr )
{
}

template <class T>
SYNKRO_INLINE SqliteBaseQueryImpl<T>::~SqliteBaseQueryImpl()
{
	Finalize();
}

template <class T>
SYNKRO_INLINE lang::String SqliteBaseQueryImpl<T>::Evaluate( IDataFilter* filter ) const
{
	return (filter != nullptr) ? lang::String::Format(L" WHERE {0}", EvaluateFilter(filter)) : lang::String::Empty;
}

template <class T>
SYNKRO_INLINE void SqliteBaseQueryImpl<T>::Bind( const lang::MapCI<lang::String, lang::Variant>& values )
{
	// Reset statement to the initial state.
	sqlite3_reset( _stmt );
	sqlite3_clear_bindings( _stmt );

	// Bind parameters.
	Int idx = 1;
	int rc = SQLITE_OK;
	lang::MapIterator<lang::String, lang::Variant> it = values.Begin();
	lang::Vector<Byte> bytes( A(Byte) );
	for ( ; it != values.End(); ++it )
	{
		switch ( it.Value().Type() )
		{
			case DATA_TYPE_INTEGER:
				rc = sqlite3_bind_int( _stmt, idx++, CastInt(it.Value()) );
				break;

			case DATA_TYPE_FLOAT:
				rc = sqlite3_bind_double( _stmt, idx++, CastFloat(it.Value()) );
				break;

			case DATA_TYPE_STRING:
			case DATA_TYPE_DATE_TIME:
				ReadString( (lang::String)it.Value(), bytes );
				rc = sqlite3_bind_text( _stmt, idx++, (const char*)bytes.Begin(), (int)bytes.Size(), SQLITE_TRANSIENT );
				break;

			case DATA_TYPE_BLOB:
				ReadBlob( (io::IStream*)it.Value(), bytes );
				rc = sqlite3_bind_blob( _stmt, idx++, (const void*)bytes.Begin(), (int)bytes.Size(), SQLITE_TRANSIENT );
				break;

			default:
				rc = sqlite3_bind_null( _stmt, idx++ );
				break;
		}
		if ( rc != SQLITE_OK )
			throw DatabaseException( lang::String::Format(L"Failed to bind parameter {0}", it.Key()), Sqlite::ToString(rc) );
	}
}

template <class T>
SYNKRO_INLINE lang::String SqliteBaseQueryImpl<T>::EvaluateFilter( IDataFilter* filter ) const
{
	if ( filter->GetFirstFilter() != nullptr )
	{
		lang::String first = EvaluateFilter( filter->GetFirstFilter() );
		lang::String second = EvaluateFilter( filter->GetSecondFilter() );
		CombinationType combination = filter->GetCombinationType();
		return lang::String::Format( L"{0} {1} {2}", first, Sqlite::ToString(combination), second );
	}
	else
	{
		ComparisonType comparison = filter->GetComparisonType();
		lang::String column = filter->GetColumn();
		lang::Variant reference = filter->GetReference();
		switch ( reference.Type() )
		{
			case DATA_TYPE_INTEGER:
				return lang::String::Format( L"({0} {1} {2})", column, Sqlite::ToString(comparison), CastInt(reference) );

			case DATA_TYPE_FLOAT:
				return lang::String::Format( L"({0} {1} {2,#.000000})", column, Sqlite::ToString(comparison), CastFloat(reference) );

			case DATA_TYPE_STRING:
			case DATA_TYPE_DATE_TIME:
				return lang::String::Format( L"({0} {1} {2,q})", column, Sqlite::ToString(comparison), (lang::String)reference );

			case DATA_TYPE_UNKNOWN:
				return lang::String::Format( L"({0} {1} NULL)", column, Sqlite::ToString(comparison) );
				break;
		}
	}
	return lang::String::Empty;
}

template <class T>
SYNKRO_INLINE void SqliteBaseQueryImpl<T>::Finalize()
{
	if ( _stmt != nullptr )
	{
		sqlite3_finalize( _stmt );
		_stmt = nullptr;
	}
}

template <class T>
SYNKRO_INLINE void SqliteBaseQueryImpl<T>::ReadString( const lang::String& value, lang::Vector<Byte>& bytes )
{
	bytes.SetSize( value.Length()+1 );
	value.GetBytes( bytes.Begin(), value.Length() );
	bytes.Add( 0 );
}

template <class T>
SYNKRO_INLINE void SqliteBaseQueryImpl<T>::ReadBlob( io::IStream* blob, lang::Vector<Byte>& bytes )
{
	io::BinaryReader rd( blob );
	rd.ReadBytes( bytes );
}
