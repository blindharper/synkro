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
// Purpose: Defines parseable argument.
//==============================================================================
#ifndef _SYNKRO_LANG_PARSEABLE_
#define _SYNKRO_LANG_PARSEABLE_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace lang
{


// Container for an value that can be converted to text.
class Parseable
{
public:
	// Creates integer value.
	Parseable( Int& value );

	// Creates floating-point value.
	Parseable( Double& value );

	// Creates string value.
	Parseable( String& value );

	// Creates default value.
	Parseable();

private:
	friend class Parser;

	enum ValueType
	{
		VALUE_NONE,
		VALUE_INTEGER,
		VALUE_FLOAT,
		VALUE_STRING,
	};

	ValueType	_type;
	Int*		_int;
	Double*		_float;
	String*		_string;
};


#include "Parseable.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_PARSEABLE_
