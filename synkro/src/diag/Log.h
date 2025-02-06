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
// Purpose: Implements diagnostics log.
//==============================================================================
#ifndef _SYNKRO_DIAG_LOG_
#define _SYNKRO_DIAG_LOG_


#include "config.h"
#include <core/ObjectImpl.h>
#include <diag/ILog.h>
#include <diag/LogListener.h>
#include <lang/Vector.h>
#include <internal/BinarySemaphore.h>
#include "BaseLog.h"


namespace synkro
{


namespace diag
{


// ILog implementation.
class Log :
	public core::ObjectImpl<ILog>,
	public BaseLog
{
public:
	// Constructor & destructor.
	Log( const LogLevel& level, const LogMode& mode );
	~Log();

	// ILog methods.
	void													Listen( LogListener* listener );
	void													InfoStart( const LogFacility& facility, const MessagePriority& priority, const lang::String& text );
	void													InfoStart( const LogFacility& facility, const MessagePriority& priority, const lang::Formatter& text );
	void													InfoContinue( const lang::String& text );
	void													InfoContinue( const lang::Formatter& text );
	void													InfoEnd( const lang::String& text );
	void													InfoEnd( const lang::Formatter& text );
	void													Info( const LogFacility& facility, const MessagePriority& priority, const lang::String& text );
	void													Info( const LogFacility& facility, const MessagePriority& priority, const lang::Formatter& text );
	void													Warning( const LogFacility& facility, const MessagePriority& priority, const lang::String& text );
	void													Warning( const LogFacility& facility, const MessagePriority& priority, const lang::Formatter& text );
	void													Error( const LogFacility& facility, const MessagePriority& priority, const lang::String& text );
	void													Error( const LogFacility& facility, const MessagePriority& priority, const lang::Formatter& text );
	LogLevel												GetLevel() const;
	LogMode													GetMode() const;

	// BaseLog methods.
	void													Initialize( const LogLevel& level, const LogMode& mode );
	void													Pause( Bool pause );

private:
	struct LogEntry
	{
		LogEntry( UInt thread, const LogMode& type, const LogFacility& facility, const MessagePriority& priority, const lang::DateTime& time, const lang::String& text ) :
			Thread( thread ),
			Type( type ),
			Facility( facility ),
			Priority( priority ),
			Time( time ),
			Text( text )
		{
		}

		LogEntry()
		{
		}

		UInt			Thread;
		LogMode			Type;
		LogFacility		Facility;
		MessagePriority	Priority;
		lang::DateTime	Time;
		lang::String	Text;
	};

	lang::Vector<LogListener*>								_listeners;
	lang::Vector<LogEntry>									_entries;
	LogLevel												_level;
	LogMode													_mode;
	lang::DateTime											_time;
	Bool													_started;
	Bool													_paused;
	BinarySemaphore											_lock;

	Bool													AllowContinueMessage();
	Bool													AllowMessage( const MessagePriority& priority, const LogMode& type );
	void													EmitInfoStart( const LogFacility& facility, const MessagePriority& priority, const lang::String& text );
	void													ContinueInfo( const lang::String& text );
	void													EndInfo( const lang::String& text );
	void													EmitInfo( const LogFacility& facility, const MessagePriority& priority, const lang::String& text );
	void													EmitWarning( const LogFacility& facility, const MessagePriority& priority, const lang::String& text );
	void													EmitError( const LogFacility& facility, const MessagePriority& priority, const lang::String& text );
};


#include "Log.inl"


} // diag


} // synkro


#endif // _SYNKRO_DIAG_LOG_
