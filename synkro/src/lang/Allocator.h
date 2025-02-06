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
// Purpose: Defines memory allocator for objects of type T.
//==============================================================================
#ifndef _SYNKRO_LANG_ALLOCATOR_
#define _SYNKRO_LANG_ALLOCATOR_


#include "config.h"
#include <mem/MemoryManager.h>
#include <new>


// Creates allocator of object of type T.
#define A( T ) synkro::lang::Allocator<T>( __FILE__, __LINE__ )


namespace synkro
{


namespace lang
{


// Manager for storage allocation for objects of type T.
template <class T> 
class Allocator
{
public:
	// Creates named allocator.
	explicit Allocator( const char* name, UInt index );

	// Creates named allocator.
	explicit Allocator( const char* name );

	// Copy by reference.
	Allocator( const Allocator<T>& other );

	// Copy by reference.
	Allocator<T>&											operator=( const Allocator<T>& other );

	// Allocates and constructs count objects.
	T*														Allocate( UInt count );

	// Allocates and constructs a single object.
	T*														Allocate();

	// Destructs and deallocates count objects.
	void													Deallocate( T* ptr, UInt count );

	// Destructs and deallocates a single object.
	void													Deallocate( T* ptr );

	// Constructs object to uninitialized memory.
	T*														Construct( void* ptr, const T& value );
	
	// Destructs object.
	void													Destroy( T* ptr );

	// Retrieves allocator name.
	const char* 											Name() const;

	// Retrieves allocator index.
	UInt 													Index() const;

private:
	const char*												_name;
	UInt													_index;
};


#include "Allocator.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_ALLOCATOR_
