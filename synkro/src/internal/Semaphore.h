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
#ifndef _SYNKRO_INTERNAL_SEMAPHORE_
#define _SYNKRO_INTERNAL_SEMAPHORE_


#include "config.h"


// Provides synchronized access to a shared resource.
class Semaphore
{
public:
	// Creates the semaphore.
	Semaphore( synkro::Int count ) SYNKRO_NOEXCEPT;

	// Destroys the semaphore.
	~Semaphore();

	// Signals the semaphore.
	void													Signal() SYNKRO_NOEXCEPT;

	// Signals the semaphore for all waiting threads.
	void													SignalAll() SYNKRO_NOEXCEPT;

	// Waits for the semaphore.
	void													Wait() SYNKRO_NOEXCEPT;

private:
	synkro::Int												_count;
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	HANDLE													_handle;
#elif ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_LINUX )
	se_t													_obj;
#else
#	error Semaphore is not defined.
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};


#include "Semaphore.inl"


#endif // _SYNKRO_INTERNAL_SEMAPHORE_
