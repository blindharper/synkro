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
#ifndef _SYNKRO_INTERNAL_LOGGER_
#define _SYNKRO_INTERNAL_LOGGER_


#include "config.h"
#include <diag/ILog.h>


// Starts a message.
#define LogInfoStart( PRIO, TXT ) InfoStart( PRIO, TXT )
// Continues previously started message.
#define LogInfoContinue( TXT ) InfoContinue( TXT )
// Ends previously started message.
#define LogInfoEnd( TXT ) InfoEnd( TXT )
// Emits a message.
#define LogInfo( PRIO, TXT ) Info( PRIO, TXT )
// Emits an error.
#define LogError( PRIO, TXT ) Error( PRIO, TXT )
// Emits a warning.
#define LogWarning( PRIO, TXT ) Warning( PRIO, TXT )


// Helper object to simplify logging. Classes that need
// logging capability should be derived from this class.
class SYNKRO_API Logger
{
public:
	// Binds logger to the specified log.
	Logger( synkro::diag::ILog* log, const synkro::diag::LogFacility& facility );

	void													InfoStart( const synkro::diag::MessagePriority& priority, const synkro::lang::String& text ) const;
	void													InfoStart( const synkro::diag::MessagePriority& priority, const synkro::lang::Formatter& text ) const;
	void													InfoContinue( const synkro::lang::String& text ) const;
	void													InfoContinue( const synkro::lang::Formatter& text ) const;
	void													InfoEnd( const synkro::lang::String& text ) const;
	void													InfoEnd( const synkro::lang::Formatter& text ) const;
	void													Info( const synkro::diag::MessagePriority& priority, const synkro::lang::String& text ) const;
	void													Info( const synkro::diag::MessagePriority& priority, const synkro::lang::Formatter& text ) const;
	void													Error( const synkro::diag::MessagePriority& priority, const synkro::lang::String& text ) const;
	void													Error( const synkro::diag::MessagePriority& priority, const synkro::lang::Formatter& text ) const;
	void													Warning( const synkro::diag::MessagePriority& priority, const synkro::lang::String& text ) const;
	void													Warning( const synkro::diag::MessagePriority& priority, const synkro::lang::Formatter& text ) const;

protected:
	mutable synkro::diag::ILog*								_log;
	synkro::diag::LogFacility								_facility;
};


#include "Logger.inl"


#endif // _SYNKRO_INTERNAL_LOGGER_
