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
// Purpose: UTF-16 character encoding implementation.
//==============================================================================
#include "config.h"
#include "UTF16Encoding.h"


namespace synkro
{


namespace lang
{


UTF16Encoding::UTF16Encoding( Bool bigEndian ) :
	_bigEndian( bigEndian )
{
}

Bool UTF16Encoding::Decode( const Byte* src, UInt srcLen, UInt* srcLenUsed, Char* dst, UInt dstLen, UInt* dstLenUsed ) const
{
	UInt s = 0;
	UInt d = 0;
	UInt cp = 0;

	// Loop until we have at least one unused character in the source buffer.
	while ( s < srcLen )
	{
		// Convert next bytes to Unicode code point.
		if ( srcLen-s < 2 )
			break;

		UInt sInc = 0;

		if ( _bigEndian )
			cp = (CastUInt(src[0])<<8) + CastUInt(src[1]);
		else
			cp = (CastUInt(src[1])<<8) + CastUInt(src[0]);
		sInc += 2;

		if ( 0xD800 == (cp&0xFFFFFC00) )
		{
			if ( srcLen-s < 4 )
				break;

			UInt c;
			if ( _bigEndian )
				c = (CastUInt(src[2])<<8) + CastUInt(src[3]);
			else
				c = (CastUInt(src[3])<<8) + CastUInt(src[2]);
			sInc += 2;
			src += 2;

			cp = (cp<<10) + c - ((0xd800<<10UL)+0xdc00-0x10000);
		}
		src += 2;

		// Copy characters to the destination buffer.
		const UInt dInc = CopyChar( dst+d, dstLen-d, cp );
		if ( dInc < 1 )
			break;

		// Update buffer pointers.
		d += dInc;
		s += sInc;
	}

	// Update buffer usage stats.
	*srcLenUsed = s;
	*dstLenUsed = d;

	return (s > 0);
}

Bool UTF16Encoding::Encode( const Char* src, UInt srcLen, UInt* srcLenUsed, Byte* dst, UInt dstLen, UInt* dstLenUsed ) const
{
	UInt s = 0;
	UInt d = 0;
	UInt cp = 0;

	// Loop until we have at least one unused character in the source buffer.
	while ( s < srcLen )
	{
		const UInt sInc = GetCode( src+s, srcLen-s, &cp );
		if ( sInc < 0 )
			break;

		Char codes[2];
		UInt codeCnt = 0;
		if ( cp >= 0x10000 )
		{
			codes[codeCnt++] = CastChar( ((cp-0x10000)>>10) + 0xD800 );
			codes[codeCnt++] = CastChar( ((cp-0x10000)&1023) + 0xDC00 );
		}
		else
		{
			codes[codeCnt++] = CastChar( cp );
		}

		if ( dstLen-d < codeCnt )
			break;

		// Update buffer pointers.
		for ( UInt i = 0 ; i < codeCnt ; ++i )
		{
			const Char code = codes[i];
			if ( _bigEndian )
			{
				dst[d++] = CastByte( cp >> 8 );
				dst[d++] = CastByte( cp );
			}
			else
			{
				dst[d++] = CastByte( cp );
				dst[d++] = CastByte( cp >> 8 );
			}
		}
		s += sInc;
	}

	// Update buffer usage stats.
	*srcLenUsed = s;
	*dstLenUsed = d;

	return (s > 0);
}


} // lang


} // synkro
