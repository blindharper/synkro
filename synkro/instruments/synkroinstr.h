//==============================================================================
// This file is a part of the Synkro Project.
// 
// Copyright (c) Nobody. No rights reserved :)
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is encouraged without any permission from the Synkro Project.
// Website: https://synkro.org Email: mailto:blindharper70@gmail.com
//
// Purpose: Synkro instrument.
//==============================================================================
#include "config.h"


#if !defined( SYNKROINSTR_API )
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
#	define SYNKROINSTR_API __declspec( dllexport )
#else
#	define SYNKROINSTR_API
#endif // ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )	
#endif // !defined( SYNKROINSTR_API )
