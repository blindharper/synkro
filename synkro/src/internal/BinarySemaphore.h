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
#ifndef _SYNKRO_INTERNAL_BINARYSEMAPHORE_
#define _SYNKRO_INTERNAL_BINARYSEMAPHORE_


#include "config.h"


// Creates semaphore lock.
#define SEMAPHORE_LOCK( SEMAPHORE ) BinarySemaphoreLock __lock( &SEMAPHORE )


// Waits until semaphore is released.
#define SEMAPHORE_WAIT( SEMAPHORE )	\
	SEMAPHORE.Wait();

// Signals that semaphore is released.
#define SEMAPHORE_SIGNAL( SEMAPHORE ) \
	SEMAPHORE.Signal();


// Provides synchronized access to a shared resource.
// @see Use SEMAPHORE_WAIT and SEMAPHORE_SIGNAL macros to protect shared resource.
class BinarySemaphore
{
public:
	// Sets the semaphore resource to unlocked state.
	BinarySemaphore( synkro::Bool signaled );

	// Gets access to resource guarded by the semaphore.
	void													Wait();

	// Signals that the resource is ready to be accessed.
	void													Signal();

private:
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	#if ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X64 )
		LONGLONG											_state;
	#elif ( SYNKRO_PROCESSOR == SYNKRO_PROCESSOR_X86 )
		LONG												_state;
	#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
#else
#	error BinarySemaphore is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOAS
};


// Helper object for semaphore waiting/signaling.
class BinarySemaphoreLock
{
public:
	SYNKRO_INLINE BinarySemaphoreLock( BinarySemaphore* semaphore ) :
		_semaphore( semaphore )
	{
		_semaphore->Wait();
	}

	SYNKRO_INLINE ~BinarySemaphoreLock()
	{
		_semaphore->Signal();
	}

private:
	BinarySemaphore*										_semaphore;
};


#include "BinarySemaphore.inl"


#endif // _SYNKRO_INTERNAL_BINARYSEMAPHORE_
