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
// Purpose: Mutable string.
//==============================================================================
#include "config.h"
#include "StringBuilder.h"


namespace synkro
{


namespace lang
{


StringBuilder::StringBuilder() :
	_buffer( A(Char) )
{
}

void StringBuilder::Clear()
{
	_buffer.Clear();
}

void StringBuilder::Append( Char ch )
{
	_buffer.Add( ch );
}

void StringBuilder::Append( const Char* text )
{
	if ( text != nullptr )
	{
		_buffer.Add( text, CastUInt(wcslen(text)) );
	}
}

void StringBuilder::Append( const String& text )
{
	for ( UInt i = 0; i < text.Length(); ++i )
	{
		_buffer.Add( text[i] );
	}
}

void StringBuilder::Append( Double number, UInt precision )
{
	Char fmt[64] = {};
	Char buf[64] = {};
	swprintf_s( fmt, L"%%.%if", precision );
	swprintf_s( buf, fmt, number );
	Append( buf );
}

void StringBuilder::Append( Double number )
{
	Append( number, 3 );
}

void StringBuilder::Append( UInt number )
{
	Char buf[64] = {};
	swprintf_s( buf, L"%d", number );
	Append( buf );
}

String StringBuilder::GetString()
{
	if ( GetLength() > 0 )
	{
		if ( _buffer.LastValue() != 0 )
		{
			_buffer.Add( 0 );
		}
		return String( _buffer.Begin() );
	}
	return String::Empty;
}

UInt StringBuilder::GetLength() const
{
	return _buffer.Size();
}


} // lang


} // synkro
