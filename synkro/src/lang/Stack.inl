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
// Purpose: Defines stack.
//==============================================================================
template <class T, class A>
SYNKRO_INLINE Stack<T,A>::Stack( const A& alloc, UInt capacity ) :
	_alloc( alloc ),
	_index( -1 ),
	_capacity( capacity )
{
	assert( _capacity != 0 );

	Init();
}

template <class T, class A>
SYNKRO_INLINE Stack<T,A>::Stack( const A& alloc ) :
	_alloc( alloc ),
	_index( -1 ),
	_capacity( DEFAULT_CAPACITY )
{
	assert( _capacity != 0 );

	Init();
}

template <class T, class A>
SYNKRO_INLINE Stack<T,A>::Stack( const Stack<T,A>& other ) :
	_alloc( other._alloc )
{
	Copy( other );
}

template <class T, class A>
SYNKRO_INLINE Stack<T,A>::~Stack()
{
	Uninit();
}

template <class T, class A>
SYNKRO_INLINE Stack<T,A>& Stack<T,A>::operator=( const Stack<T,A>& other )
{
	if ( this != &other )
	{
		Uninit();
		Copy( other );
	}
	return *this;
}

template <class T, class A>
SYNKRO_INLINE void Stack<T,A>::Push( const T& elem )
{
	if ( ++_index >= _capacity )
		throw StackOverflowException();

	_data[_index] = elem;
}

template <class T, class A>
SYNKRO_INLINE void Stack<T,A>::Clear()
{
	_index = -1;
}

template <class T, class A>
SYNKRO_INLINE void Stack<T,A>::Pop()
{
	if ( --_index < -1 )
		throw StackUnderflowException();
}

template <class T, class A>
SYNKRO_INLINE T& Stack<T,A>::Top()
{
	assert( (_index >= 0) && (_index < _capacity) );

	return _data[_index];
}

template <class T, class A>
SYNKRO_INLINE const T& Stack<T,A>::Top() const
{
	assert( (_index >= 0) && (_index < _capacity) );

	return _data[_index];
}

template <class T, class A>
SYNKRO_INLINE UInt Stack<T,A>::Size() const
{
	return _index + 1;
}

template <class T, class A>
SYNKRO_INLINE UInt Stack<T,A>::Capacity() const
{
	return _capacity;
}

template <class T, class A>
SYNKRO_INLINE void Stack<T,A>::Init()
{
	_data = _alloc.Allocate( _capacity );
}

template <class T, class A>
SYNKRO_INLINE void Stack<T,A>::Uninit()
{
	_alloc.Deallocate( _data, _capacity );
}

template <class T, class A>
SYNKRO_INLINE void Stack<T,A>::Copy( const Stack<T,A>& other )
{
	_alloc = other._alloc;
	_index = other._index;
	_capacity = other._capacity;
	_data = _alloc.Allocate( _capacity );

	for ( Int i = 0; i < _capacity; ++i )
	{
		_data[i] = other._data[i];
	}
}
