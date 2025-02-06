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
// Purpose: Defines variant data type.
//==============================================================================
#ifndef _SYNKRO_LANG_VARIANT_
#define _SYNKRO_LANG_VARIANT_


#include "config.h"
#include <lang/Ptr.h>
#include <io/IStream.h>
#include <lang/DateTime.h>
#include <lang/DataType.h>


namespace synkro
{


namespace lang
{


/**
 * Variant data type.
 */
class SYNKRO_API Variant
{
public:
	/**
	 * Null variant constant.
	 */
	static const Variant									Null;

	/**
	 * Creates variant of type Integer.
	 */
	Variant( Int value );

	/**
	 * Creates variant of type Float.
	 */
	Variant( Float value );

	/**
	 * Creates variant of type String.
	 */
	Variant( const String& value );

	/**
	 * Creates variant of type String.
	 */
	Variant( const Char* value );

	/**
	 * Creates variant of type DateTime.
	 */
	Variant( const DateTime& value );

	/**
	 * Creates variant of type Blob.
	 */
	Variant( io::IStream* value );

	/**
	 * Creates variant of type Blob.
	 */
	Variant( const Byte* value, UInt size );

	/**
	 * Creates NULL variant.
	 */
	Variant();

	/**
	 * Retrieves variant value type.
	 */
	DataType												Type() const;

	/**
	 * Indicates whether the variant has the value of NULL.
	 */
	Bool													IsNull() const;

	/**
	 * Casts variant value to integer value.
	 */
															operator Int() const;

	/**
	 * Casts variant value to floating-point value.
	 */
															operator Float() const;

	/**
	 * Casts variant value to string value.
	 */
															operator String() const;

	/**
	 * Casts variant value to date-time value.
	 */
															operator DateTime() const;

	/**
	 * Casts variant value to BLOB value.
	 */
															operator io::IStream*() const;

private:
	DataType												_type;
	Int														_int;
	Float													_float;
	String													_string;
	DateTime												_date;
	P(io::IStream)											_blob;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_VARIANT_
