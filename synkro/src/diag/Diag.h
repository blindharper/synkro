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
#ifndef _SYNKRO_DIAG_DIAG_
#define _SYNKRO_DIAG_DIAG_


#include "config.h"
#include <lang/Map.h>
#include <core/ObjectImpl.h>
#include <lang/Formatter.h>
#include <diag/IDiag.h>


namespace synkro
{


namespace diag
{


// IDiag implementation.
class Diag :
	public core::ObjectImpl<IDiag>
{
public:
	// Constructor & destructor.
	Diag();
	~Diag();

	// IDiag methods.
	ILog*													CreateLog( const lang::String& name, const LogLevel& level, const LogMode& mode );
	ILog*													GetLog( const lang::String& name ) const;
	ILog*													GetLog() const;

private:
	typedef lang::MapPair<lang::String, P(ILog)>			LogEntry;

	lang::MapCI<lang::String, P(ILog)>						_logs;
};


#include "Diag.inl"


} // diag


} // synkro


#endif // _SYNKRO_DIAG_DIAG_
