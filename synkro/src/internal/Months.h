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
#ifndef _SYNKRO_INTERNAL_MONTHS_
#define _SYNKRO_INTERNAL_MONTHS_


#include "config.h"


synkro::Char* MonthsShort[];
synkro::Char* MonthsLong[];


synkro::UInt StringToMonthShort( const synkro::Char* str );
synkro::UInt StringToMonthLong( const synkro::Char* str );


#endif // _SYNKRO_INTERNAL_MONTHS_
