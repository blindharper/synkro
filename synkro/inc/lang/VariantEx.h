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
// Purpose: Defines named variant data type.
//==============================================================================
#ifndef _SYNKRO_LANG_VARIANTEX_
#define _SYNKRO_LANG_VARIANTEX_


#include "config.h"
#include <lang/Variant.h>


namespace synkro
{


namespace lang
{


/**
 * Named variant data type.
 */
class SYNKRO_API VariantEx
{
public:
	/**
	 * Creates variant of type Integer.
	 * @param name Variant name.
	 * @param value Variant value.
	 */
	VariantEx( const String& name, Int value );

	/**
	 * Creates variant of type Integer.
	 * @param name Variant name.
	 * @param value Variant value.
	 */
	VariantEx( const String& name, UInt value );

	/**
	 * Creates variant of type Float.
	 * @param name Variant name.
	 * @param value Variant value.
	 */
	VariantEx( const String& name, Float value );

	/**
	 * Creates variant of type String.
	 * @param name Variant name.
	 * @param value Variant value.
	 */
	VariantEx( const String& name, const String& value );

	/**
	 * Creates variant of type String.
	 * @param name Variant name.
	 * @param value Variant value.
	 */
	VariantEx( const String& name, const Char* value );

	/**
	 * Creates variant of type DateTime.
	 * @param name Variant name.
	 * @param value Variant value.
	 */
	VariantEx( const String& name, const DateTime& value );

	/**
	 * Creates variant of type Blob.
	 * @param name Variant name.
	 * @param value Variant value.
	 */
	VariantEx( const String& name, io::IStream* value );

	/**
	 * Creates variant of type Blob.
	 * @param name Variant name.
	 * @param value Variant value.
	 */
	VariantEx( const String& name, const Byte* value, UInt size );

	/**
	 * Creates NULL variant.
	 * @param name Variant name.
	 */
	VariantEx( const String& name );

	/**
	 * Creates nameless NULL variant.
	 */
	VariantEx();

	/**
	 * Variant name.
	 */
	String													Name;

	/**
	 * Variant value type.
	 */
	Variant													Value;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_VARIANTEX_
