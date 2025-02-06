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
// Purpose: Defines dynamic array.
//==============================================================================
template <class T, class A>
SYNKRO_INLINE Vector<T,A>::Vector( const T* elems, UInt size, const A& alloc ) :
	_alloc( alloc ),
	_data( 0 ),
	_capacity( 0 ),
	_size( 0 )
{
	if ( size > 0 )
	{
		SetSize( size );
		Copy( _data, elems, _size );
	}
}

template <class T, class A>
SYNKRO_INLINE Vector<T,A>::Vector( const A& alloc, UInt capacity ) :
	_alloc( alloc ),
	_data( 0 ),
	_capacity( capacity ),
	_size( 0 )
{
	if ( _capacity > 0 )
	{
		_data = _alloc.Allocate( _capacity );
	}
}

template <class T, class A>
SYNKRO_INLINE Vector<T,A>::Vector( const A& alloc ) :
	_alloc( alloc ),
	_data( 0 ),
	_capacity( 0 ),
	_size( 0 )
{
}

template <class T, class A>
SYNKRO_INLINE Vector<T,A>::Vector( const Vector<T,A>& other ) :
	_alloc( other._alloc )
{
	_data = 0;
	_capacity = 0;
	_size = 0;

	if ( other._size > 0 )
	{
		SetSize( other._size );
		Copy( _data, other._data, _size );
	}
}

template <class T, class A>
SYNKRO_INLINE Vector<T,A>::~Vector()
{
	Destroy();
}

template <class T, class A>
SYNKRO_INLINE Vector<T,A>& Vector<T,A>::operator=( const Vector<T,A>& other )
{
	if ( this != &other )
	{
		_alloc = other._alloc;
		SetSize( other._size );
		if ( other._size > 0 )
			Copy( _data, other._data, _size );
	}
	return *this;
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::SetSize( UInt size, const T& value )
{
	T* data = 0;
	UInt cap = 0;

	assert( size >= 0 );

	try
	{
		if ( size < _size )
		{
			while ( _size > size )
			{
				_alloc.Destroy( _data + --_size );
			}
		}
		else if ( size <= _capacity )
		{
			while ( _size < size )
			{
				_alloc.Construct( _data + _size++, value );
			}
		}
		else // size > _capacity
		{
			assert( size > _capacity );

			cap = GetCapacity( size );
			if ( cap < _capacity*2 )
				cap = _capacity*2;

			// Allocate new memory block.
			data = _alloc.Allocate( cap );

			// Copy existing data.
			Copy( data, _data, _size );

			// Fill new elements.
			for ( UInt i = _size ; i < size ; ++i )
			{
				data[i] = value;
			}
			Destroy();

			for ( UInt i = size ; i < cap ; ++i )
			{
				_alloc.Destroy( data+i );
			}

			// Save new data.
			_data = data;
			_size = size;
			_capacity = cap;
		}
	}
	catch ( ... )
	{
		_alloc.Deallocate( data, cap );
		throw;
	}
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::SetSize( UInt size )
{
	SetSize( size, T() );
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Add( const T& elem )
{
	SetSize( _size+1 );
	_data[_size-1] = elem;
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Add( const T* elems, UInt size )
{
	assert( elems != nullptr );

	if ( size > 0 )
	{
		UInt oldSize = _size;
		SetSize( _size + size );
		Copy( _data+oldSize, elems, size );
	}
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Insert( UInt index, const T& elem )
{
	SetSize( _size+1 );

	T* start = _data + index - 1;
	T* src = _data + _size-2;
	T* dst = _data + _size-1;
	while ( src != start )
	{
		*dst-- = *src--;
	}
	_alloc.Construct( _data+index, elem );
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Set( UInt start, const T* elems, UInt size )
{
	assert( elems != nullptr );

	if ( size > 0 )
	{
		Copy( _data+start, elems, size );
	}
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Swap( UInt first, UInt second )
{
	assert( first < _size );
	assert( second < _size );

	if ( first != second )
	{
		T tmp = *(_data+first);
		*(_data+first) = *(_data+second);
		*(_data+second) = tmp;
	}
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Remove( UInt index )
{
	assert( index < _size );

	Copy( _data+index, _data+(index+1), _size-(index+1) );
	_alloc.Destroy( _data+_size-1 );
	--_size;
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Remove( const T& elem )
{
	const UInt index = IndexOf( elem );
	if ( index != none )
	{
		Remove( index );
	}
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::TrimToSize()
{
	T* tmp = 0;
	UInt size = _size;

	try
	{
		if ( size > 0 )
			tmp = _alloc.Allocate( size );
		Copy( tmp, _data, size );
		Destroy();

		_data = tmp;
		_size = size;
		_capacity = size;
	}
	catch ( ... )
	{
		_alloc.Deallocate( tmp, size );
		throw;
	}
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Clear()
{
	SetSize( 0 );
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Sort()
{
	if ( _size > 1 )
	{
		QuickSort( _data, 0, _size-1 );
	}
}

template<class T, class A> template<class F, class P>
SYNKRO_INLINE void Vector<T,A>::Each( F& function, const P& param )
{
	for ( UInt i = 0; i < _size; ++i )
	{
		if ( !function.Call(_data[i], param) )
			break;
	}
}

template<class T, class A> template<class F>
SYNKRO_INLINE void Vector<T,A>::Each( F& function )
{
	for ( UInt i = 0; i < _size; ++i )
	{
		if ( !function.Call(_data[i]) )
			break;
	}
}

template <class T, class A>
SYNKRO_INLINE T& Vector<T,A>::operator[]( UInt index )
{
	assert( index < _size );

	return _data[index];
}

template <class T, class A>
SYNKRO_INLINE T& Vector<T,A>::LastValue()
{
	assert( _size > 0 );

	return _data[_size-1];
}

template<class T, class A> template<class F, class P>
SYNKRO_INLINE void Vector<T,A>::Each( F& function, const P& param ) const
{
	for ( UInt i = 0; i < _size; ++i )
	{
		if ( !function.Call(_data[i], param) )
			break;
	}
}

template<class T, class A> template<class F>
SYNKRO_INLINE void Vector<T,A>::Each( F& function ) const
{
	for ( UInt i = 0; i < _size; ++i )
	{
		if ( !function.Call(_data[i]) )
			break;
	}
}

template <class T, class A>
SYNKRO_INLINE const T& Vector<T,A>::operator[]( UInt index ) const
{
	assert( index < _size );

	return _data[index];
}

template <class T, class A>
SYNKRO_INLINE const T& Vector<T,A>::LastValue() const
{
	assert( _size > 0 );

	return _data[_size-1];
}

template <class T, class A>
SYNKRO_INLINE UInt Vector<T,A>::IndexOf( const T& elem, UInt start ) const
{
	for ( UInt i = start; i < _size; ++i )
	{
		if ( _data[i] == elem )
			return i;
	}
	return none;
}

template <class T, class A>
SYNKRO_INLINE UInt Vector<T,A>::IndexOf( const T& elem ) const
{
	return IndexOf( elem, 0 );
}

template <class T, class A>
SYNKRO_INLINE UInt Vector<T,A>::LastIndexOf( const T& elem, UInt start ) const
{
	if ( start == none )
		start = _size-1;

	for ( UInt i = start; i > 0; --i )
	{
		if ( _data[i] == elem )
			return i;
	}
	return none;
}

template <class T, class A>
SYNKRO_INLINE UInt Vector<T,A>::LastIndexOf( const T& elem ) const
{
	return LastIndexOf( elem, none );
}

template <class T, class A>
SYNKRO_INLINE Bool Vector<T,A>::Contains( const T& elem ) const
{
	return (IndexOf(elem) != none);
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Get( UInt start, T* elems, UInt size ) const
{
	assert( elems != nullptr );

	if ( size > 0 )
	{
		Copy( elems, (const T*)(_data+start), size );
	}
}

template <class T, class A>
SYNKRO_INLINE UInt Vector<T,A>::Capacity() const
{
	return _capacity;
}

template <class T, class A>
SYNKRO_INLINE UInt Vector<T,A>::Size() const
{
	return _size;
}

template <class T, class A>
SYNKRO_INLINE Bool Vector<T,A>::IsEmpty() const
{
	return _size == 0;
}

template <class T, class A>
SYNKRO_INLINE T* Vector<T,A>::Begin() const
{
	return _data;
}

template <class T, class A>
SYNKRO_INLINE T* Vector<T,A>::Last() const
{
	return (_size > 0) ? _data + _size-1 : 0;
}

template <class T, class A>
SYNKRO_INLINE T* Vector<T,A>::End() const
{
	return _data + _size;
}

template <class T, class A>
SYNKRO_INLINE T* Vector<T,A>::Get( UInt index ) const
{
	assert( index < _size );

	return _data + index;
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Destroy()
{
	while ( _size < _capacity )
	{
		_alloc.Construct( _data + _size++, T() );
	}

	_alloc.Deallocate( _data, _capacity );
	_data = 0;
	_capacity = 0;
	_size = 0;
}

template <class T, class A>
SYNKRO_INLINE void Vector<T,A>::Copy( T* dst, const T* src, UInt count )
{
	T* end = dst + count;
	while ( dst != end )
	{
		*dst++ = *src++;
	}
}

template <class T, class A>
SYNKRO_INLINE UInt Vector<T,A>::GetCapacity( UInt size )
{
	Int cap = size + 1;
	cap += 15;
	cap &= ~15;
	return cap;
}
