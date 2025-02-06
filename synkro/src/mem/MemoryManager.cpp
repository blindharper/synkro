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
// Purpose: Memory manager wrapper.
//==============================================================================
#include "config.h"
#include <mem/MemoryManager.h>
#include <core/Platform.h>
#include <core/CallStack.h>
#include <lang/String.h>
#include <internal/DynamicLibrary.h>
#include <internal/BinarySemaphore.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro;

//------------------------------------------------------------------------------


static DynamicLibrary _module;				// Library module handle.
static BinarySemaphore _semaphore( true );	// Binary semaphore for synchronization.


static void StubMemInitialize( Bool )
{
	// Do nothing.
}

static void* StubMemAllocate( UInt size, const char*, UInt )
{
	SEMAPHORE_WAIT( _semaphore );
	void* p = malloc( size );
	SEMAPHORE_SIGNAL( _semaphore );
	return p;
}

static void StubMemFree( void* address, UInt )
{
	SEMAPHORE_WAIT( _semaphore );
	free( address );
	SEMAPHORE_SIGNAL( _semaphore );
}

static void StubMemGetStats( UInt*, UInt )
{
	// Do nothing.
}

static void StubMemSaveReport( const char*, Bool, Bool )
{
	// Do nothing.
}

//------------------------------------------------------------------------------

namespace synkro
{


namespace mem
{


static SYNKRO_FUNC_SETBOOL		_funcInitialize = nullptr;	// Initialize().
static SYNKRO_FUNC_ALLOCATE		_funcAllocate = nullptr;	// Allocate().
static SYNKRO_FUNC_FREE			_funcFree = nullptr;		// Free().
static SYNKRO_FUNC_GET_STATS	_funcGetStats = nullptr;	// GetStats().
static SYNKRO_FUNC_SAVE_REPORT	_funcSaveReport = nullptr;	// SaveReport().


void MemoryManager::Initialize( const char* filename, Bool showLines )
{
	if ( (_funcInitialize == nullptr) && (_funcAllocate == nullptr) && (_funcFree == nullptr) && (_funcSaveReport == nullptr) && (_funcGetStats == nullptr) )
	{
		if ( (filename != nullptr) && (strlen(filename) > 0) )
		{
			char module[260] = {};
			char suffix[32] = {};
			strcpy( module, filename );
			char* dot = strrchr( module, '.' );
			if ( dot )
			{
				strcpy( suffix, dot );
				*dot = 0;
			}
#ifdef SYNKRO_DEBUG
			strcat( module, "_debug" );
#endif // SYNKRO_DEBUG
			if ( dot )
			{
				strcat( module, suffix );
			}
			size_t len = wcslen( Platform::DynamicLibraryExtension );
			for ( size_t i = 0; i < len; ++i )
			{
				char ch = (char)Platform::DynamicLibraryExtension[i];
				strncat( module, &ch, 1 );
			}

			// Load module into memory.
			_module.Open( module );
			if ( !_module.IsOpen() )
			{
				Platform::Error( L"Failed to load memory manager." );
				throw;
			}

			// Get required entry points.
			_funcInitialize	= (SYNKRO_FUNC_SETBOOL)_module.GetSymbol( "SynkroMemInitialize" );
			_funcAllocate	= (SYNKRO_FUNC_ALLOCATE)_module.GetSymbol( "SynkroMemAllocate" );
			_funcFree		= (SYNKRO_FUNC_FREE)_module.GetSymbol( "SynkroMemFree" );
			_funcGetStats	= (SYNKRO_FUNC_GET_STATS)_module.GetSymbol( "SynkroMemGetStats" );
			_funcSaveReport	= (SYNKRO_FUNC_SAVE_REPORT)_module.GetSymbol( "SynkroMemSaveReport" );

			// Verify entry points.
			if ( (_funcInitialize == nullptr) || (_funcSaveReport == nullptr) || (_funcAllocate == nullptr) || (_funcFree == nullptr) || (_funcGetStats == nullptr) )
			{
				Platform::Error( L"Memory manager is corrupted." );
				throw;
			}
		}
		else
		{
			// Use stub implementation.
			_funcInitialize	= StubMemInitialize;
			_funcAllocate	= StubMemAllocate;
			_funcFree		= StubMemFree;
			_funcGetStats	= StubMemGetStats;
			_funcSaveReport	= StubMemSaveReport;
		}

		// Perform initialization.
		_funcInitialize( showLines );
	}
}

void MemoryManager::Finalize()
{
	_module.Close();
	_funcInitialize = nullptr;
	_funcAllocate = nullptr;
	_funcFree = nullptr;
	_funcGetStats = nullptr;
	_funcSaveReport = nullptr;
}

void* MemoryManager::Allocate( UInt size, const char* file, UInt line )
{
	char name[260] = {};
	strcpy( name, file );

	char* s = strrchr( name, '/' );
	char* bs = strrchr( name, '\\' );
	if ( s || bs )
	{
		char* p = max( s, bs );
		*p = '|';
		s = strrchr( name, '/' );
		bs = strrchr( name, '\\' );
		if ( s || bs )
		{
			p = max( s, bs );
			strcpy( name, ++p );
		}
		p = strchr( name, '|' );
		*p = '/';
	}

	return _funcAllocate( size, name, line );
}

void MemoryManager::Free( void* p, UInt size )
{
	return _funcFree( p, size );
}

void MemoryManager::GetStats( MemoryStats& stats )
{
	if ( _funcGetStats != nullptr )
	{
		UInt bytes[3];
		_funcGetStats( bytes, 3 );
		stats.UsedByteCount = bytes[0];
		stats.MaximumByteCount = bytes[1];
		stats.TotalByteCount = bytes[2];
	}
}

void MemoryManager::SaveReport( const char* filename, Bool leaksOnly, Bool plain )
{
	CallStack::Finalize();
	String::Finalize();

	if ( _funcSaveReport != nullptr )
	{
		_funcSaveReport( filename, leaksOnly, plain );
	}
}


} // mem


} // synkro
