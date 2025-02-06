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
// Purpose: Defines months names.
//==============================================================================
#include "config.h"
#include "Months.h"
#include "SizeOf.h"


//------------------------------------------------------------------------------

using namespace synkro;

//------------------------------------------------------------------------------


Char* MonthsShort[] = { L"", L"Jan", L"Feb", L"Mar", L"Apr", L"May", L"Jun", L"Jul", L"Aug", L"Sep", L"Oct", L"Nov", L"Dec" };
Char* MonthsLong[] = { L"", L"January", L"February", L"March", L"April", L"May", L"June", L"July", L"August", L"September", L"October", L"November", L"December" };


UInt StringToMonthShort( const Char* str )
{
	constexpr UInt count = SizeOf( MonthsShort );
	for ( UInt i = 1; i < count; ++i )
	{
		if ( _wcsicmp(str, MonthsShort[i]) == 0 )
			return i;
	}
	return none;
}

UInt StringToMonthLong( const Char* str )
{
	constexpr UInt count = SizeOf( MonthsLong );
	for ( UInt i = 1; i < count; ++i )
	{
		if ( _wcsicmp(str, MonthsLong[i]) == 0 )
			return i;
	}
	return none;
}
