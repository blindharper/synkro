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
// Purpose: Defines weekday names.
//==============================================================================
#include "config.h"
#include "Weekdays.h"
#include "SizeOf.h"


//------------------------------------------------------------------------------

using namespace synkro;

//------------------------------------------------------------------------------


Char* WeekdaysShort[] = { L"Sun", L"Mon", L"Tue", L"Wed", L"Thu", L"Fri", L"Sat" };
Char* WeekdaysLong[] = { L"Sunday", L"Monday", L"Tuesday", L"Wednesday", L"Thursday", L"Friday", L"Saturday" };


UInt StringToWeekdayShort( const Char* str )
{
	constexpr UInt count = SizeOf( WeekdaysShort );
	for ( UInt i = 0; i < count; ++i )
	{
		if ( _wcsicmp(str, WeekdaysShort[i]) == 0 )
			return i;
	}
	return none;
}

UInt StringToWeekdayLong( const Char* str )
{
	constexpr UInt count = SizeOf( WeekdaysLong );
	for ( UInt i = 0; i < count; ++i )
	{
		if ( _wcsicmp(str, WeekdaysLong[i]) == 0 )
			return i;
	}
	return none;
}
