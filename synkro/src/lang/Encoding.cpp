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
// Purpose: Defines base character encoding.
//==============================================================================
#include "config.h"
#include "Encoding.h"
#include "ASCII7Encoding.h"
#include "UTF8Encoding.h"
#include "UTF16Encoding.h"
#include "UTF32Encoding.h"
#include <lang/Exception.h>


namespace synkro
{


namespace lang
{


static ASCII7Encoding _encASCII7;
static UTF8Encoding _encUTF8;
static UTF16Encoding _encUTF16LE( false );
static UTF16Encoding _encUTF16BE( true );
static UTF32Encoding _encUTF32LE( false );
static UTF32Encoding _encUTF32BE( true );


//------------------------------------------------------------------------------


Encoding* Encoding::Get( const char* name )
{
	if ( _strcmpi(name, "ASCII-7") == 0 )
	{
		return &_encASCII7;
	}
	else if ( _strcmpi(name, "UTF-8") == 0 )
	{
		return &_encUTF8;
	}
	else if ( _strcmpi(name, "UTF-16LE") == 0 )
	{
		return &_encUTF16LE;
	}
	else if ( _strcmpi(name, "UTF-16BE") == 0 )
	{
		return &_encUTF16BE;
	}
	else if ( _strcmpi(name, "UTF-32LE") == 0 )
	{
		return &_encUTF32LE;
	}
	else if ( _strcmpi(name, "UTF-32BE") == 0 )
	{
		return &_encUTF32BE;
	}

	throw Exception( String::Format( L"Unknown encoding {0}.", name ) );
}

UInt Encoding::CopyChar( Char* p, UInt len, UInt cp )
{
	UInt i = 0;

	if ( cp >= 0x10000 )
	{
		if ( len >= 2 )
		{
			p[i++] = Char( ((cp-0x10000)>>10) + 0xD800 );
			p[i++] = Char( ((cp-0x10000)&1023) + 0xDC00 );
		}
	}
	else
	{
		if ( len >= 1 )
		{
			p[i++] = Char( cp );
		}
	}

	return i;
}

UInt Encoding::GetCode( const Char* p, UInt len, UInt* cp )
{
	if ( len < 1 )
		return 0;

	UInt i = 0;
	UInt c = p[i];

	// High-surrogate character?
	if ( c >= 0xD800 && c <= 0xDBFF ) 
	{
		if ( len >= 2 )
		{
			// Supplementary code point, <H,L> pair.
			i++;
			UInt c2 = p[i++];
			c = (UInt(c-0xD800) << 10) + ( UInt(c2-0xDC00) + 0x10000);
			*cp = c;
		}
	}
	else
	{
		if ( len >= 1 )
		{
			*cp = c;
			i++;
		}
	}

	return i;
}


} // lang


} // synkro
