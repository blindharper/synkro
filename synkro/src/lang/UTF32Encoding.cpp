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
// Purpose: UTF-32 character encoding implementation.
//==============================================================================
#include "config.h"
#include "UTF32Encoding.h"


namespace synkro
{


namespace lang
{


UTF32Encoding::UTF32Encoding( Bool bigEndian ) :
	_bigEndian( bigEndian )
{
}

Bool UTF32Encoding::Decode( const Byte* src, UInt srcLen, UInt* srcLenUsed, Char* dst, UInt dstLen, UInt* dstLenUsed ) const
{
	UInt s = 0;
	UInt d = 0;
	UInt cp = 0;

	// Loop until we have at least one unused character in the source buffer.
	while ( s < srcLen )
	{
		// Convert next bytes to Unicode code point.
		if ( srcLen-s < 4 )
			break;

		if ( _bigEndian )
		{
			cp = 0;
			for ( UInt i = 0; i < 4; ++i )
			{
				cp <<= 8;
				cp += src[i];
			}
		}
		else
		{
			cp = 0;
			for ( UInt i = 4; i > 0; --i )
			{
				cp <<= 8;
				cp += src[i-1];
			}
		}
		src += 4;

		// Copy characters to the destination buffer.
		const UInt dInc = CopyChar( dst+d, dstLen-d, cp );
		if ( dInc < 1 )
			break;

		// Update buffer pointers.
		d += dInc;
		s += 4;
	}

	// Update buffer usage stats.
	*srcLenUsed = s;
	*dstLenUsed = d;

	return (s > 0);
}

Bool UTF32Encoding::Encode( const Char* src, UInt srcLen, UInt* srcLenUsed, Byte* dst, UInt dstLen, UInt* dstLenUsed ) const
{
	UInt s = 0;
	UInt d = 0;
	UInt cp = 0;

	// Loop until we have at least one unused character in the source buffer.
	while ( s < srcLen )
	{
		const UInt sInc = GetCode( src+s, srcLen-s, &cp );
		if ( (sInc < 0) || (dstLen-d < 4) )
			break;

		// Update buffer pointers.
		if ( _bigEndian )
		{
			dst[d++] = CastByte( cp >> 24 );
			dst[d++] = CastByte( cp >> 16 );
			dst[d++] = CastByte( cp >> 8 );
			dst[d++] = CastByte( cp );
		}
		else
		{
			dst[d++] = CastByte( cp );
			dst[d++] = CastByte( cp >> 8 );
			dst[d++] = CastByte( cp >> 16 );
			dst[d++] = CastByte( cp >> 24 );
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
