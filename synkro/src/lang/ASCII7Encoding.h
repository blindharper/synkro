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
// Purpose: Defines ASCII-7 character encoding.
//==============================================================================
#ifndef _SYNKRO_LANG_ASCII7ENCODING_
#define _SYNKRO_LANG_ASCII7ENCODING_


#include "config.h"
#include "Encoding.h"


namespace synkro
{


namespace lang
{


// ASCII-7 encoding.
class SYNKRO_API ASCII7Encoding :
	public Encoding
{
public:
	Bool													Decode( const Byte* src, UInt srcLen, UInt* srcLenUsed, Char* dst, UInt dstLen, UInt* dstLenUsed ) const;
	Bool													Encode( const Char* src, UInt srcLen, UInt* srcLenUsed, Byte* dst, UInt dstLen, UInt* dstLenUsed ) const;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_ASCII7ENCODING_
