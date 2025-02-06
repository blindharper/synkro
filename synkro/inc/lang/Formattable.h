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
// Purpose: Defines formattable argument.
//==============================================================================
#ifndef _SYNKRO_LANG_FORMATTABLE_
#define _SYNKRO_LANG_FORMATTABLE_


#include "config.h"
#include <lang/DateTime.h>


namespace synkro
{


namespace lang
{


/**
 * Container for a value that can be converted to text.
 */
class Formattable
{
public:
	/**
	 * Creates empty value.
	 */
	Formattable();

	/**
	 * Creates numeric value.
	 */
	Formattable( Double value );

	/**
	 * Creates string value.
	 */
	Formattable( const char* value );

	/**
	 * Creates string value.
	 */
	Formattable( const Char* value );

	/**
	 * Creates date-time value.
	 */
	Formattable( const DateTime& value );

private:
	friend class Formatter;

	enum ValueType
	{
		VALUE_NONE,
		VALUE_NUMBER,
		VALUE_ANSI,
		VALUE_UNICODE,
		VALUE_DATETIME,
	};

	ValueType	_type;
	Double		_number;
	const char*	_ansi;
	const Char*	_unicode;
	DateTime	_dateTime;
};


#include "Formattable.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_FORMATTABLE_
