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
// Purpose: Defines semaphore.
//==============================================================================
SYNKRO_INLINE Semaphore::Semaphore( synkro::Int count ) :
	_count( count )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	_handle = ::CreateSemaphore( nullptr, 0, count, nullptr );
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	se_init( &_obj, 0, count );
#else
#	error Semaphore::Semaphore() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

SYNKRO_INLINE Semaphore::~Semaphore()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::CloseHandle( _handle );
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	se_destroy( &_obj );
#else
#	error Semaphore::~Semaphore() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

SYNKRO_INLINE void Semaphore::Signal()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::ReleaseSemaphore( _handle, 1L, nullptr );
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	se_post( &_obj );
#else
#	error Semaphore::Signal() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

SYNKRO_INLINE void Semaphore::SignalAll()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::ReleaseSemaphore( _handle, _count, nullptr );
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	for ( int i = 0; i < _count; ++i ) { se_post( &_obj ); }
#else
	#error ERROR: Semaphore::SignalAll() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

SYNKRO_INLINE void Semaphore::Wait()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::WaitForSingleObject( _handle, INFINITE );
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	se_wait( &_obj );
#else
#	error Semaphore::Wait() is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}
