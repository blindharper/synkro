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
template <class T, class A>
SYNKRO_INLINE Queue<T,A>::Queue( const A& alloc, UInt capacity ) :
	_alloc( alloc ),
	_start( 0 ),
	_end( 0 ),
	_capacity( capacity )
{
	assert( _capacity != 0 );

	Init();
}

template <class T, class A>
SYNKRO_INLINE Queue<T,A>::Queue( const A& alloc ) :
	_alloc( alloc ),
	_start( 0 ),
	_end( 0 ),
	_capacity( DEFAULT_CAPACITY )
{
	Init();
}

template <class T, class A>
SYNKRO_INLINE Queue<T,A>::Queue( const Queue<T,A>& other ) :
	_alloc( other._alloc )
{
	Copy( other );
}

template <class T, class A>
SYNKRO_INLINE Queue<T,A>::~Queue()
{
	Deinit();
}

template <class T, class A>
SYNKRO_INLINE Queue<T,A>& Queue<T,A>::operator=( const Queue<T,A>& other )
{
	if ( this != &other )
	{
		Deinit();
		Copy( other );
	}
	return *this;
}

template <class T, class A>
SYNKRO_INLINE void Queue<T,A>::Add( const T& elem )
{
	_data[_end++] = elem;
	if ( _end >= _capacity )
	{
		_end = 0;
	}
}

template <class T, class A>
SYNKRO_INLINE T& Queue<T,A>::Remove()
{
	T& val = _data[_start].value;
	if ( ++_start >= _capacity )
	{
		_start = 0;
	}
	return val;
}

template <class T, class A>
SYNKRO_INLINE UInt Queue<T,A>::Size() const
{
	return (_start <= _end) ? (_end - _start) : (_end + _capacity - _start);
}

template <class T, class A>
SYNKRO_INLINE UInt Queue<T,A>::Capacity() const
{
	return _capacity;
}

template <class T, class A>
SYNKRO_INLINE void Queue<T,A>::Init()
{
	_data = _alloc.Allocate( _capacity );
}

template <class T, class A>
SYNKRO_INLINE void Queue<T,A>::Deinit()
{
	_alloc.Deallocate( _data, _capacity );
}

template <class T, class A>
SYNKRO_INLINE void Queue<T,A>::Copy( const Queue<T,A>& other )
{
	_alloc = other._alloc;
	_start = other._start;
	_end = other._end;
	_capacity = other._capacity;
	_data = _alloc.Allocate( _capacity );

	for ( UInt i = 0; i < _capacity; ++i )
	{
		_data[i] = other._data[i];
	}
}
