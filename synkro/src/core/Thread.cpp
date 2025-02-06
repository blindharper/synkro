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
#include "config.h"
#include "ThreadPool.h"
#include "Thread.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
static DWORD _slot = (DWORD)-1;
static DWORD WINAPI ThreadProc( VOID* lpParameter )
{
	Thread* thread = (Thread*)lpParameter;
	::TlsSetValue( _slot, (LPVOID)thread->ID() );	
	thread->Pool()->RunThread();
	return 0;
}
#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

//------------------------------------------------------------------------------


Thread::Thread( ThreadPool* pool, UInt id ) :
	_pool( pool ),
	_id( id )
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	if ( _slot == (DWORD)-1 )
	{
		_slot = ::TlsAlloc();
		::TlsSetValue( _slot, 0 );
	}
	_handle = ::CreateThread( nullptr, 0, ThreadProc, (LPVOID)this, CREATE_SUSPENDED, nullptr );
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

Thread::Thread()
{
}

Thread::~Thread()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	if ( _handle != nullptr )
	{
		::CloseHandle( _handle );
		_handle = nullptr;
	}
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

UInt Thread::CurrentID()
{
	UInt id = 0;

#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	id = CastUInt( (Pointer)::TlsGetValue(_slot) );
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS

	return id;
}

void Thread::Start()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	::ResumeThread( _handle );
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

void Thread::Join()
{
#if ( SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS )
	DWORD ret = ::WaitForSingleObject( _handle, INFINITE );
	if ( (ret == WAIT_OBJECT_0) || (ret == WAIT_TIMEOUT) )
	{
		::CloseHandle( _handle );
		_handle = nullptr;
	}
#else

#endif // SYNKRO_PLATFORM == SYNKRO_PLATFORM_WINDOWS
}

ThreadPool* Thread::Pool() const
{
	return _pool;
}

UInt Thread::ID() const
{
	return _id;
}


} // core


} // synkro
