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
// Purpose: Implements plain log file.
//==============================================================================
#ifndef _SYNKRO_CORE_PLAINLOGFILE_
#define _SYNKRO_CORE_PLAINLOGFILE_


#include "config.h"
#include "ObjectImpl.h"
#include <diag/LogListener.h>
#include <io/TextWriter.h>


namespace synkro
{


namespace core
{


// LogListener implementation.
class PlainLogFile :
	public ObjectImpl<IObject>,
	public diag::LogListener,
	public io::TextWriter
{
public:
	// Constructor.
	PlainLogFile( const lang::String& version, io::IStream* stream, UInt maxSize, Bool append );

	// LogListener methods.
	void													OnLogStart( const lang::DateTime& time );
	void													OnLogEnd( const lang::DateTime& time );
	void													OnLogInfoStart( UInt thread, const diag::LogFacility& facility, const lang::DateTime& time, const lang::String& text );
	void													OnLogInfoContinue( const lang::String& text );
	void													OnLogInfoEnd( const lang::String& text );
	void													OnLogInfo( UInt thread, const diag::LogFacility& facility, const lang::DateTime& time, const lang::String& text );
	void													OnLogWarning( UInt thread, const diag::LogFacility& facility, const lang::DateTime& time, const lang::String& text );
	void													OnLogError( UInt thread, const diag::LogFacility& facility, const lang::DateTime& time, const lang::String& text );

private:
	Bool													_started;
	Bool													_ended;
	UInt													_maxSize;
	lang::String											_version;
};


#include "PlainLogFile.inl"


} // core


} // synkro


#endif // _SYNKRO_CORE_PLAINLOGFILE_
