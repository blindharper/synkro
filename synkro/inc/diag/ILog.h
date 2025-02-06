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
// Purpose: Defines diagnostics log.
//==============================================================================
#ifndef _SYNKRO_DIAG_ILOG_
#define _SYNKRO_DIAG_ILOG_


#include "config.h"
#include <core/IObject.h>
#include <diag/LogMode.h>
#include <diag/LogLevel.h>
#include <diag/LogFacility.h>
#include <diag/MessagePriority.h>
#include <lang/Formatter.h>


namespace synkro
{


namespace diag
{


/**
 * Diagnostics log.
 */
iface ILog :
	public core::IObject
{
public:
	/**
	 * Registers a listener with the log.
	 * @param listener Log event listener.
	 */
	virtual void											Listen( LogListener* listener ) = 0;

	/**
	 * Starts emitting an informational message with the given priority.
	 * Must be followed by a call to InfoContinue or InfoEnd.
	 * @param facility Facility that emitted the message.
	 * @param priority Priority assigned to the message.
	 * @param text Message text.
	 */
	virtual void											InfoStart( const LogFacility& facility, const MessagePriority& priority, const lang::String& text ) = 0;

	/**
	 * Starts emitting an informational message with the given priority.
	 * Must be followed by a call to InfoContinue or InfoEnd.
	 * @param facility Facility that emitted the message.
	 * @param priority Priority assigned to the message.
	 * @param text Formatted message text. Text is not evaluated until absolutely necessary.
	 */
	virtual void											InfoStart( const LogFacility& facility, const MessagePriority& priority, const lang::Formatter& text ) = 0;

	/**
	 * Continues an informational message started by a previous call to InfoStart.
	 * @param text Message text.
	 */
	virtual void											InfoContinue( const lang::String& text ) = 0;

	/**
	 * Continues an informational message started by a previous call to InfoStart.
	 * @param text Formatted message text. Text is not evaluated until absolutely necessary.
	 */
	virtual void											InfoContinue( const lang::Formatter& text ) = 0;

	/**
	 * Ends an informational message started by a previous call to InfoStart.
	 * @param text Message text.
	 */
	virtual void											InfoEnd( const lang::String& text ) = 0;

	/**
	 * Ends an informational message started by a previous call to InfoStart.
	 * @param text Formatted message text. Text is not evaluated until absolutely necessary.
	 */
	virtual void											InfoEnd( const lang::Formatter& text ) = 0;

	/**
	 * Emits an informational message with the given priority.
	 * @param facility Facility that emitted the message.
	 * @param priority Priority assigned to the message.
	 * @param text Message text.
	 */
	virtual void											Info( const LogFacility& facility, const MessagePriority& priority, const lang::String& text ) = 0;

	/**
	 * Emits an informational message with the given priority.
	 * @param facility Facility that emitted the message.
	 * @param priority Priority assigned to the message.
	 * @param text Formatted message text. Text is not evaluated until absolutely necessary.
	 */
	virtual void											Info( const LogFacility& facility, const MessagePriority& priority, const lang::Formatter& text ) = 0;
	
	/**
	 * Emits a warning message with the given priority.
	 * @param facility Facility that emitted the message.
	 * @param priority Priority assigned to the message.
	 * @param text Warning text.
	 */
	virtual void											Warning( const LogFacility& facility, const MessagePriority& priority, const lang::String& text ) = 0;

	/**
	 * Emits a warning message with the given priority.
	 * @param facility Facility that emitted the message.
	 * @param priority Priority assigned to the message.
	 * @param text Formatted warning text. Text is not evaluated until absolutely necessary.
	 */
	virtual void											Warning( const LogFacility& facility, const MessagePriority& priority, const lang::Formatter& text ) = 0;

	/**
	 * Emits an error message with the given priority.
	 * @param facility Facility that emitted the message.
	 * @param priority Priority assigned to the message.
	 * @param text Error text.
	 */
	virtual void											Error( const LogFacility& facility, const MessagePriority& priority, const lang::String& text ) = 0;

	/**
	 * Emits an error message with the given priority.
	 * @param facility Facility that emitted the message.
	 * @param priority Priority assigned to the message.
	 * @param text Formatted error text. Text is not evaluated until absolutely necessary.
	 */
	virtual void											Error( const LogFacility& facility, const MessagePriority& priority, const lang::Formatter& text ) = 0;

	/**
	 * Retrieves logging level.
	 */
	virtual LogLevel										GetLevel() const = 0;

	/**
	 * Retrieves logging mode.
	 */
	virtual LogMode											GetMode() const = 0;
};


} // diag


} // synkro


#endif // _SYNKRO_DIAG_ILOG_
