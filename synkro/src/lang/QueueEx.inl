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
template <class T, class A>
SYNKRO_INLINE QueueEx<T,A>::QueueEx( const Queue<T,A>& queue ) :
	_queue( queue )
{
}

template <class T, class A>
SYNKRO_INLINE QueueEx<T,A>::~QueueEx()
{
}

template <class T, class A>
SYNKRO_INLINE void QueueEx<T,A>::Add( const T& elem )
{
	LOCK( _mutex );

	_queue.Add( elem );
}

template <class T, class A>
SYNKRO_INLINE T& QueueEx<T,A>::Remove()
{
	LOCK( _mutex );

	return _queue.Remove();
}

template <class T, class A>
SYNKRO_INLINE UInt QueueEx<T,A>::Size() const
{
	return _queue.Size();
}

template <class T, class A>
SYNKRO_INLINE UInt QueueEx<T,A>::Capacity() const
{
	return _queue.Capacity();
}
