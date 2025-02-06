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
// Purpose: Implements parseable argument.
//==============================================================================
SYNKRO_INLINE Parseable::Parseable( Int& value ) :
	_type( VALUE_INTEGER ),
	_int( &value ),
	_float( nullptr ),
	_string( nullptr )
{
}

SYNKRO_INLINE Parseable::Parseable( Double& value ) :
	_type( VALUE_FLOAT ),
	_int( nullptr ),
	_float( &value ),
	_string( nullptr )
{
}

SYNKRO_INLINE Parseable::Parseable( String& value ) :
	_type( VALUE_STRING ),
	_int( nullptr ),
	_float( nullptr ),
	_string( &value )
{
}

SYNKRO_INLINE Parseable::Parseable() :
	_type( VALUE_NONE ),
	_int( nullptr ),
	_float( nullptr ),
	_string( nullptr )
{
}
