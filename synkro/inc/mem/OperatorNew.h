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
// Purpose: Defines debug new/delete operators.
//==============================================================================
#ifndef _SYNKRO_MEM_OPERATORNEW_
#define _SYNKRO_MEM_OPERATORNEW_


#include "config.h"
#include <mem/MemoryManager.h>


#undef new


SYNKRO_INLINE void* operator new( size_t size, const char* file, synkro::Int line )
{
#if !defined( SYNKRO_DISABLE_MEMMGR )
	return synkro::mem::MemoryManager::Allocate( (synkro::UInt)size, file, line );
#else
	return malloc( n );
#endif // !defined( SYNKRO_DISABLE_MEMMGR )
}

SYNKRO_INLINE void* operator new[]( size_t size, const char* file, synkro::Int line )
{
#if !defined( SYNKRO_DISABLE_MEMMGR )
	return synkro::mem::MemoryManager::Allocate( (synkro::UInt)size, file, line );
#else
	return malloc( n );
#endif // !defined( SYNKRO_DISABLE_MEMMGR )
}

SYNKRO_INLINE void operator delete( void* ptr, const char* file, synkro::Int line )
{
#if !defined( SYNKRO_DISABLE_MEMMGR )
	synkro::mem::MemoryManager::Free( ptr, 0 );
#else
	free( ptr );
#endif // !defined( SYNKRO_DISABLE_MEMMGR )
}

SYNKRO_INLINE void* operator new( size_t size )
{
#if !defined( SYNKRO_DISABLE_MEMMGR )
	return synkro::mem::MemoryManager::Allocate( (synkro::UInt)size, "Default", -1 );
#else
	return malloc( n );
#endif // !defined( SYNKRO_DISABLE_MEMMGR )
}

SYNKRO_INLINE void* operator new[]( size_t size )
{
#if !defined( SYNKRO_DISABLE_MEMMGR )
	return synkro::mem::MemoryManager::Allocate( (synkro::UInt)size, "Default[]", -1 );
#else
	return malloc( size );
#endif // !defined( SYNKRO_DISABLE_MEMMGR )
}

SYNKRO_INLINE void operator delete( void* ptr )
{
#if !defined( SYNKRO_DISABLE_MEMMGR )
	synkro::mem::MemoryManager::Free( ptr, 0 );
#else
	free( ptr );
#endif // !defined( SYNKRO_DISABLE_MEMMGR )
}


#define SYNKRO_NEW new( __FILE__, __LINE__ )
#define new SYNKRO_NEW


#endif // _SYNKRO_MEM_OPERATORNEW_
