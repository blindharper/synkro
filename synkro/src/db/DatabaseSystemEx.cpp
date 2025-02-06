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
// Purpose: Implements extended database system.
//==============================================================================
#include "config.h"
#include "DatabaseSystemEx.h"
#include "DataFilter.h"
#include "Database.h"
#include <db/IDatabaseSystemFactory.h>
#include <io/IStream.h>


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace db
{


DatabaseSystemEx::DatabaseSystemEx( ILog* log ) :
	_factory( nullptr ),
	Logger( log, LogFacility::DatabaseSystem )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating database system...") );
}

DatabaseSystemEx::~DatabaseSystemEx()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying database system...") );
}

Bool DatabaseSystemEx::Update( Double delta )
{
	return true;
}

IDatabase* DatabaseSystemEx::CreateDatabase( IStream* stream )
{
	// Optimize data source performance.
	stream->SetAccessMode( AccessMode::Random );

	return new Database( _databaseSystem->CreateDatabase(stream) );
}

IDataFilter* DatabaseSystemEx::CreateFilter( const String& column, const ComparisonType& comparison, const Variant& reference )
{
	return new DataFilter( column, comparison, reference );
}

IDataFilter* DatabaseSystemEx::CreateFilter( IDataFilter* first, const CombinationType& combination, IDataFilter* second )
{
	return new DataFilter( first, combination, second );
}

void DatabaseSystemEx::Initialize( IDatabaseSystemFactory* factory )
{
	// Re-create database system, if needed.
	if ( factory != _factory )
	{
		_factory = factory;
		_databaseSystem = _factory->Create( _log );
	}
}


} // db


} // synkro
