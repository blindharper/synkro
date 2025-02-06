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
#include "config.h"
#include "Log.h"
#include <core/Thread.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace diag
{


Log::Log( const LogLevel& level, const LogMode& mode ) :
	_listeners( A(LogListener*) ),
	_entries( A(LogEntry) ),
	_level( level ),
	_mode( mode ),
	_started( false ),
	_paused( false ),
	_lock( true )
{
}

Log::~Log()
{
	DateTime time;
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		_listeners[i]->OnLogEnd( time );
	}
}

void Log::Listen( LogListener* listener )
{
	assert ( listener != nullptr );

	_listeners.Add( listener );
	listener->OnLogStart( _time );

	// Send deferred log entries to listener.
	for ( UInt i = 0; i < _entries.Size(); ++i )
	{
		LogEntry& entry = _entries[i];

		if ( _level > entry.Priority )
			continue;

		if ( _mode.IsNotSet(entry.Type) )
			continue;

		if ( entry.Type == LogMode::Info )
		{
			listener->OnLogInfo( entry.Thread, entry.Facility, entry.Time, entry.Text );
		}
		else if ( entry.Type == LogMode::Warning )
		{
			listener->OnLogWarning( entry.Thread, entry.Facility, entry.Time, entry.Text );
		}
		else if ( entry.Type == LogMode::Error )
		{
			listener->OnLogError( entry.Thread, entry.Facility, entry.Time, entry.Text );
		}
	}
}

void Log::InfoStart( const LogFacility& facility, const MessagePriority& priority, const String& text )
{
	if ( AllowMessage(priority, LogMode::Info) )
	{
		EmitInfoStart( facility, priority, text );
	}
}

void Log::InfoStart( const LogFacility& facility, const MessagePriority& priority, const Formatter& text )
{
	if ( AllowMessage(priority, LogMode::Info) )
	{
		EmitInfoStart( facility, priority, text.ToString() );
	}
}

void Log::InfoContinue( const String& text )
{
	if ( AllowContinueMessage() )
	{
		ContinueInfo( text );
	}
}

void Log::InfoContinue( const Formatter& text )
{
	if ( AllowContinueMessage() )
	{
		ContinueInfo( text.ToString() );
	}
}

void Log::InfoEnd( const String& text )
{
	if ( AllowContinueMessage() )
	{
		EndInfo( text );
	}
}

void Log::InfoEnd( const Formatter& text )
{
	if ( AllowContinueMessage() )
	{
		EndInfo( text.ToString() );
	}
}

void Log::Info( const LogFacility& facility, const MessagePriority& priority, const String& text )
{
	if ( AllowMessage(priority, LogMode::Info) )
	{
		EmitInfo( facility, priority, text );
	}
}

void Log::Info( const LogFacility& facility, const MessagePriority& priority, const Formatter& text )
{
	if ( AllowMessage(priority, LogMode::Info) )
	{
		EmitInfo( facility, priority, text.ToString() );
	}
}

void Log::Warning( const LogFacility& facility, const MessagePriority& priority, const String& text )
{
	if ( AllowMessage(priority, LogMode::Warning) )
	{
		EmitWarning( facility, priority, text );
	}
}

void Log::Warning( const LogFacility& facility, const MessagePriority& priority, const Formatter& text )
{
	if ( AllowMessage(priority, LogMode::Warning) )
	{
		EmitWarning( facility, priority, text.ToString() );
	}
}

void Log::Error( const LogFacility& facility, const MessagePriority& priority, const String& text )
{
	if ( AllowMessage(priority, LogMode::Error) )
	{
		EmitError( facility, priority, text );
	}
}

void Log::Error( const LogFacility& facility, const MessagePriority& priority, const Formatter& text )
{
	if ( AllowMessage(priority, LogMode::Error) )
	{
		EmitError( facility, priority, text.ToString() );
	}
}

void Log::Initialize( const LogLevel& level, const LogMode& mode )
{
	_level = level;
	_mode = mode;
}

Bool Log::AllowContinueMessage()
{
	if ( !_started )
		return false;

	if ( _paused )
		return false;

	return true;
}

Bool Log::AllowMessage( const MessagePriority& priority, const LogMode& type )
{
	if ( _paused )
		return false;

	if ( _level > priority )
		return false;

	if ( _mode.IsNotSet(type) )
		return false;

	return true;
}

void Log::EmitInfoStart( const LogFacility& facility, const MessagePriority& priority, const String& text )
{
	SEMAPHORE_LOCK( _lock );

	DateTime time;
	const UInt thread = Thread::CurrentID();
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		_listeners[i]->OnLogInfoStart( thread, facility, time, text );
	}

	if ( _listeners.IsEmpty() )
	{
		_entries.Add( LogEntry(thread, LogMode::Info, facility, priority, time, text) );
	}

	_started = true;
}

void Log::ContinueInfo( const String& text )
{
	SEMAPHORE_LOCK( _lock );

	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		_listeners[i]->OnLogInfoContinue( text );
	}

	if ( _listeners.IsEmpty() )
	{
		_entries.Last()->Text = _entries.Last()->Text.Append( text );
	}
}

void Log::EndInfo( const String& text )
{
	SEMAPHORE_LOCK( _lock );

	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		_listeners[i]->OnLogInfoEnd( text );
	}

	if ( _listeners.IsEmpty() )
	{
		_entries.Last()->Text = _entries.Last()->Text.Append( text );
	}

	_started = false;
}

void Log::EmitInfo( const LogFacility& facility, const MessagePriority& priority, const String& text )
{
	SEMAPHORE_LOCK( _lock );

	DateTime time;
	const UInt thread = Thread::CurrentID();
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		_listeners[i]->OnLogInfo( thread, facility, time, text );
	}

	if ( _listeners.IsEmpty() )
	{
		_entries.Add( LogEntry(thread, LogMode::Info, facility, priority, time, text) );
	}
}

void Log::EmitWarning( const LogFacility& facility, const MessagePriority& priority, const String& text )
{
	SEMAPHORE_LOCK( _lock );

	DateTime time;
	const UInt thread = Thread::CurrentID();
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		_listeners[i]->OnLogWarning( thread, facility, time, text );
	}

	if ( _listeners.IsEmpty() )
	{
		_entries.Add( LogEntry(thread, LogMode::Warning, facility, priority, time, text) );
	}
}

void Log::EmitError( const LogFacility& facility, const MessagePriority& priority, const String& text )
{
	SEMAPHORE_LOCK( _lock );

	DateTime time;
	const UInt thread = Thread::CurrentID();
	for ( UInt i = 0; i < _listeners.Size(); ++i )
	{
		_listeners[i]->OnLogError( thread, facility, time, text );
	}

	if ( _listeners.IsEmpty() )
	{
		_entries.Add( LogEntry(thread, LogMode::Error, facility, priority, time, text) );
	}
}


} // diag


} // synkro
