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
// Purpose: Defines UTF-16 character encoding.
//==============================================================================
#ifndef _SYNKRO_LANG_UTF16ENCODING_
#define _SYNKRO_LANG_UTF16ENCODING_


#include "config.h"
#include "Encoding.h"


namespace synkro
{


namespace lang
{


// UTF-16 encoding.
class SYNKRO_API UTF16Encoding :
	public Encoding
{
public:
	UTF16Encoding( Bool bigEndian );
	Bool													Decode( const Byte* src, UInt srcLen, UInt* srcLenUsed, Char* dst, UInt dstLen, UInt* dstLenUsed ) const;
	Bool													Encode( const Char* src, UInt srcLen, UInt* srcLenUsed, Byte* dst, UInt dstLen, UInt* dstLenUsed ) const;

private:
	Bool													_bigEndian;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_UTF16ENCODING_
