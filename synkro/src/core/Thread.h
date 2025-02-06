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
// Purpose: OS thread.
//==============================================================================
#ifndef _SYNKRO_CORE_THREAD_
#define _SYNKRO_CORE_THREAD_


#include "config.h"


namespace synkro
{


namespace core
{


class ThreadPool;


// OS thread. Used to process tasks found in the thread pool.
class Thread
{
public:
	// Creates a thread in the given pool.
	Thread( ThreadPool* pool, UInt id );

	// Creates default thread.
	Thread();

	// Destroys thread.
	~Thread();

	// Retrieves calling thread identifier.
	static UInt												CurrentID();

	// Starts the thread.
	void													Start();

	// Waits for thread to die and releases thread resources.
	void													Join();

	// Retrieves pool to which this thread belongs.
	ThreadPool*												Pool() const;

	// Retrieves thread's unique identifier.
	UInt													ID() const;

private:
	ThreadPool*												_pool;
	UInt													_id;
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	HANDLE													_handle;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
};


} // core


} // synkro


#endif // _SYNKRO_CORE_THREAD_
