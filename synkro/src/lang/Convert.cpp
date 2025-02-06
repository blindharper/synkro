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
// Purpose: Implements type converter.
//==============================================================================
#include "config.h"
#include <lang/Convert.h>
#include <internal/Weekdays.h>
#include <internal/Months.h>
#include <internal/Zero.h>


namespace synkro
{


namespace lang
{


Bool Convert::ToBool( const String& value )
{
	return value.ToLower() == "true";
}

Byte Convert::ToByte( const String& value )
{
	char buf[24] = {};
	value.GetBytes( buf, 24 );
	return CastByte( atoi(buf) );
}

Short Convert::ToShort( const String& value )
{
	char buf[24] = {};
	value.GetBytes( buf, 24 );
	return CastShort( atoi(buf) );
}

Int Convert::ToInt( const String& value )
{
	char buf[24] = {};
	value.GetBytes( buf, 24 );
	return CastInt( atoi(buf) );
}

Long Convert::ToLong( const String& value )
{
	char buf[24] = {};
	value.GetBytes( buf, 24 );
	return CastLong( atoi(buf) );
}

UShort Convert::ToUShort( const String& value )
{
	char buf[24] = {};
	value.GetBytes( buf, 24 );
	return CastUShort( atoi(buf) );
}

UInt Convert::ToUInt( const String& value )
{
	char buf[24] = {};
	value.GetBytes( buf, 24 );
	return CastUInt( atoi(buf) );
}

ULong Convert::ToULong( const String& value )
{
	char buf[24] = {};
	value.GetBytes( buf, 24 );
	return CastULong( atoi(buf) );
}

Float Convert::ToFloat( const String& value )
{
	char buf[64] = {};
	value.GetBytes( buf, 64 );
	return CastFloat( atof(buf) );
}

Double Convert::ToDouble( const String& value )
{
	char buf[64] = {};
	value.GetBytes( buf, 64 );
	return CastDouble( atof(buf) );
}

DateTime Convert::ToDateTime( const String& value, const String& format )
{
	if ( value.IsEmpty() )
		return DateTime();

	UShort month = 1; UShort day = 1; UShort year = 0;
	UShort hour = 0; UShort minute = 0;
	UShort second = 0; UShort millisecond = 0;
	Char bufMonth[64] = {};
	Char bufWeekday[64] = {};
	Char buf[128] = {};
	value.GetChars( 0, 128, buf );

	switch ( format[0] )
	{
		case 'd':
		{
			swscanf( buf, L"%hd/%hd/%hd", &month, &day, &year );
		} break;

		case 'D':
		{
			swscanf( buf, L"%9s, %9s %hd, %hd", bufWeekday, bufMonth, &day, &year );
			month = StringToMonthLong( bufMonth );
		} break;

		case 'f':
		{
			Zero( bufMonth, 64 );
			Zero( bufWeekday, 64 );
			swscanf( buf, L"%9s, %9s %hd, %hd %hd:%hd", bufWeekday, bufMonth, &day, &year, &hour, &minute );
			month = StringToMonthLong( bufMonth );
		} break;

		case 'F':
		{
			Zero( bufMonth, 64 );
			Zero( bufWeekday, 64 );
			swscanf( buf, L"%9s, %9s %hd, %hd %hd:%hd:%hd", bufWeekday, bufMonth, &day, &year, &hour, &minute, &second );
			month = StringToMonthLong( bufMonth );
		} break;

		case 'g':
		{
			swscanf( buf, L"%hd/%hd/%hd %hd:%hd", &month, &day, &year, &hour, &minute );
		} break;

		case 'r':
		{
			Zero( bufMonth, 64 );
			Zero( bufWeekday, 64 );
			swscanf( buf, L"%3s %3s %hd %hd %hd:%hd:%hd", bufWeekday, bufMonth, &day, &year, &hour, &minute, &second );
			month = StringToMonthShort( bufMonth );
		} break;

		case 't':
		{
			time_t t; time( &t );
			struct tm* newtime; newtime = localtime( &t );
			year = CastUShort( newtime->tm_year );
			month = CastUShort( newtime->tm_mon+1 );
			day = CastUShort( newtime->tm_mday );
			swscanf( buf, L"%hd:%hd", &hour, &minute );
		} break;

		case 'T':
		{
			time_t t; time( &t );
			struct tm* newtime; newtime = localtime( &t );
			year = CastUShort( newtime->tm_year );
			month = CastUShort( newtime->tm_mon+1 );
			day = CastUShort( newtime->tm_mday );
			swscanf( buf, L"%hd:%hd:%hd", &hour, &minute, &second );
		} break;

		case 'o':
		{
			time_t t; time( &t );
			struct tm* newtime; newtime = localtime( &t );
			year = CastUShort( newtime->tm_year );
			month = CastUShort( newtime->tm_mon+1 );
			day = CastUShort( newtime->tm_mday );
			swscanf( buf, L"%hd:%hd:%hd.%hd", &hour, &minute, &second, &millisecond );
		} break;

		default:
		{
			swscanf( buf, L"%hd-%hd-%hd %hd:%hd:%hd.%hd", &year, &month, &day, &hour, &minute, &second, &millisecond );
		}
		break;
	}

	return DateTime( year, month, day, hour, minute, second, millisecond );
}

String Convert::ToString( Bool value )
{
	return value ? L"true" : L"false";
}

String Convert::ToString( Byte value )
{
	return String::Format( L"{0}", value );
}

String Convert::ToString( Short value )
{
	return String::Format( L"{0}", value );
}

String Convert::ToString( Int value )
{
	return String::Format( L"{0}", value );
}

String Convert::ToString( Long value )
{
	return String::Format( L"{0}", value );
}

String Convert::ToString( UShort value )
{
	return String::Format( L"{0}", value );
}

String Convert::ToString( UInt value )
{
	return String::Format( L"{0}", value );
}

String Convert::ToString( ULong value )
{
	return String::Format( L"{0}", value );
}

String Convert::ToString( Float value )
{
	return String::Format( L"{0}", value );
}

String Convert::ToString( Double value )
{
	return String::Format( L"{0}", value );
}

String Convert::ToString( Double value, const Char* format )
{
	Char buf[40] = {};
	String fmt;
	fmt = fmt.Append( L"{0," );
	fmt = fmt.Append( format );
	fmt = fmt.Append( L"}" );
	fmt.GetChars( 0, 40, buf );
	return String::Format( buf, value );
}

String Convert::ToString( const DateTime& value )
{
	return String::Format( L"{0}", value );
}

String Convert::ToString( const DateTime& value, const Char* format )
{
	Char buf[40] = {};
	String fmt;
	fmt = fmt.Append( L"{0," );
	fmt = fmt.Append( format );
	fmt = fmt.Append( L"}" );
	fmt.GetChars( 0, 40, buf );
	return String::Format( buf, value );
}


} // lang


} // synkro
