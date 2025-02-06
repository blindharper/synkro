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
// Purpose: Thread pool.
//==============================================================================
#ifndef _SYNKRO_CORE_THREADPOOL_
#define _SYNKRO_CORE_THREADPOOL_


#include "config.h"
#include <lang/Ptr.h>
#include <lang/QueueEx.h>
#include <lang/Vector.h>
#include <lang/Formatter.h>
#include <core/Task.h>
#include <internal/Logger.h>
#include <internal/Semaphore.h>
#include "Thread.h"


namespace synkro
{


namespace core
{


// Thread pool.
class SYNKRO_API ThreadPool :
	public Logger
{
public:
	// Constructor & destructor.
	ThreadPool( Int capacity, diag::ILog* log );
	~ThreadPool();

	// Adds a task to execute.
	void													AddTask( Task* task );

	// Executes working thread.
	void													RunThread();

	// Terminates all working threads.
	void													Terminate();

	// Returns the number of active threads.
	UInt													GetThreadCount() const;

private:
	typedef lang::QueueItem<Task*>							TaskEntry;

	lang::Vector<Thread*>									_threads;
	lang::QueueEx<Task*>									_tasks;
	Semaphore												_haveWork;
	Bool													_running;
	Int														_capacity;
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	__declspec( align(4) ) Int								_active;
#else
	Int														_active;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

	void													CreateThread();
	UInt													GetInactiveCount();
};


} // core


} // synkro


#endif // _SYNKRO_CORE_THREADPOOL_
