//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is encouraged without any permission from the Synkro Project.
// Website: https://synkro.org Email: mailto:blindharper70@gmail.com
//
// Purpose: Defines standard memory manager.
//==============================================================================
#ifndef _SYNKRO_MEM_STDMEMORYMANAGER_
#define _SYNKRO_MEM_STDMEMORYMANAGER_


#include "config.h"


namespace synkro
{


namespace mem
{


// Debug memory manager. Provides methods for memory allocation/deallocation 
// and gathers statistics on allocated/freed memory.
class StdMemoryManager
{
public:
	// Allocates a block of memory on heap.	 
	// param group Memory group to allocate memory to.
	// param size The size, in bytes of memory block to allocate.
	// return Pointer to allocated memory block, if succeded, null-pointer otherwise.
	static void*											Allocate( void* group, UInt size );

	// Frees a block of memory previously allocated with a call to Allocate.
	// param ptr Pointer to memory block to free.
	// see Allocate.
	static void												Free( void* ptr );

	// Returns the number of bytes currently used by all groups.
	static UInt												BytesUsed();

	// Returns the number of memory blocks currently used by all groups.
	static UInt												BlocksUsed();

	// Returns the maximum number of bytes used by all groups simultaneously.
	static UInt												BytesMaximum();

	// Returns the maximum number of memory blocks used by all groups simultaneously.
	static UInt												BlocksMaximum();

	// Returns all-time number of bytes allocated to all groups.
	static UInt												BytesTotal();

	// Returns all-time number of memory blocks allocated to all groups.
	static UInt												BlocksTotal();

	// Creates new memory group with the specified name.
	// param name Memory group name.
	// return Created memory group.
	static void*											GroupCreate( const char* name );

	// Decrements group reference count and destroys it if no references left.
	// param group Group to release.
	static void												GroupRelease( void* group );

	// Returns the first memory group in the group list. Increments reference count.
	static void*											GroupFirst();

	// Returns the next memory group in the group list. Increments reference count.
	// param group Memory group.
	static void*											GroupNext( void* group );

	// Returns the group name.
	// param group Memory group.
	static const char*										GroupName( void* group );

	// Returns the number of bytes currently used by the group.
	// param group Memory group.
	static UInt												GroupBytesUsed( void* group );

	// Returns the number of memory blocks currently used by the group.
	// param group Memory group.
	static UInt												GroupBlocksUsed( void* group );

	// Returns the maximum number of bytes used by the group simultaneously.
	// param group Memory group.
	static UInt												GroupBytesMaximum( void* group );

	// Returns the maximum number of memory blocks used by the group simultaneously.
	// param group Memory group.
	static UInt												GroupBlocksMaximum( void* group );

	// Returns the all-time number of bytes allocated to the group.
	// param group Memory group.
	static UInt												GroupBytesTotal( void* group );

	// Returns the all-time number of memory blocks allocated to the group.
	// param group Memory group.
	static UInt												GroupBlocksTotal( void* group );

	// Saves memory usage report to disk file.
	// param leaksOnly Force reporting memory leaks only.
	// param plain True to create plain text report, false for rich text report.
	static void												SaveReport( const char* filename, Bool leaksOnly, Bool plain );

private:
	static void												SaveReportPlain( const char* filename, Bool leaksOnly );
	static void												SaveReportRich( const char* filename, Bool leaksOnly );
};


} // mem


} // synkro


#endif // _SYNKRO_MEM_STDMEMORYMANAGER_
