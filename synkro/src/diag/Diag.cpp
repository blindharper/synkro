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
// Purpose: Implements diagnostics object.
//==============================================================================
#include "config.h"
#include "Diag.h"
#include "Log.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace diag
{


Diag::Diag() :
	_logs( A(LogEntry) )
{
	// Create default log.
	CreateLog( String::Empty, LogLevel::Extensive, LogMode::All );
}

Diag::~Diag()
{
}

ILog* Diag::CreateLog( const String& name, const LogLevel& level, const LogMode& mode )
{
	if ( !_logs.ContainsKey(name) )
		_logs[name] = new Log( level, mode );

	return _logs[name];
}


} // diag


} // synkro
