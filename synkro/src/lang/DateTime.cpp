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
// Purpose: Implements date-time value.
//==============================================================================
#include "config.h"
#include <lang/DateTime.h>


namespace synkro
{


namespace lang
{


enum
{
	TIME_YEAR = 0,
	TIME_MONTH,
	TIME_DAYOFWEEK,
	TIME_DAY,
	TIME_HOUR,
	TIME_MINUTE,
	TIME_SECOND,
	TIME_MILLISECOND,
};


static void Set( UShort* date, UShort year, UShort month, UShort day, UShort hour, UShort minute, UShort second, UShort millisecond )
{
	date[TIME_YEAR]			= year;
	date[TIME_MONTH]		= month;
	date[TIME_DAY]			= day;
	date[TIME_DAYOFWEEK]	= 0;
	date[TIME_HOUR]			= hour;
	date[TIME_MINUTE]		= minute;
	date[TIME_SECOND]		= second;
	date[TIME_MILLISECOND]	= millisecond;
}


const DateTime DateTime::Invalid = DateTime( 0 );

DateTime::DateTime( UShort year, UShort month, UShort day, UShort hour, UShort minute, UShort second, UShort millisecond )
{
	Set( _value, year, month, day, hour, minute, second, millisecond );
}

DateTime::DateTime( UShort year, UShort month, UShort day, UShort hour, UShort minute, UShort second )
{
	Set( _value, year, month, day, hour, minute, second, 0 );
}

DateTime::DateTime( UShort year, UShort month, UShort day, UShort hour, UShort minute )
{
	Set( _value, year, month, day, hour, minute, 0, 0 );
}

DateTime::DateTime( UShort year, UShort month, UShort day, UShort hour )
{
	Set( _value, year, month, day, hour, 0, 0, 0 );
}

DateTime::DateTime( UShort year, UShort month, UShort day )
{
	Set( _value, year, month, day, 0, 0, 0, 0 );
}

DateTime::DateTime( UShort fake )
{
	Set( _value, 0, 0, 0, 0, 0, 0, 0 );
}

DateTime::DateTime()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::GetLocalTime( reinterpret_cast<SYSTEMTIME*>(&_value) );
#else
#	error DateTime::DateTime() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

UShort DateTime::Year() const
{
	return _value[TIME_YEAR];
}

UShort DateTime::Month() const
{
	return _value[TIME_MONTH];
}

UShort DateTime::DayOfWeek() const
{
	return _value[TIME_DAYOFWEEK];
}

UShort DateTime::Day() const
{
	return _value[TIME_DAY];
}

UShort DateTime::Hour() const
{
	return _value[TIME_HOUR];
}

UShort DateTime::Minute() const
{
	return _value[TIME_MINUTE];
}

UShort DateTime::Second() const
{
	return _value[TIME_SECOND];
}

UShort DateTime::Millisecond() const
{
	return _value[TIME_MILLISECOND];
}

Float DateTime::TotalHours() const
{
	return CastFloat(_value[TIME_HOUR]) + TotalMinutes()/60.0f;
}

Float DateTime::TotalMinutes() const
{
	return CastFloat(_value[TIME_MINUTE]) + TotalSeconds()/60.0f;
}

Float DateTime::TotalSeconds() const
{
	return CastFloat(_value[TIME_SECOND]) + 0.001f*CastFloat(_value[TIME_MILLISECOND]);
}

Bool DateTime::operator==( const DateTime& other ) const
{
	for ( UInt i = TIME_YEAR; i <= TIME_MILLISECOND; ++i )
	{
		if ( _value[i] != other._value[i] )
			return false;
	}
	return true;
}

Bool DateTime::operator!=( const DateTime& other ) const
{
	return !(*this == other);
}

Bool DateTime::IsValid() const
{
	return (*this != Invalid);
}


} // lang


} // synkro
