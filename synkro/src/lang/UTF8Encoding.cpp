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
// Purpose: UTF-8 character encoding implementation.
//==============================================================================
#include "config.h"
#include "UTF8Encoding.h"


namespace synkro
{


namespace lang
{


Bool UTF8Encoding::Decode( const Byte* src, UInt srcLen, UInt* srcLenUsed, Char* dst, UInt dstLen, UInt* dstLenUsed ) const
{
	UInt s = 0;
	UInt d = 0;
	UInt cp = 0;

	// Loop until we have at least one unused character in the source buffer.
	while ( s < srcLen )
	{
		// Convert next bytes to Unicode code point.
		Byte first = src[s];
		if ( (first & 0x80) == 0 ) // Single byte ASCII-7 code.
		{
			cp = CastUInt( first );
			const UInt dInc = CopyChar( dst+d, dstLen-d, cp );
			if ( dInc < 1 )
				break;

			// Update buffer pointers.
			d += dInc;
			++s;
		}
		else // Multibyte character code.
		{
			// Get the number of the following bytes.
			UInt bytes = 1;
			Byte maskByteCount = 0x40;
			UInt maskCode = 0x3F;
			while ( first & maskByteCount )
			{
				++bytes;
				maskByteCount >>= 1;
				maskCode >>= 1;
			}
			if ( (bytes < 2) || (bytes > 4) || (srcLen-s < bytes) )
				break;

			// Read the remaining bytes.
			cp = first & maskCode;
			for ( UInt i = 1; i < bytes; ++i )
			{
				cp <<= 6;
				cp |= ( 0x3F & CastUInt(src[s+i]) );
			}

			// Copy characters to the destination buffer.
			const UInt dInc = CopyChar( dst+d, dstLen-d, cp );
			if ( dInc < 1 )
				break;

			// Update buffer pointers.
			d += dInc;
			s += bytes;
		}
	}

	// Update buffer usage stats.
	*srcLenUsed = s;
	*dstLenUsed = d;

	return (s > 0);
}

Bool UTF8Encoding::Encode( const Char* src, UInt srcLen, UInt* srcLenUsed, Byte* dst, UInt dstLen, UInt* dstLenUsed ) const
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

		if ( cp < 0x80 )
		{
			if ( dstLen-d < 1 )
				break;

			// Update buffer pointers.
			dst[d++] = CastByte( cp );
			s += sInc;
		}
		else if ( cp < 0x800 )
		{
			if ( dstLen-d < 2 )
				break;

			// Update buffer pointers.
			dst[d++] = CastByte( 0xC0 | cp>>6 );
			dst[d++] = CastByte( 0x80 | cp&0x3F );
			s += sInc;
		}
		else if ( cp < 0x10000 )
		{
			if ( dstLen-d < 3 )
				break;

			// Update buffer pointers.
			dst[d++] = CastByte( 0xE0 | cp>>12 );
			dst[d++] = CastByte( 0x80 | (cp>>6)&0x3F );
			dst[d++] = CastByte( 0x80 | cp&0x3F );
			s += sInc;
		}
		else if ( cp < 0x200000 )
		{
			if ( dstLen-d < 4 )
				break;

			// Update buffer pointers.
			dst[d++] = CastByte( 0xE0 | cp>>18 );
			dst[d++] = CastByte( 0x80 | (cp>>12) &0x3F );
			dst[d++] = CastByte( 0x80 | (cp>>6) &0x3F );
			dst[d++] = CastByte( 0x80 | cp&0x3F );
			s += sInc;
		}
		else
		{
			// Invalid Unicode character.
			break;
		}
	}

	// Update buffer usage stats.
	*srcLenUsed = s;
	*dstLenUsed = d;

	return (s > 0);
}


} // lang


} // synkro
