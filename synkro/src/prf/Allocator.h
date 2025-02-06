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
// Purpose: Defines memory allocator for objects of type T.
//==============================================================================
#ifndef _SYNKRO_PRF_ALLOCATOR_
#define _SYNKRO_PRF_ALLOCATOR_


#include "config.h"


namespace synkro
{


namespace prf
{


// Manager for storage allocation for objects of type T.
template <class T> 
class Allocator
{
public:
	// Creates named allocator.
	explicit Allocator( const char* name );

	// Copy by reference.
	Allocator( const Allocator<T>& other );

	// Copy by reference.
	Allocator<T>&											operator=( const Allocator<T>& other );

	// Allocates and constructs n objects.
	T*														Allocate( UInt n );

	// Allocates and constructs a single object.
	T*														Allocate();

	// Destructs and deallocates n objects.
	void													Deallocate( T* p, UInt n );

	// Destructs and deallocates a single object.
	void													Deallocate( T* p );

	// Constructs object to uninitialized memory.
	T*														Construct( void* p, const T& v );
	
	// Destructs object.
	void													Destroy( T* p );

	// Retrieves allocator name.
	const char* 											Name() const;

private:
	const char*												_name;
};


#include "Allocator.inl"


} // prf


} // synkro


#endif // _SYNKRO_PRF_ALLOCATOR_
