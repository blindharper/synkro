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
// Purpose: Interface to Synkro memory manager.
//==============================================================================
#ifndef _SYNKRO_MEM_MEMORYMANAGER_
#define _SYNKRO_MEM_MEMORYMANAGER_


#include "config.h"
#include <mem/MemoryStats.h>


// Initializes memory manager.
#define SynkroMemoryInit( MODULE, SHOWLINES, REPORT, LEAKSONLY, PLAIN ) synkro::mem::MemoryInitializer __mi( MODULE, SHOWLINES, REPORT, LEAKSONLY, PLAIN )


namespace synkro
{


namespace mem
{


/**
 * Debug memory manager. Provides the means for memory allocation
 * and deallocation, and prints statistics on allocated/freed memory.
 */
class SYNKRO_API MemoryManager
{
public:
	/**
	 * Loads and initializes the specified memory manager module.
	 * @param filename Memory manager module filename. If empty, there will be no memory manager.
	 * @param showLines Indicates whether to gather statistics for particular lines.
	 */
	static void												Initialize( const char* filename, Bool showLines );

	/**
	 * Uninitializes and unloads memory manager.
	 */
	static void												Finalize();

	/**
	 * Allocates a block of memory.
	 * @param size The size, in bytes of memory block to allocate.
	 * @param file Name of the source file that allocated the block.
	 * @param line Line number containing the call to Allocate.
	 * @return Pointer to allocated memory block, if succeded, nullptr otherwise.
	 */
	static void*											Allocate( UInt size, const char* file, UInt line );

	/** 
	 * Frees a block of memory previously allocated with a call to Allocate.
	 * @param address Address of memory block to deallocate.
	 * @param size The size, in bytes of memory block to deallocate.
	 */
	static void												Free( void* address, UInt size );

	/** 
	 * Retrieves memory usage statistics.
	 */
	static void												GetStats( MemoryStats& stats );

	/** 
	 * Saves memory report to a file.
	 * @param filename Memory report filename.
	 * @param leaksOnly True to force reporting memory leaks only.
	 * @param plain True to create plain text report, false for rich text report.
	 */
	static void												SaveReport( const char* filename, Bool leaksOnly, Bool plain );
};


/**
 * Helper object used to initialize and finalize memory manager.
 */
class MemoryInitializer
{
public:
	SYNKRO_INLINE MemoryInitializer( const char* module, Bool showLines, const char* report, Bool leaksOnly, Bool plain ) :
		_report( report ),
		_leaksOnly( leaksOnly ),
		_plain( plain )
	{
		MemoryManager::Initialize( module, showLines );
	}

	SYNKRO_INLINE ~MemoryInitializer()
	{
		MemoryManager::SaveReport( _report, _leaksOnly, _plain );
		MemoryManager::Finalize();
	}

private:
	const char*	_report;
	Bool		_leaksOnly;
	Bool		_plain;
};


} // mem


} // synkro


#endif // _SYNKRO_MEM_MEMORYMANAGER_
