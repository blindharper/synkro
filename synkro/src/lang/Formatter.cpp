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
// Purpose: Implements string formatter.
//==============================================================================
#include "config.h"
#include <lang/Formatter.h>
#include <lang/Vector.h>
#include <lang/Exception.h>
#include <internal/Zero.h>
#include <internal/SizeOf.h>
#include <internal/Months.h>
#include <internal/Weekdays.h>


namespace synkro
{


namespace lang
{



static void FormatNumber( Vector<Char>& buffer, const Char* format, UInt formatLength, Double arg )
{
	// Parse formatting options.
	constexpr Int absMaxIntDigits = 20;
	UInt minIntDigits	= 0;
	UInt maxIntDigits	= 0;
	UInt minFracDigits	= 0;
	UInt maxFracDigits	= 0;
	Bool fraction		= false;
	char hex			= 0;	
	
	for ( UInt i = 0; i < formatLength; ++i )
	{
		switch ( format[i] )
		{
			case L'x': case L'X':
				hex = char(format[i]);
				break;

			case L'.':
				fraction = true;
				break;

			case L'0':
				// Compulsory digit.
				if ( fraction )
					++minFracDigits, ++maxFracDigits;
				else
					++minIntDigits, maxIntDigits=absMaxIntDigits;
				break;

			case L'#':
				// Optional digit.
				if ( fraction )
					++maxFracDigits;
				else
					maxIntDigits=absMaxIntDigits;
				break;
		}
	}

	// Apply formatting.
	Bool chopInt = false;
	Char fmt[32] = {};

	if ( hex )
		swprintf_s( fmt, 32, L"%%%c", hex ), chopInt = true;
	else if ( (maxFracDigits == 0) && (maxIntDigits == 0) )
		swprintf_s( fmt, 32, L"%%g" );
	else if ( minIntDigits > 0 )
		swprintf_s( fmt, 32, L"%%0%i.%if", minIntDigits, maxFracDigits );
	else
		swprintf_s( fmt, 32, L"%%.%if", maxFracDigits );

	Char buf[64] = {};
	if ( chopInt )
		swprintf_s( buf, 64, fmt, CastInt(arg) );
	else
		swprintf_s( buf, 64, fmt, arg );

	// Append to output buffer.
	buffer.Add( buf, CastUInt(wcslen(buf)) );
}

static void FormatString( Vector<Char>& buffer, const Char* format, UInt formatLength, const String& arg )
{
	// Parse formatting options.
	Bool toUpperCase = false;
	Bool toLowerCase = false;
	Bool toQuotedStr = false;
	
	for ( UInt i = 0; i < formatLength; ++i )
	{
		switch ( format[i] )
		{
			case L'l': case L'L':
				toLowerCase = true;
				break;

			case L'u': case L'U':
				toUpperCase = true;
				break;

			case L'q': case L'Q':
				toQuotedStr = true;
				break;
		}
	}

	// Apply formatting.
	String str = arg;

	if ( toUpperCase )
		str = str.ToUpper();
	else if ( toLowerCase )
		str = str.ToLower();

	if ( toQuotedStr )
		buffer.Add( L'\'' );

	for ( UInt i = 0; i < str.Length(); ++i )
	{
		buffer.Add( str[i]);
	}

	if ( toQuotedStr )
		buffer.Add( L'\'' );
}

static void FormatDateTime( Vector<Char>& buffer, const Char* format, UInt formatLength, const DateTime& arg )
{
	// Parse formatting options.
	Char fmt = L'G';
	if ( formatLength > 0 )
	{
		fmt = format[0];
	}

	// Apply formatting.
	constexpr UInt BUF_SIZE = 64;
	Char buf[BUF_SIZE] = {};
	switch ( fmt )
	{
		case L'd': swprintf_s( buf, BUF_SIZE, L"%02d/%02d/%4d", arg.Month(), arg.Day(), arg.Year() ); break;
		case L'D': swprintf_s( buf, BUF_SIZE, L"%s, %s %d, %d", WeekdaysLong[arg.DayOfWeek()], MonthsLong[arg.Month()], arg.Day(), arg.Year() ); break;
		case L'f': swprintf_s( buf, BUF_SIZE, L"%s, %s %d, %d %02d:%02d", WeekdaysLong[arg.DayOfWeek()], MonthsLong[arg.Month()], arg.Day(), arg.Year(), arg.Hour(), arg.Minute() ); break;
		case L'F': swprintf_s( buf, BUF_SIZE, L"%s, %s %d, %d %02d:%02d:%02d", WeekdaysLong[arg.DayOfWeek()], MonthsLong[arg.Month()], arg.Day(), arg.Year(), arg.Hour(), arg.Minute(), arg.Second() ); break;
		case L'g': swprintf_s( buf, BUF_SIZE, L"%2d/%2d/%4d %02d:%02d", arg.Month(), arg.Day(), arg.Year(), arg.Hour(), arg.Minute() ); break;
		case L'r': swprintf_s( buf, BUF_SIZE, L"%s %s %d %d %02d:%02d:%02d", WeekdaysShort[arg.DayOfWeek()], MonthsShort[arg.Month()], arg.Day(), arg.Year(), arg.Hour(), arg.Minute(), arg.Second() ); break;
		case L'R': swprintf_s( buf, BUF_SIZE, L"%4d%02d%02d", arg.Year(), arg.Month(), arg.Day() ); break;
		case L't': swprintf_s( buf, BUF_SIZE, L"%02d:%02d", arg.Hour(), arg.Minute() ); break;
		case L'T': swprintf_s( buf, BUF_SIZE, L"%02d:%02d:%02d", arg.Hour(), arg.Minute(), arg.Second() ); break;
		case L'u': swprintf_s( buf, BUF_SIZE, L"%02d%02d%02d", arg.Hour(), arg.Minute(), arg.Second() ); break;
		case L'o': swprintf_s( buf, BUF_SIZE, L"%02d:%02d:%02d.%03d", arg.Hour(), arg.Minute(), arg.Second(), arg.Millisecond() ); break;
		default:   swprintf_s( buf, BUF_SIZE, L"%4d-%02d-%02d %02d:%02d:%02d.%03d", arg.Year(), arg.Month(), arg.Day(), arg.Hour(), arg.Minute(), arg.Second(), arg.Millisecond() ); break;
	}

	// Append to output buffer.
	buffer.Add( buf, CastUInt(wcslen(buf)) );
}

//------------------------------------------------------------------------------

Formatter::Formatter( const Char* pattern ) :
	_pattern( pattern ),
	_prepared( false )
{
}

String Formatter::ToString() const
{
	if ( _pattern == nullptr )
		return String::Empty;

	Prepare();

	Vector<Char> buffer( A(Char), 2*CastUInt(wcslen(_pattern)) );

	// Format entries.
	for ( UInt i = 0; i < _entryCount; ++i )
	{
		const PatternEntry& en = _entries[i];
		if ( en.Type == ENTRY_TEXT )
		{
			buffer.Add( en.Text, en.TextLength );
		}
		else if ( en.Type == ENTRY_ARGUMENT )
		{
			// Validate argument index.
			const UInt argIdx = en.Index;
			assert( argIdx < _argCount );
			if ( argIdx >= _argCount )
				throw Exception( String::Format(L"Bad formatting pattern. Invalid argument index: {0}.", argIdx) );

			switch ( _args[argIdx]._type )			
			{
				case Formattable::VALUE_NUMBER:
					FormatNumber( buffer, en.Text, en.TextLength, _args[argIdx]._number );
					break;

				case Formattable::VALUE_ANSI:
					FormatString( buffer, en.Text, en.TextLength, _args[argIdx]._ansi );
					break;

				case Formattable::VALUE_UNICODE:
					FormatString( buffer, en.Text, en.TextLength, _args[argIdx]._unicode );
					break;

				case Formattable::VALUE_DATETIME:
					FormatDateTime( buffer, en.Text, en.TextLength, _args[argIdx]._dateTime );
					break;

				default:
					break;
			}
		}
	}

	buffer.Add( L'\0' );
	return String( buffer.Begin() );
}

void Formatter::Map( const Formattable& arg0 )
{
	Formattable args[] = { arg0 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1 )
{
	Formattable args[] = { arg0, arg1 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2 )
{
	Formattable args[] = { arg0, arg1, arg2 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4, arg5 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13, const Formattable& arg14 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14 };
	Map( args, SizeOf(args) );
}

void Formatter::Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13, const Formattable& arg14, const Formattable& arg15 )
{
	Formattable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15 };
	Map( args, SizeOf(args) );
}

Formatter Formatter::Format( const Char* pattern )
{
	Formatter f( pattern );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0 )
{
	Formatter f( pattern );
	f.Map( arg0 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4, arg5 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13, const Formattable& arg14 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14 );
	return f;
}

Formatter Formatter::Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13, const Formattable& arg14, const Formattable& arg15 )
{
	Formatter f( pattern );
	f.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15 );
	return f;
}

void Formatter::Prepare() const
{
	if ( _prepared )
		return;

	// Reset internal state.
	_entryCount = 0;
	_argCount = 0;

	// Validate parameter.
	assert( _pattern != nullptr );
	if ( _pattern == nullptr )
		throw Exception( L"Invalid formatting pattern." );

	// Parse pattern.
	const UInt patternLen = CastUInt( wcslen(_pattern) );
	UInt org = 0;
	UInt argStart = 0;
	UInt argEnd = 0;

	while ( org < patternLen )
	{
		const Char* idxStart = wcschr( _pattern+org, L'{' );
		if ( idxStart == nullptr )
		{
			_entries[_entryCount++] = PatternEntry( _pattern+org, patternLen-org );
			break;
		}

		argStart = idxStart - _pattern;
		if ( argStart > argEnd )
		{
			const UInt delta = (org == 0) ? 0 : 1;
			_entries[_entryCount++] = PatternEntry( _pattern+org, argStart-argEnd-delta );
		}

		const Char* idxEnd = wcschr( _pattern+argStart+1, L'}' );
		if ( idxEnd == nullptr )
			throw Exception( L"Bad formatting pattern. Closing brace is missing." );

		argEnd = idxEnd - _pattern;
		org = argEnd + 1;

		// Extract formatting options.
		const Char* options = nullptr;
		UInt optionsLength = 0;
		const Char* idxOpt = wcschr( _pattern+argStart+1, L',' );
		if ( idxOpt != nullptr )
		{
			const UInt optIdx = idxOpt - _pattern;
			if ( optIdx < argEnd )
			{
				options = _pattern+optIdx+1;
				optionsLength = argEnd-optIdx-1;
			}
		}

		// Extract argument index.
		UInt argIdx = 0;
		Char chars[64] = {};
		for ( UInt i = 0; i < argEnd-argStart+1; ++i )
		{
			chars[i] = _pattern[argStart+i];
		}
		swscanf( chars, L"{%d}", &argIdx );
		_entries[_entryCount++] = PatternEntry( argIdx, options, optionsLength );
		++_argCount;
	}

	_prepared = true;
}

void Formatter::Map( const Formattable* args, UInt argCount )
{
	for ( UInt i = 0; i < argCount; ++i )
	{
		_args[i] = args[i];
	}
}


} // lang


} // synkro
