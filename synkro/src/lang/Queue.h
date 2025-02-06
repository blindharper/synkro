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
// Purpose: Defines queue.
//==============================================================================
#ifndef _SYNKRO_LANG_QUEUE_
#define _SYNKRO_LANG_QUEUE_


#include "config.h"
#include "Allocator.h"
#include "QueueItem.h"


namespace synkro
{


namespace lang
{


// Queue of elements of type T.
template <class T, class A = Allocator<QueueItem<T> > >
class Queue
{
public:
	enum
	{
		// Default queue capacity.
		DEFAULT_CAPACITY = 64,
	};

	// Constructs an empty queue of the given capacity.
	explicit Queue( const A& alloc, UInt capacity );

	// Constructs an empty queue of default capacity.
	explicit Queue( const A& alloc );

	// Creates a copy of another queue.
	Queue( const Queue<T,A>& other );

	// Frees all allocated resources.
	~Queue();

	// Creates a copy of another queue.
	Queue<T,A>&												operator=( const Queue<T,A>& other );

	// Adds the element to the end of the queue.
	void													Add( const T& elem );

	// Removes first element from the queue.
	T&														Remove();

	// Returns the number of elements in the queue.
	UInt													Size() const;

	// Returns queue capacity.
	UInt													Capacity() const;

private:
	QueueItem<T>*											_data;
	A														_alloc;
	UInt													_start;
	UInt													_end;
	UInt													_capacity;

	void													Init();
	void													Deinit();
	void													Copy( const Queue<T,A>& other );
};


#include "Queue.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_QUEUE_
