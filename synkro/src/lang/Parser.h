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
// Purpose: Defines text parser.
//==============================================================================
#ifndef _SYNKRO_LANG_PARSER_
#define _SYNKRO_LANG_PARSER_


#include "config.h"
#include "Parseable.h"
#include <internal/SizeOf.h>


namespace synkro
{


namespace lang
{


// Text parser.
class SYNKRO_API Parser
{
public:
	// Constructor.
	Parser( const Char* pattern );

	// Methods.
	Bool					ParseText( const String& text );
	void					Map( Parseable arg0 );
	void					Map( Parseable arg0, Parseable arg1 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13, Parseable arg14 );
	void					Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13, Parseable arg14, Parseable arg15 );

	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13, Parseable arg14 );
	static Bool				Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13, Parseable arg14, Parseable arg15 );

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

	PatternEntry			_entries[2*MAX_ARG_COUNT+1];
	UInt					_entryCount;
	Parseable				_args[MAX_ARG_COUNT];
	UInt					_argCount;

	void					Prepare( const Char* pattern );
	void					Map( const Parseable* args, UInt argCount );
};


#include "Parser.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_PARSER_
