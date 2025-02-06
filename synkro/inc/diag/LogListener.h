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
// Purpose: Defines log listener.
//==============================================================================
#ifndef _SYNKRO_DIAG_LOGLISTENER_
#define _SYNKRO_DIAG_LOGLISTENER_


#include "config.h"
#include <lang/String.h>
#include <lang/DateTime.h>
#include <diag/LogFacility.h>


namespace synkro
{


namespace diag
{


/**
 * Log listener. Gets notified every time a log event occurs.
 */
iface LogListener
{
public:
	/**
	 * Start log event handler. Occurs when the listener is bound to the log.
	 * @param time Event time.
	 */
	virtual void											OnLogStart( const lang::DateTime& time ) = 0;

	/**
	 * End log event handler. Occurs when the log gets destroyed.
	 * @param time Event time.
	 */
	virtual void											OnLogEnd( const lang::DateTime& time ) = 0;

	/**
	 * Message start event handler.
	 * @param thread Calling thread identifier.
	 * @param facility Event facility.
	 * @param time Event time.
	 * @param text Message text.
	 */
	virtual void											OnLogInfoStart( UInt thread, const LogFacility& facility, const lang::DateTime& time, const lang::String& text ) = 0;

	/**
	 * Message continue event handler.
	 * @param text Message text.
	 */
	virtual void											OnLogInfoContinue( const lang::String& text ) = 0;

	/**
	 * Message end event handler.
	 * @param text Message text.
	 */
	virtual void											OnLogInfoEnd( const lang::String& text ) = 0;

	/**
	 * Message event handler.
	 * @param thread Calling thread identifier.
	 * @param facility Event facility.
	 * @param time Event time.
	 * @param text Message text.
	 */
	virtual void											OnLogInfo( UInt thread, const LogFacility& facility, const lang::DateTime& time, const lang::String& text ) = 0;
	
	/**
	 * Warning event handler.
	 * @param thread Calling thread identifier.
	 * @param facility Event facility.
	 * @param time Event time.
	 * @param text Warning text.
	 */
	virtual void											OnLogWarning( UInt thread, const LogFacility& facility, const lang::DateTime& time, const lang::String& text ) = 0;

	/**
	 * Error event handler.
	 * @param thread Calling thread identifier.
	 * @param facility Event facility.
	 * @param time Event time.
	 * @param text Error text.
	 */
	virtual void											OnLogError( UInt thread, const LogFacility& facility, const lang::DateTime& time, const lang::String& text ) = 0;
};


} // diag


} // synkro


#endif // _SYNKRO_DIAG_LOGLISTENER_
