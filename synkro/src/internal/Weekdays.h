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
#ifndef _SYNKRO_INTERNAL_WEEKDAYS_
#define _SYNKRO_INTERNAL_WEEKDAYS_


#include "config.h"


synkro::Char* WeekdaysShort[];
synkro::Char* WeekdaysLong[];


synkro::UInt StringToWeekdayShort( const synkro::Char* str );
synkro::UInt StringToWeekdayLong( const synkro::Char* str );


#endif // _SYNKRO_INTERNAL_WEEKDAYS_
