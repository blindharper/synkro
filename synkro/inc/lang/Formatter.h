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
// Purpose: Defines string formatter.
//==============================================================================
#ifndef _SYNKRO_LANG_FORMATTER_
#define _SYNKRO_LANG_FORMATTER_


#include "config.h"
#include <lang/Formattable.h>
#include <lang/String.h>


namespace synkro
{


namespace lang
{


/** Formatted text.
 * 
 * Syntax of format string:
 * <ul>
 * <li>{0} = replaced with 1st argument formatted to string.
 * <li>{1} = replaced with 2nd argument formatted to string.
 * <li>{n} = replaced with n-th argument formatted to string.
 * <li>{0,l} = replaced with 1st argument formatted to lower case.
 * <li>{0,u} = replaced with 1st argument formatted to upper case.
 * <li>{0,q} = replaced with 1st argument formatted to quoted string.
 * <li>{0,x} = replaced with 1st argument formatted to hex number.
 * <li>{0,#.##} = replaced with 1st argument formatted to number using max 2 digits, e.g. 1.2=1.2 but 1.211=1.21.
 * <li>{0,#.00} = replaced with 1st argument formatted to number using exactly 2 digits, e.g. 1.2=1.20 and 1.211=1.21.
 * <li>{0,000} = replaced with 1st argument formatted to number using at least 3 numbers, padded with zeros, e.g. 3=003.
 * </ul>
 */
class SYNKRO_API Formatter
{
public:
	// Constructor.
	Formatter( const Char* pattern );

	// Methods.
	String														ToString() const;
	void														Map( const Formattable& arg0 );
	void														Map( const Formattable& arg0, const Formattable& arg1 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13, const Formattable& arg14 );
	void														Map( const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13, const Formattable& arg14, const Formattable& arg15 );

	static Formatter											Format( const Char* pattern );
	static Formatter											Format( const Char* pattern, const Formattable& arg0 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13, const Formattable& arg14 );
	static Formatter											Format( const Char* pattern, const Formattable& arg0, const Formattable& arg1, const Formattable& arg2, const Formattable& arg3, const Formattable& arg4, const Formattable& arg5, const Formattable& arg6, const Formattable& arg7, const Formattable& arg8, const Formattable& arg9, const Formattable& arg10, const Formattable& arg11, const Formattable& arg12, const Formattable& arg13, const Formattable& arg14, const Formattable& arg15 );

private:
	enum
	{
		MAX_ARG_COUNT = 16,
	};

	enum EntryType
	{
		ENTRY_NONE = 0,
		ENTRY_ARGUMENT,
		ENTRY_TEXT,
	};

	struct PatternEntry
	{
		PatternEntry( UInt index, const Char* text, UInt textLength ) :
			Type( ENTRY_ARGUMENT ),
			Index( index ),
			Text( text ),
			TextLength( textLength )
		{
		}

		PatternEntry( const Char* text, UInt textLength ) :
			Type( ENTRY_TEXT ),
			Index( none ),
			Text( text ),
			TextLength( textLength )
		{
		}

		PatternEntry() :
			Type( ENTRY_NONE ),
			Index( none ),
			Text( nullptr ),
			TextLength( 0 )
		{
		}

		EntryType	Type;
		UInt		Index;
		const Char*	Text;
		UInt		TextLength;
	};

	mutable PatternEntry										_entries[2*MAX_ARG_COUNT+1];
	mutable UInt												_entryCount;
	mutable Formattable											_args[MAX_ARG_COUNT];
	mutable UInt												_argCount;

	const Char*													_pattern;
	mutable Bool												_prepared;

	void														Prepare() const;
	void														Map( const Formattable* args, UInt argCount );
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_FORMATTER_
