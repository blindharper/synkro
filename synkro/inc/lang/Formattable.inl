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
// Purpose: Implements formattable argument.
//==============================================================================
SYNKRO_INLINE Formattable::Formattable() SYNKRO_NOEXCEPT :
	_type( VALUE_NONE ),
	_number( 0.0 ),
	_ansi( nullptr ),
	_unicode( nullptr ),
	_dateTime( 0 )
{
}

SYNKRO_INLINE Formattable::Formattable( Double value ) SYNKRO_NOEXCEPT :
	_type( VALUE_NUMBER ),
	_number( value ),
	_ansi( nullptr ),
	_unicode( nullptr ),
	_dateTime( 0 )
{
}

SYNKRO_INLINE Formattable::Formattable( const char* value ) SYNKRO_NOEXCEPT :
	_type( VALUE_ANSI ),
	_number( 0.0 ),
	_ansi( value ),
	_unicode( nullptr ),
	_dateTime( 0 )
{
}

SYNKRO_INLINE Formattable::Formattable( const Char* value ) SYNKRO_NOEXCEPT :
	_type( VALUE_UNICODE ),
	_number( 0.0 ),
	_ansi( nullptr ),
	_unicode( value ),
	_dateTime( 0 )
{
}

SYNKRO_INLINE Formattable::Formattable( const DateTime& value ) SYNKRO_NOEXCEPT :
	_type( VALUE_DATETIME ),
	_number( 0.0 ),
	_ansi( nullptr ),
	_unicode( nullptr ),
	_dateTime( value )
{
}
