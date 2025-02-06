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
#ifndef _SYNKRO_LANG_ENCODING_
#define _SYNKRO_LANG_ENCODING_


#include "config.h"


namespace synkro
{


namespace lang
{


// Base Unicode character encoding. Provides means to 
// convert Unicode characters to bytes and vice versa.
class SYNKRO_API Encoding
{
public:
	// Decodes bytes to Unicode code points.
	// @param src Source byte buffer.
	// @param srcLen Source buffer length, in bytes.
	// @param srcLenUsed Number of bytes from source buffer used for for conversion.
	// @param dst Destination character buffer.
	// @param dstLen Destination buffer length, in characters.
	// @param dstLenUsed Number of characters copied to destination buffer.
	// @return True if the source buffer was successfully decoded, false otherwise.
	virtual Bool											Decode( const Byte* src, UInt srcLen, UInt* srcLenUsed, Char* dst, UInt dstLen, UInt* dstLenUsed ) const = 0;

	// Encodes Unicode code points to bytes.
	// @param src Source character buffer.
	// @param srcLen Source buffer length, in characters.
	// @param srcLenUsed Number of characters from source buffer used for for conversion.
	// @param dst Destination byte buffer.
	// @param dstLen Destination buffer length, in bytes.
	// @param dstLenUsed Number of bytes copied to destination buffer.
	// @return True if the source buffer was successfully encoded, false otherwise.
	virtual Bool											Encode( const Char* src, UInt srcLen, UInt* srcLenUsed, Byte* dst, UInt dstLen, UInt* dstLenUsed ) const = 0;

	// Retrieves encoding by name.
	// @param name Text constant specifying encoding name.
	// @return Pointer to the encoding.
	// @exception Unknown encoding requested.
	// @see The following encodings are currently supported:
	// ASCII-7, UTF-8, UTF-16BE, UTF-16LE, UTF-32BE, UTF-32LE
	static Encoding*										Get( const char* name );

protected:
	// Copies the specified Unicode code point 
	// to character array provided there's enough space.
	// Returns the number of characters copied.
	static UInt												CopyChar( Char* p, UInt len, UInt cp );

	// Creates Unicode code point from the character buffer.
	// Returns the number of characters consumed in the source buffer.
	static UInt												GetCode( const Char* p, UInt len, UInt* cp );
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_ENCODING_
