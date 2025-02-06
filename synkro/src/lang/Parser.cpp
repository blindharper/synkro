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
// Purpose: Implements text parser.
//==============================================================================
#include "config.h"
#include "Parser.h"
#include <lang/Exception.h>


namespace synkro
{


namespace lang
{


static Bool MatchConstant( const String& text, UInt pos, const Char* str, UInt strLength )
{
	for ( UInt i = 0; i < strLength; ++i )
	{
		if ( text[pos+i] != str[i] )
			return false;
	}
	return true;
}

static UInt ParseInt( const String& text, UInt pos, Int* arg )
{
	*arg = 0;
	UInt cnt = 0;

	for ( UInt i = pos; i < text.Length(); ++i )
	{
		if ( iswdigit(text[i]) || (text[i] == L'-') )
			++cnt;
		else
			break;
	}

	Int num = 0;
	Char chars[64] = {};
	text.GetChars( pos, cnt, chars );
	swscanf( chars, L"%d", &num );
	*arg = num;

	return cnt;
}

static UInt ParseFloat( const String& text, const Char* format, UInt formatLength, UInt pos, Double* arg )
{
	*arg = 0.0;
	UInt cnt = 0;

	for ( UInt i = pos; i < text.Length(); ++i )
	{
		if ( iswdigit(text[i]) || (text[i] == L'.') || (text[i] == L'-') )
			++cnt;
		else
			break;
	}

	UInt maxFracDigits	= 0;
	Bool fraction = false;
	for ( UInt i = 0; i < formatLength; ++i )
	{
		switch ( format[i] )
		{
			case L'.':
				fraction = true;
				break;

			case L'0':
				// Compulsory digit.
				if ( fraction )
					++maxFracDigits;
				break;
		}
	}

	Double num = 0;
	Char chars[64] = {};
	Char fmt[32] = {};
	swprintf_s( fmt, 32, L"%%%if", maxFracDigits );
	text.GetChars( pos, cnt, chars );
	swscanf( chars, L"%lf", &num );
	*arg = num;

	return cnt;
}

static UInt ParseString( const String& text, UInt pos, String* arg )
{
	*arg = String::Null;
	UInt cnt = 0;

	for ( UInt i = pos; i < text.Length(); ++i )
	{
		if ( iswalnum(text[i]) )
			++cnt;
		else
			break;
	}

	*arg = text.Substring( pos, cnt );

	return cnt;
}

//------------------------------------------------------------------------------

Parser::Parser( const Char* pattern )
{
	Prepare( pattern );
}

Bool Parser::ParseText( const String& text )
{
	// Reset mappings.
	for ( UInt i = 0; i < _argCount; ++i )
	{
		Parseable& arg = _args[i];
		switch ( arg._type )
		{
			case Parseable::VALUE_INTEGER:
				*arg._int = 0;
				break;

			case Parseable::VALUE_FLOAT:
				*arg._float = 0.0;
				break;

			case Parseable::VALUE_STRING:
				*arg._string = String::Null;
				break;
		}
	}

	// Try to match entries.
	UInt pos = 0;
	for ( UInt i = 0; i < _entryCount; ++i )
	{
		const PatternEntry& en = _entries[i];
		if ( en.Type == ENTRY_TEXT )
		{
			if ( !MatchConstant(text, pos, en.Text, en.TextLength) )
				return false;

			pos += en.TextLength;
		}
		else if ( en.Type == ENTRY_ARGUMENT )
		{
			// Validate argument index.
			const UInt argIdx = en.Index;
			assert( argIdx < _argCount );
			if ( argIdx >= _argCount )
				throw Exception( String::Format(L"Bad parsing pattern. Invalid argument index: {0}.", argIdx) );

			UInt res = 0;
			switch( _args[argIdx]._type )
			{
				case Parseable::VALUE_INTEGER:
					res = ParseInt( text, pos, _args[argIdx]._int );
					break;

				case Parseable::VALUE_FLOAT:
					res = ParseFloat( text, en.Text, en.TextLength, pos, _args[argIdx]._float );
					break;

				case Parseable::VALUE_STRING:
					res = ParseString( text, pos, _args[argIdx]._string );
					break;

				default:
					break;
			}

			// If no match found - return error.
			if ( res == 0 )
				return false;

			// Move further.
			pos += res;
		}
	}

	return true;
}

void Parser::Prepare( const Char* pattern )
{
	// Reset internal state.
	_argCount = 0;
	_entryCount = 0;
	for ( UInt i = 0; i < MAX_ARG_COUNT; ++i )
	{
		_args[i] = Parseable();
	}

	// Validate parameter.
	assert( pattern != nullptr );
	if ( pattern == nullptr )
		throw Exception( L"Invalid parser pattern." );

	// Parse pattern.
	const UInt patternLen = CastUInt( wcslen(pattern) );
	UInt org = 0;
	UInt argStart = 0;
	UInt argEnd = 0;

	while ( org < patternLen )
	{
		const Char* idxStart = wcschr( pattern+org, L'{' );
		if ( idxStart == nullptr )
			break;

		argStart = idxStart - pattern;
		if ( argStart > argEnd+1 )
		{
			_entries[_entryCount++] = PatternEntry( pattern+org, argStart-argEnd-1 );
		}

		const Char* idxEnd = wcschr( pattern+argStart+1, L'}' );
		if ( idxEnd == nullptr )
			throw Exception( L"Bad parsing pattern. Closing brace is missing." );

		argEnd = idxEnd - pattern;
		org = argEnd + 1;

		// Extract formatting options.
		const Char* options = nullptr;
		UInt optionsLength = 0;
		const Char* idxOpt = wcschr( pattern+argStart+1, L',' );
		if ( idxOpt != nullptr )
		{
			const UInt optIdx = idxOpt - pattern;
			if ( optIdx < argEnd )
			{
				options = pattern+optIdx+1;
				optionsLength = argEnd-optIdx-1;
			}
		}

		// Extract argument index.
		UInt argIdx = 0;
		Char chars[64] = {};
		for ( UInt i = 0; i < argEnd-argStart+1; ++i )
		{
			chars[i] = pattern[argStart+i];
		}
		swscanf( chars, L"{%d}", &argIdx );
		_entries[_entryCount++] = PatternEntry( argIdx, options, optionsLength );
		++_argCount;
	}
}

void Parser::Map( const Parseable* args, UInt argCount )
{
	assert( args != nullptr );
	assert( argCount == _argCount );

	for ( UInt i = 0; i < _argCount; ++i )
	{
		_args[i] = args[i];
	}
}


} // lang


} // synkro
