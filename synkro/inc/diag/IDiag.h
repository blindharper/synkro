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
// Purpose: Defines diagnostics object.
//==============================================================================
#ifndef _SYNKRO_DIAG_IDIAG_
#define _SYNKRO_DIAG_IDIAG_


#include "config.h"
#include <core/IObject.h>
#include <diag/LogMode.h>
#include <diag/LogLevel.h>


namespace synkro
{


namespace diag
{


/**
 * Diagnostics object. Provides functionality for application diagnostics.
 */
iface IDiag :
	public core::IObject
{
public:
	/**
	 * Creates a log with the specified name or returns existing one.
	 * @param name Unique log name.
	 * @param level Logging level.
	 * @param mode Logging mode.
	 * @return Created log.
	 */
	virtual ILog*											CreateLog( const lang::String& name, const LogLevel& level, const LogMode& mode ) = 0;

	/**
	 * Retrieves a log by name.
	 * @param name Log name.
	 * @return Requested log, if one is found, or null otherwise.
	 */
	virtual ILog*											GetLog( const lang::String& name ) const = 0;

	/**
	 * Retrieves the default log.
	 * @return Default log.
	 */
	virtual ILog*											GetLog() const = 0;
};


} // diag


} // synkro


#endif // _SYNKRO_DIAG_IDIAG_
