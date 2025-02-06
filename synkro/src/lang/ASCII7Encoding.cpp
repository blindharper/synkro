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
// Purpose: ASCII-7 character encoding implementation.
//==============================================================================
#include "config.h"
#include "ASCII7Encoding.h"


namespace synkro
{


namespace lang
{


Bool ASCII7Encoding::Decode( const Byte* src, UInt srcLen, UInt* srcLenUsed, Char* dst, UInt dstLen, UInt* dstLenUsed ) const
{
	UInt s = 0;
	UInt d = 0;
	UInt cp = 0;

	// Loop until we have at least one unused character in the source buffer.
	while ( s < srcLen )
	{
		// Convert next byte to Unicode code point.
		cp = src[s];

		// Convert code point to the Unicode character and write it to the output buffer.
		const UInt dInc = CopyChar( dst+d, dstLen-d, cp );
		if ( dInc < 1 )
			break;

		// Update buffer pointers.
		d += dInc;
		++s;
	}

	// Update buffer usage stats.
	*srcLenUsed = s;
	*dstLenUsed = d;

	return (s > 0);
}

Bool ASCII7Encoding::Encode( const Char* src, UInt srcLen, UInt* srcLenUsed, Byte* dst, UInt dstLen, UInt* dstLenUsed ) const
{
	UInt s = 0;
	UInt d = 0;
	UInt cp = 0;

	// Loop until we have at least one unused character in the source buffer.
	while ( s < srcLen )
	{
		const UInt sInc = GetCode( src+s, srcLen-s, &cp );
		if ( (sInc < 0) || (cp >= 128) || (dstLen-d < 1) )
			break;

		// Update buffer pointers.
		dst[d++] = CastByte( cp );
		s += sInc;
	}

	// Update buffer usage stats.
	*srcLenUsed = s;
	*dstLenUsed = d;

	return (s > 0);
}


} // lang


} // synkro
