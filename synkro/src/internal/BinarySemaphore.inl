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
// Purpose: Defines binary semaphore.
//==============================================================================
SYNKRO_INLINE BinarySemaphore::BinarySemaphore( synkro::Bool signaled ) SYNKRO_NOEXCEPT :
	_state( signaled ? 0 : 1 )
{
}

SYNKRO_INLINE void BinarySemaphore::Wait() SYNKRO_NOEXCEPT
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	#if ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X64 )
		while ( ::InterlockedExchange64( &_state, 1 ) == 1 ) {};
	#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS	
#else
#	error BinarySemaphore::Wait() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOAS
}

SYNKRO_INLINE void BinarySemaphore::Signal() SYNKRO_NOEXCEPT
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	#if ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X64 )
		::InterlockedExchange64( &_state, 0 );
	#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
#else
#	error BinarySemaphore::Signal() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOAS
}
