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
// Purpose: Sqlite API.
//==============================================================================
#include "config.h"
#include "Sqlite.h"
#include <db/DatabaseException.h>
#include <lang/Vector.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


void Sqlite::Prepare( sqlite3* db, const lang::String& sql, sqlite3_stmt** stmt )
{
	Vector<char> query( A(char) );
	query.SetSize( sql.Length() );
	sql.GetBytes( query.Begin(), sql.Length() );
	const int rc = sqlite3_prepare_v2( db, query.Begin(), query.Size(), stmt, nullptr );
	if ( rc != SQLITE_OK )
		throw DatabaseException( L"Failed to prepare query", sql, Sqlite::ToString(rc) );
}

void Sqlite::Execute( sqlite3* db, const String& sql, sqlite_callback callback, void* ctx )
{
	char* error = 0;
	Vector<char> query( A(char) );
	query.SetSize( sql.Length() );
	sql.GetBytes( query.Begin(), sql.Length() );
	const int rc = sqlite3_exec( db, query.Begin(), callback, ctx, &error );
	if ( rc != SQLITE_OK )
	{
		String message( error );
		sqlite3_free( error );
		throw DatabaseException( message, sql, ToString(rc) );
	}
}

DataType Sqlite::ToType( const String& type )
{
	if ( type.EqualsTo(L"INTEGER", true) )
		return DataType::Integer;
	else if ( type.EqualsTo(L"REAL", true) )
		return DataType::Float;
	else if ( type.EqualsTo(L"TEXT", true) )
		return DataType::String;
	else if ( type.EqualsTo(L"BLOB", true) )
		return DataType::Blob;

	return DataType::Unknown;
}

const Char* Sqlite::ToString( const DataType& type )
{
	static Char* consts[] =
	{
		L"NULL",
		L"INTEGER",
		L"REAL",
		L"TEXT",
		L"TEXT",
		L"BLOB",
	};
	return consts[type];
}

const Char* Sqlite::ToString( const SortOrder& order )
{
	Char* values[] =
	{
		L"ASC",
		L"DESC",
	};
	return values[order.Value()];
}

const Char* Sqlite::ToString( const CombinationType& combination )
{
	Char* values[] =
	{
		L"AND",
		L"OR",
	};
	return values[combination.Value()];
}

const Char* Sqlite::ToString( const ComparisonType& comparison )
{
	Char* values[] =
	{
		L"",
		L"IS",
		L"IS NOT",
		L"=",
		L"!=",
		L"<",
		L"<=",
		L">",
		L">=",
	};
	return values[comparison.Value()];
}

const Char* Sqlite::ToString( int error )
{
	switch ( error )
	{
		case SQLITE_OK:				return L"SQLITE_OK";
		case SQLITE_ERROR:			return L"SQLITE_ERROR";
		case SQLITE_INTERNAL:		return L"SQLITE_INTERNAL";
		case SQLITE_PERM:			return L"SQLITE_PERM";
		case SQLITE_ABORT:			return L"SQLITE_ABORT";
		case SQLITE_BUSY:			return L"SQLITE_BUSY";
		case SQLITE_LOCKED:			return L"SQLITE_LOCKED";
		case SQLITE_NOMEM:			return L"SQLITE_NOMEM";
		case SQLITE_READONLY:		return L"SQLITE_READONLY";
		case SQLITE_INTERRUPT:		return L"SQLITE_INTERRUPT";
		case SQLITE_IOERR:			return L"SQLITE_IOERR";
		case SQLITE_CORRUPT:		return L"SQLITE_CORRUPT";
		case SQLITE_NOTFOUND:		return L"SQLITE_NOTFOUND";
		case SQLITE_FULL:			return L"SQLITE_FULL";
		case SQLITE_CANTOPEN:		return L"SQLITE_CANTOPEN";
		case SQLITE_PROTOCOL:		return L"SQLITE_PROTOCOL";
		case SQLITE_EMPTY:			return L"SQLITE_EMPTY";
		case SQLITE_SCHEMA:			return L"SQLITE_SCHEMA";
		case SQLITE_TOOBIG:			return L"SQLITE_TOOBIG";
		case SQLITE_CONSTRAINT:		return L"SQLITE_CONSTRAINT";
		case SQLITE_MISMATCH:		return L"SQLITE_MISMATCH";
		case SQLITE_MISUSE:			return L"SQLITE_MISUSE";
		case SQLITE_NOLFS:			return L"SQLITE_NOLFS";
		case SQLITE_AUTH:			return L"SQLITE_AUTH";
		case SQLITE_FORMAT:			return L"SQLITE_FORMAT";
		case SQLITE_RANGE:			return L"SQLITE_RANGE";
		case SQLITE_NOTADB:			return L"SQLITE_NOTADB";
		case SQLITE_NOTICE:			return L"SQLITE_NOTICE";
		case SQLITE_WARNING:		return L"SQLITE_WARNING";
		case SQLITE_ROW:			return L"SQLITE_ROW";
		case SQLITE_DONE:			return L"SQLITE_DONE";
		default:					return L"";
	}
}


} // db


} // synkro
