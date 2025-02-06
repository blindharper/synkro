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
#include "config.h"
#include "ThreadPool.h"
#include <lang/Exception.h>
#include <mem/OperatorNew.h>


//------------------------------------------------------------------------------

using namespace synkro::diag;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


class Counter
{
public:
	Counter( Int* count ) :
		_count( count )
	{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
		::InterlockedIncrement( (LONG*)_count );
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
	}

	~Counter()
	{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
		::InterlockedDecrement( (LONG*)_count );
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
	}

private:
	Int*	_count;
};


ThreadPool::ThreadPool( Int capacity, ILog* log ) :
	_threads( A(Thread*) ),
	_tasks( Queue<Task*>(A(TaskEntry)) ),
	_running( true ),
	_capacity( capacity ),
	_active( 0 ),
	_haveWork( capacity ),
	Logger( log, LogFacility::Core )
{
}

ThreadPool::~ThreadPool()
{
	Terminate();
}

void ThreadPool::AddTask( Task* task )
{
	if ( (GetInactiveCount() == 0) && (_active < _capacity) )
	{
		CreateThread();
	}

	_tasks.Add( task );
	_haveWork.Signal();
}

void ThreadPool::RunThread()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::InterlockedDecrement( (LONG*)&_active );
#else
	--_active;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

	while ( _running )
	{
		Task* task = nullptr;

		// Wait till a work is available.
		_haveWork.Wait();
		if ( _tasks.Size() > 0 )
		{
			try
			{
				task = _tasks.Remove();
			}
			catch ( const Exception& ex )
			{
				LogError( MessagePriority::Highest, Formatter::Format(L"Failed to retrieve task from task queue. {0}", ex.Message()) );
			}
		}

		if ( task != nullptr )
		{
			Counter cnt( &_active );
			try
			{
				LogInfo( MessagePriority::Lowest, Formatter::Format(L"Task started.") );
				task->Execute();
				LogInfo( MessagePriority::Lowest, Formatter::Format(L"Task completed.") );
			}
			catch ( const Exception& ex )
			{
				LogError( MessagePriority::Highest, Formatter::Format(L"Failed to execute task. {0}", ex.Message()) );
			}

			delete task;
		}
	}
}

void ThreadPool::Terminate()
{
	_running = false;
	_haveWork.SignalAll();
	for ( UInt i = 0; i < _threads.Size(); ++i  )
	{
		_threads[i]->Join();
		delete _threads[i];
	}
}

UInt ThreadPool::GetThreadCount() const
{
	return _threads.Size();
}

void ThreadPool::CreateThread()
{
	UInt id = _threads.Size()+1;
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating working thread [{0,00}]...", id) );
	Thread* thread = new Thread( this, id );
	_threads.Add( thread );
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::InterlockedIncrement( (LONG*)&_active );
#else
	++_active;
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
	thread->Start();
}

UInt ThreadPool::GetInactiveCount()
{
	return _threads.Size() - _active;
}


} // core


} // synkro
