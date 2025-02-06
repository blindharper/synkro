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
// Purpose: Implements rich log file.
//==============================================================================
#include "config.h"
#include "RichLogFile.h"


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


RichLogFile::RichLogFile( const String& version, IStream* stream, UInt maxSize, Bool append ) :
	TextWriter( stream, "UTF-8", append, true ),
	_string( A(Char) ),
	_started( false ),
	_ended( false ),
	_maxSize( maxSize ),
	_version( version )
{
}

void RichLogFile::OnLogStart( const DateTime& time )
{
	// Prevent emitting multiple start messages.
	if ( _started )
		return;

	_started = true;

	// Check for maximum log size.
	if ( (_maxSize > 0) && (GetStream()->GetLength() > _maxSize*1024) )
	{
		GetStream()->Close();
		GetStream()->Open( OpenMode::Write );
	}

	// Optionally write log header.
	if ( GetStream()->GetMode().IsNotSet(OpenMode::Append) || (GetStream()->GetLength() == 0) )
	{
		WriteLine( L"<html>" );
		WriteLine( L"<head>" );
		WriteLine( L"<title>Synkro Log</title>" );
		WriteLine( L"<style>" );
		WriteLine( L"body { background-color:#000000; color:#ffffff; font-family:Courier; font-size:1em; }" );
		WriteLine( L"::selection { background: #5e011f; color:#ffffff; }" );
		WriteLine( L".centered { text-align:center; }" );
		WriteLine( L".thread { color:#ffa500; }" );
		WriteLine( L".time { color:#8a0000; padding-right:8px; }" );
		WriteLine( L".facility { color:#696969; padding-right:8px; }" );
		WriteLine( L".info { color:#51a635; }" );
		WriteLine( L".warning { color:#ffff00; }" );
		WriteLine( L".error { color:#ff0000; }" );
		WriteLine( L".num { color:#ff0000; }" );
		WriteLine( L".string { color:#bfbfbf; }" );
		WriteLine( L"</style>" );
		WriteLine( L"</head>" );
		WriteLine( L"<body>" );
	}

	// Write log table start.
	WriteLine( String::Format(L"<hr><div class='centered'>Synkro {0}</div><br>", _version) );
	WriteLine( String::Format(L"<div class='centered'>{0,r}</div><hr>", time) );
	WriteLine( L"<table border='0'>" );
	Write( L"<tr><td class='thread'>THREAD</td>" );
	Write( L"<td class='time'>TIMESTAMP</td>" );
	Write( L"<td class='facility'>FACILITY</td>" );
	WriteLine( L"<td class='info'>MESSAGE</td></tr>" );
}

void RichLogFile::OnLogEnd( const DateTime& time )
{
	// Prevent emitting multiple end messages.
	if ( !_ended )
	{
		_ended = true;
		WriteLine( L"</table>" );
		WriteLine( L"<hr><div class='centered'>End of log</div><hr>" );
		WriteLine( L"</body>" );
		WriteLine( L"</html>" );
	}
}

void RichLogFile::OnLogInfoStart( UInt thread, const LogFacility& facility, const DateTime& time, const String& text )
{
	Write( String::Format(L"<tr><td class='thread'>{0}</td>", thread) );
	Write( String::Format(L"<td class='time'>{0,o}</td>", time) );
	Write( String::Format(L"<td class='facility'>{0}</td>", facility.ToString().Trim()) );
	Write( String::Format(L"<td class='info'>{0} ", Preprocess(text)) );
}

void RichLogFile::OnLogInfoContinue( const String& text )
{
	Write( Preprocess(text) );
}

void RichLogFile::OnLogInfoEnd( const String& text )
{
	WriteLine( String::Format(L" {0}</td></tr>", Preprocess(text)) );
}

void RichLogFile::OnLogInfo( UInt thread, const LogFacility& facility, const DateTime& time, const String& text )
{
	Write( String::Format(L"<tr><td class='thread'>{0}</td>", thread) );
	Write( String::Format(L"<td class='time'>{0,o}</td>", time) );
	Write( String::Format(L"<td class='facility'>{0}</td>", facility.ToString().Trim()) );
	WriteLine( String::Format(L"<td class='info'>{0}</td></tr>", Preprocess(text)) );
}

void RichLogFile::OnLogWarning( UInt thread, const LogFacility& facility, const DateTime& time, const String& text )
{
	Write( String::Format(L"<tr><td class='thread'>{0}</td>", thread) );
	Write( String::Format(L"<td class='time'>{0,o}</td>", time) );
	Write( String::Format(L"<td class='facility'>{0}</td>", facility.ToString().Trim()) );
	WriteLine( String::Format(L"<td class='warning'>{0}</td></tr>", text) );
}

void RichLogFile::OnLogError( UInt thread, const LogFacility& facility, const DateTime& time, const String& text )
{
	Write( String::Format(L"<tr><td class='thread'>{0}</td>", thread) );
	Write( String::Format(L"<td class='time'>{0,o}</td>", time) );
	Write( String::Format(L"<td class='facility'>{0}</td>", facility.ToString().Trim()) );
	WriteLine( String::Format(L"<td class='error'>{0}</td></tr>", text) );
}

String RichLogFile::Preprocess( const String& text )
{
	StringClear();

	Bool insideNumber = false;
	Bool insideQuotes = false;
	for ( UInt i = 0; i < text.Length(); ++i )
	{
		const Char c = text[i];
		switch ( c )
		{
			case L'0': case L'1': case L'2': case L'3': case L'4':
			case L'5': case L'6': case L'7': case L'8': case L'9':
				if ( !insideNumber && !insideQuotes )
				{
					StringAppend( L"<span class='num'>" );
					insideNumber = true;
				}
				StringAppend( c );
				break;

			case L'\'':
				StringAppend( insideQuotes ? L"'</span>" : L"<span class='string'>'" );
				insideQuotes = !insideQuotes;
				break;

			default:
				if ( insideNumber )
				{
					StringAppend( L"</span>" );
					insideNumber = false;
				}
				StringAppend( c );
				break;
		}
	}
	if ( insideNumber )
	{
		StringAppend( L"</span>" );
	}

	return StringGet();
}

void RichLogFile::StringClear()
{
	_string.Clear();
}

void RichLogFile::StringAppend( Char ch )
{
	_string.Add( ch );
}

void RichLogFile::StringAppend( const Char* text )
{
	if ( text != nullptr )
	{
		_string.Add( text, CastUInt(wcslen(text)) );
	}
}

String RichLogFile::StringGet()
{
	if ( _string.Size() > 0 )
	{
		if ( _string.LastValue() != 0 )
		{
			_string.Add( 0 );
		}
		return String( _string.Begin() );
	}
	return String::Empty;
}


} // core


} // synkro
