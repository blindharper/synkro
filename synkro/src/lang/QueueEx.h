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
// Purpose: Defines thread-safe queue.
//==============================================================================
#ifndef _SYNKRO_LANG_QUEUEEX_
#define _SYNKRO_LANG_QUEUEEX_


#include "config.h"
#include "Queue.h"
#include <internal/Mutex.h>


namespace synkro
{


namespace lang
{


// Thread-safe queue of elements of type T.
template <class T, class A = Allocator<QueueItem<T> > >
class QueueEx
{
public:
	// Creates thread-safe version of another queue.
	QueueEx( const Queue<T,A>& queue );

	// Frees all allocated resources.
	~QueueEx();

	// Adds the element to the end of the queue.
	void													Add( const T& elem );

	// Removes first element from the queue.
	T&														Remove();

	// Returns the number of elements in the queue.
	UInt													Size() const;

	// Returns queue capacity.
	UInt													Capacity() const;

private:
	Queue<T,A>												_queue;
	Mutex													_mutex;
};


#include "QueueEx.inl"


} // lang


} // synkro


#endif // _SYNKRO_LANG_QUEUEEX_
