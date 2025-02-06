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
// Purpose: Defines mutex.
//==============================================================================
SYNKRO_INLINE Mutex::Mutex()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::InitializeCriticalSection( &_handle );
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	pthread_mutex_init( &_obj, 0 );
#else
#	error Mutex::Mutex() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

SYNKRO_INLINE Mutex::~Mutex()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::DeleteCriticalSection( &_handle );
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	pthread_mutex_destroy( &_obj );
#else
#	error Mutex::~Mutex() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

SYNKRO_INLINE void Mutex::Lock()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::EnterCriticalSection( &_handle );
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	pthread_mutex_lock( &_obj );
#else
#	error Mutex::Lock() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

SYNKRO_INLINE void Mutex::Unlock()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::LeaveCriticalSection( &_handle );
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	pthread_mutex_unlock( &_obj );
#else
#	error Mutex::Unlock() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}
