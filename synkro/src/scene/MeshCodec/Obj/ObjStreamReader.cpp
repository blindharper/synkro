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
// Purpose: Obj mesh stream reader.
//==============================================================================
#include "config.h"
#include "ObjStreamReader.h"


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


ObjStreamReader::ObjStreamReader( IStream* stream ) :
	_stream( stream ),
	_lexem( A(char) ),
	_lexemCache( A(char) ),
	_char( 0 )
{
	_stream->Open( OpenMode::Read );
}

ObjStreamReader::~ObjStreamReader()
{
	_stream->Close();
}

String ObjStreamReader::GetString()
{
	GetLexem();
	return String( _lexem.Begin() );
}

Float ObjStreamReader::GetFloat()
{
	Float f;
	GetLexem();
	sscanf( _lexem.Begin(), "%f", &f );
	return f;
}

Bool ObjStreamReader::GetLexem()
{
	if ( !_lexemCache.IsEmpty() )
	{
		_lexem.SetSize( _lexemCache.Size() );
		for ( UInt i = 0; i < _lexem.Size(); ++i )
		{
			_lexem[i] = _lexemCache[i];
		}
		_lexemCache.Clear();
		return true;
	}

	char ch = 0;
	_lexem.Clear();

	while ( (ch = ReadChar()) != 0 )
	{
		if ( ch == '#' )
		{
			SkipComment();
			continue;
		}

		switch ( ch )
		{
			case ' ': case '\t': case '\r': case '\n':
				if ( _lexem.IsEmpty() )
					continue;

				_lexem.Add( 0 );
				return true;

			default:
				_lexem.Add( ch );
				break;
		}
	}

	return false;
}

Bool ObjStreamReader::PeekLexem()
{
	if ( !_lexemCache.IsEmpty() )
		return true;

	char ch = 0;
	while ( (ch = ReadChar()) != 0 )
	{
		if ( ch == '#' )
		{
			SkipComment();
			continue;
		}

		switch ( ch )
		{
			case ' ': case '\t': case '\r': case '\n':
				if (_lexemCache.IsEmpty() )
					continue;

				_lexemCache.Add( 0 );
				return true;

			default:
				_lexemCache.Add( ch );
				break;
		}
	}

	return false;
}

void ObjStreamReader::SkipComment()
{
	char ch = 0;

	while ( (ch = ReadChar()) != 0 )
	{
		if ( ch == '\r' )
		{
			ReadChar();
			break;
		}
		else if ( ch == '\n' )
		{
			break;
		}
	}
}

char ObjStreamReader::ReadChar()
{
	char ch = 0;
	if ( _char != 0 )
	{
		ch = _char;
		_char = 0;
		return ch;
	}

	if ( _stream->Read(&ch, 1) == 1 )
		return ch;
	else
		return 0;
}


} // scene


} // synkro
