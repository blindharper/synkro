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
SYNKRO_INLINE void PlainLogFile::OnLogInfoStart( UInt thread, const diag::LogFacility& facility, const lang::DateTime& time, const lang::String& text )
{
	Write( lang::String::Format(L"[{0,00}] {1,o} {2} {3}: {4} ", thread, time, facility.ToString(), L"   INFO", text) );
}

SYNKRO_INLINE void PlainLogFile::OnLogInfoContinue( const lang::String& text )
{
	Write( text );
}

SYNKRO_INLINE void PlainLogFile::OnLogInfoEnd( const lang::String& text )
{
	WriteLine( text );
}

SYNKRO_INLINE void PlainLogFile::OnLogInfo( UInt thread, const diag::LogFacility& facility, const lang::DateTime& time, const lang::String& text )
{
	WriteLine( lang::String::Format(L"[{0,00}] {1,o} {2} {3}: {4}", thread, time, facility.ToString(), L"   INFO", text) );
}

SYNKRO_INLINE void PlainLogFile::OnLogWarning( UInt thread, const diag::LogFacility& facility, const lang::DateTime& time, const lang::String& text )
{
	WriteLine( lang::String::Format(L"[{0,00}] {1,o} {2} {3}: {4}", thread, time, facility.ToString(), L"WARNING", text) );
}

SYNKRO_INLINE void PlainLogFile::OnLogError( UInt thread, const diag::LogFacility& facility, const lang::DateTime& time, const lang::String& text )
{
	WriteLine( lang::String::Format(L"[{0,00}] {1,o} {2} {3}: {4}", thread, time, facility.ToString(), L"  ERROR", text) );
}
