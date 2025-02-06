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
// Purpose: Visual exception handler.
//==============================================================================
#include "config.h"
#include "ExceptionHandler.h"
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	#include "Win32/Win32ExceptionHandler.h"
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


void ExceptionHandler::Initialize( Pointer module, ISynkro* synkro )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	Win32ExceptionHandler::Initialize( module, synkro );
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

void ExceptionHandler::Show( const String& message )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	Win32ExceptionHandler::Show( message );
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}


} // core


} // synkro
