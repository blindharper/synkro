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
	_type( VALUE_NONE )
{
}

SYNKRO_INLINE Formattable::Formattable( Double value ) SYNKRO_NOEXCEPT :
	_type( VALUE_NUMBER ),
	_number( value )
{
}

SYNKRO_INLINE Formattable::Formattable( const char* value ) SYNKRO_NOEXCEPT :
	_type( VALUE_ANSI ),
	_ansi( value )
{
}

SYNKRO_INLINE Formattable::Formattable( const Char* value ) SYNKRO_NOEXCEPT :
	_type( VALUE_UNICODE ),
	_unicode( value )
{
}

SYNKRO_INLINE Formattable::Formattable( const DateTime& value ) SYNKRO_NOEXCEPT :
	_type( VALUE_DATETIME ),
	_dateTime( value )
{
}
