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
#ifndef _SYNKRO_INTERNAL_MUTEX_
#define _SYNKRO_INTERNAL_MUTEX_


#include "config.h"


// Creates mutex lock.
#define LOCK( MUTEX ) MutexLock __lock( &MUTEX )


// Provides mutual exclusive access to a shared resource.
class Mutex
{
public:
	// Creates the mutex.
	Mutex();

	// Destroys the mutex.
	~Mutex();

	// Acquires exclusive access to the mutex.
	void													Lock();

	// Releases exclusive access to the mutex.
	void													Unlock();

private:
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	CRITICAL_SECTION										_handle;
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	pthread_mutex_t											_obj;
#else
#	error Mutex is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};


// Helper object for mutex locking/unlocking.
class MutexLock
{
public:
	SYNKRO_INLINE MutexLock( Mutex* mutex ) :
		_mutex( mutex )
	{
		_mutex->Lock();
	}

	SYNKRO_INLINE ~MutexLock()
	{
		_mutex->Unlock();
	}

private:
	Mutex*													_mutex;
};


#include "Mutex.inl"


#endif // _SYNKRO_INTERNAL_MUTEX_
