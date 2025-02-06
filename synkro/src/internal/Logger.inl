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
// Purpose: Defines application logger.
//==============================================================================
SYNKRO_INLINE Logger::Logger( synkro::diag::ILog* log, const synkro::diag::LogFacility& facility ) :
	_log( log ),
	_facility( facility )
{
}

SYNKRO_INLINE void Logger::InfoStart( const synkro::diag::MessagePriority& priority, const synkro::lang::String& text ) const
{
	if ( _log != nullptr )
	{
		_log->InfoStart( _facility, priority, text );
	}
}

SYNKRO_INLINE void Logger::InfoStart( const synkro::diag::MessagePriority& priority, const synkro::lang::Formatter& text ) const
{
	if ( _log != nullptr )
	{
		_log->InfoStart( _facility, priority, text );
	}
}

SYNKRO_INLINE void Logger::InfoContinue( const synkro::lang::String& text ) const
{
	if ( _log != nullptr )
	{
		_log->InfoContinue( text );
	}
}

SYNKRO_INLINE void Logger::InfoContinue( const synkro::lang::Formatter& text ) const
{
	if ( _log != nullptr )
	{
		_log->InfoContinue( text );
	}
}

SYNKRO_INLINE void Logger::InfoEnd( const synkro::lang::String& text ) const
{
	if ( _log != nullptr )
	{
		_log->InfoEnd( text );
	}
}

SYNKRO_INLINE void Logger::InfoEnd( const synkro::lang::Formatter& text ) const
{
	if ( _log != nullptr )
	{
		_log->InfoEnd( text );
	}
}

SYNKRO_INLINE void Logger::Info( const synkro::diag::MessagePriority& priority, const synkro::lang::String& text ) const
{
	if ( _log != nullptr )
	{
		_log->Info( _facility, priority, text );
	}
}

SYNKRO_INLINE void Logger::Info( const synkro::diag::MessagePriority& priority, const synkro::lang::Formatter& text ) const
{
	if ( _log != nullptr )
	{
		_log->Info( _facility, priority, text );
	}
}

SYNKRO_INLINE void Logger::Error( const synkro::diag::MessagePriority& priority, const synkro::lang::String& text ) const
{
	if ( _log != nullptr )
	{
		_log->Error( _facility, priority, text );
	}
}

SYNKRO_INLINE void Logger::Error( const synkro::diag::MessagePriority& priority, const synkro::lang::Formatter& text ) const
{
	if ( _log != nullptr )
	{
		_log->Error( _facility, priority, text );
	}
}

SYNKRO_INLINE void Logger::Warning( const synkro::diag::MessagePriority& priority, const synkro::lang::String& text ) const
{
	if ( _log != nullptr )
	{
		_log->Warning( _facility, priority, text );
	}
}

SYNKRO_INLINE void Logger::Warning( const synkro::diag::MessagePriority& priority, const synkro::lang::Formatter& text ) const
{
	if ( _log != nullptr )
	{
		_log->Warning( _facility, priority, text );
	}
}
