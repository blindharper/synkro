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
// Purpose: Implements variant data type.
//==============================================================================
#include "config.h"
#include <lang/Variant.h>
#include <lang/Convert.h>
#include <io/BinaryStream.h>


//------------------------------------------------------------------------------

using namespace synkro::io;

//------------------------------------------------------------------------------


namespace synkro
{


namespace lang
{


const Variant Variant::Null;

Variant::Variant( Int value ) :
	_type( DataType::Integer ),
	_int( value ),
	_float( 0.0f ),
	_date( DateTime::Invalid )
{
}

Variant::Variant( Float value ) :
	_type( DataType::Float ),
	_int( 0 ),
	_float( value ),
	_date( DateTime::Invalid )
{
}

Variant::Variant( const String& value ) :
	_type( DataType::String ),
	_int( 0 ),
	_float( 0.0f ),
	_string( value ),
	_date( DateTime::Invalid )
{
}

Variant::Variant( const Char* value ) :
	_type( DataType::String ),
	_int( 0 ),
	_float( 0.0f ),
	_string( value ),
	_date( DateTime::Invalid )
{
}

Variant::Variant( const DateTime& value ) :
	_type( DataType::DateTime ),
	_int( 0 ),
	_float( 0.0f ),
	_date( value )
{
}

Variant::Variant( IStream* value ) :
	_type( DataType::Blob ),
	_int( 0 ),
	_float( 0.0f ),
	_date( DateTime::Invalid ),
	_blob( value )
{
}

Variant::Variant( const Byte* value, UInt size ) :
	_type( DataType::Blob ),
	_int( 0 ),
	_float( 0.0f ),
	_date( DateTime::Invalid ),
	_blob( new BinaryStream(value, size) )
{
}

Variant::Variant() :
	_type( DataType::Unknown ),
	_int( 0 ),
	_float( 0.0f ),
	_date( DateTime::Invalid )
{
}

DataType Variant::Type() const
{
	return _type;
}

Bool Variant::IsNull() const
{
	return (_type == DataType::Unknown);
}

Variant::operator Int() const
{
	if ( _type == DataType::Integer )
		return _int;
	else if ( _type == DataType::Float )
		return CastInt(_float);
	else if ( _type == DataType::String )
	{
		if ( _string.IsInteger() )
			return _string.ToInteger();
		else if ( _string.IsDecimal() )
			return CastInt(_string.ToDecimal());
	}

	return 0L;
}

Variant::operator Float() const
{
	if ( _type == DataType::Integer )
		return CastFloat(_int);
	else if ( _type == DataType::Float )
		return _float;
	else if ( _type == DataType::String )
	{
		if ( _string.IsInteger() )
			return CastFloat(_string.ToInteger());
		else if ( _string.IsDecimal() )
			return _string.ToDecimal();
	}

	return 0L;
}

Variant::operator String() const
{
	if ( _type == DataType::Integer )
		return String::Format( L"{0}", _int );
	else if ( _type == DataType::Float )
		return String::Format( L"{0,#.000000}", _float );
	else if ( _type == DataType::String )
		return _string;
	else if ( _type == DataType::DateTime )
		return String::Format( L"{0}", _date );
	else if ( _type == DataType::Unknown )
		return L"NULL";

	return String::Empty;
}

Variant::operator DateTime() const
{
	if ( _type == DataType::String )
		return Convert::ToDateTime( _string, String::Empty );

	return _date;
}

Variant::operator IStream*() const
{
	return _blob.AsPtr();
}


} // lang


} // synkro
