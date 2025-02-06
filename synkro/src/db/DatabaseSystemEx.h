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
#ifndef _SYNKRO_DB_DATABASESYSTEMEX_
#define _SYNKRO_DB_DATABASESYSTEMEX_


#include "config.h"
#include <core/ObjectImpl.h>
#include <db/IDatabaseSystemEx.h>


namespace synkro
{


namespace db
{


// Extended database system implementation.
class DatabaseSystemEx :
	public core::ObjectImpl<IDatabaseSystemEx>,
	public Logger
{
public:
	// Constructor & destructor.
	DatabaseSystemEx( diag::ILog* log );
	~DatabaseSystemEx();

	// ISystem methods.
	Bool													Update( Double delta );

	// IDatabaseSystem methods.
	IDatabase*												CreateDatabase( io::IStream* stream );

	// IDatabaseSystemEx methods.
	IDataFilter*											CreateFilter( const lang::String& column, const ComparisonType& comparison, const lang::Variant& reference );
	IDataFilter*											CreateFilter( IDataFilter* first, const CombinationType& combination, IDataFilter* second );

	// Other methods.
	void													Initialize( IDatabaseSystemFactory* factory );

private:
	IDatabaseSystemFactory*									_factory;
	P(IDatabaseSystem)										_databaseSystem;
};


} // db


} // synkro


#endif // _SYNKRO_DB_DATABASESYSTEMEX_
