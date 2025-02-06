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
// Purpose: Defines type converter.
//==============================================================================
#ifndef _SYNKRO_LANG_CONVERT_
#define _SYNKRO_LANG_CONVERT_


#include "config.h"
#include <lang/String.h>
#include <lang/DateTime.h>


namespace synkro
{


namespace lang
{


// Standard type converter.
class SYNKRO_API Convert
{
public:
	static Bool												ToBool( const String& value );
	static Byte												ToByte( const String& value );
	static Short											ToShort( const String& value );
	static Int												ToInt( const String& value );
	static Long												ToLong( const String& value );
	static UShort											ToUShort( const String& value );
	static UInt												ToUInt( const String& value );
	static ULong											ToULong( const String& value );
	static Float											ToFloat( const String& value );
	static Double											ToDouble( const String& value );
	static DateTime											ToDateTime( const String& value, const String& format );
	static String											ToString( Bool value );
	static String											ToString( Byte value );
	static String											ToString( Short value );
	static String											ToString( Int value );
	static String											ToString( Long value );
	static String											ToString( UShort value );
	static String											ToString( UInt value );
	static String											ToString( ULong value );
	static String											ToString( Float value );
	static String											ToString( Double value );
	static String											ToString( Double value, const Char* format ); // format: '#.##', '#.00' or '000'.
	static String											ToString( const DateTime& value );
	static String											ToString( const DateTime& value, const Char* format ); // format: One of 'd', 'D', 'f', 'F', 'g', 'r', 't', 'T', 'o'.
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_CONVERT_
