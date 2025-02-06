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
// Purpose: Wildcard mask.
//==============================================================================
#include "config.h"
#include "Mask.h"


namespace synkro
{


namespace lang
{


Mask::Mask( const String& pattern )
{
	// Remove duplicate wildcards.
	for ( UInt i = 0; i < pattern.Length(); ++i )
	{
		const Char c = pattern[i];
		if ( (c == L'*') && _pattern.EndsWith(L'*') )
			continue;

		_pattern = _pattern.Append( c );
	}
	_pattern = _pattern.ToLower();
}

Bool Mask::Matches( const String& text ) const
{
	return MatchesPattern( _pattern, text.ToLower() );
}

Bool Mask::IsWildcard( Char c )
{
	return (c == L'*') || (c == L'?');
}

String Mask::GetNonWildcardString( const String& pattern, UInt pos )
{
	if ( pos >= pattern.Length() )
		return String::Empty;

	String res;
	for ( UInt i = pos; i < pattern.Length(); ++i )
	{
		if ( IsWildcard(pattern[i]) )
			break;

		res = res.Append( pattern[i] );
	}
	return res;
}

Bool Mask::MatchesPattern( const String& pattern, const String& text )
{
	if ( pattern.IsEmpty() && text.IsEmpty() )
		return true;

	const UInt len = text.Length();
	if ( len < 1 )
		return false;

	UInt pos = 0; // Index in the text.
	Int res = -1; // Holds match test result.
	UInt idx = none;
	String s;
	for ( UInt i = 0; i < pattern.Length(); ++i )
	{
		const Char c = pattern[i];

		if ( IsWildcard(c) )
		{
			switch ( c )
			{
				case L'*':
					if ( i == pattern.Length()-1 )
						return true;

					idx = text.Length();
					s = GetNonWildcardString( pattern, i+1 );
					while ( (idx = text.LastIndexOf(s, idx-1)) != none )
					{
						if ( idx < pos )
							return false;

						if ( MatchesPattern(pattern.Substring(i+1+s.Length()), text.Substring(idx+s.Length())) )
							return true;

						if ( idx == 0 )
							return false;
					}
					break;

				case L'?': res = 1; break;
			}
		}
		else // Non-wildcard characters.
		{
			res = (text[pos] == c) ? 1 : -1;
		}

		// If no match found, return error.
		if ( res == -1 )
			return false;

		// Move forward by read number of chars.
		pos += res;

		// If we reached the end of the string then the match is found.
		if ( (CastUInt(pos) >= len) && (i+1 >= pattern.Length()) )
			return true;
	}
	return false;
}


} // lang


} // synkro
