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
// Purpose: Defines COM framework initializer.
//==============================================================================
SYNKRO_INLINE ComInitializer::ComInitializer()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::CoInitializeEx( nullptr, COINIT_MULTITHREADED );
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

SYNKRO_INLINE ComInitializer::~ComInitializer()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::CoUninitialize(); 
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}
