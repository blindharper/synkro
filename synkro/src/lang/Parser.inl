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
SYNKRO_INLINE void Parser::Map( Parseable arg0 )
{
	Parseable args[] = { arg0 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1 )
{
	Parseable args[] = { arg0, arg1 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2 )
{
	Parseable args[] = { arg0, arg1, arg2 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4, arg5 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13, Parseable arg14 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE void Parser::Map( Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13, Parseable arg14, Parseable arg15 )
{
	Parseable args[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15 };
	Map( args, SizeOf(args) );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0 )
{
	Parser p( pattern );
	p.Map( arg0 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1 )
{
	Parser p( pattern );
	p.Map( arg0, arg1 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4, arg5 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13, Parseable arg14 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14 );
	return p.ParseText( text );
}

SYNKRO_INLINE Bool Parser::Parse( const String& text, const Char* pattern, Parseable arg0, Parseable arg1, Parseable arg2, Parseable arg3, Parseable arg4, Parseable arg5, Parseable arg6, Parseable arg7, Parseable arg8, Parseable arg9, Parseable arg10, Parseable arg11, Parseable arg12, Parseable arg13, Parseable arg14, Parseable arg15 )
{
	Parser p( pattern );
	p.Map( arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15 );
	return p.ParseText( text );
}
