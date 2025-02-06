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
// Purpose: Defines linked list.
//==============================================================================
template <class T, class A>
SYNKRO_INLINE List<T,A>::List( const A& alloc ) :
	_alloc( alloc ),
	_begin( nullptr ),
	_size( 0 )
{
	_end = _alloc.Allocate();
}

template <class T, class A>
SYNKRO_INLINE List<T,A>::List( const List<T,A>& other ) :
	_alloc( other._alloc ),
	_begin( nullptr ),
	_size( 0 )
{
	_end = _alloc.Allocate();
	Copy( other );
}

template <class T, class A>
SYNKRO_INLINE List<T,A>::~List()
{
	Clear();
	_alloc.Deallocate( _end );
}

template <class T, class A>
SYNKRO_INLINE List<T,A>& List<T,A>::operator=( const List<T,A>& other )
{
	if ( *this != other )
	{
		Clear();
		_alloc = other._alloc;
		Copy( other );
	}
	return *this;
}

template <class T, class A>
SYNKRO_INLINE ListIterator<T> List<T,A>::Find( const T& elem, const ListIterator<T>& it )
{
	assert( it.IsValid() );

	if ( !it.IsValid() )
		return ListIterator<T>();

	ListItem<T>* item = it.Item();
	for ( ; (item != _end) && (elem != item->value); item = item->next )
	{
	}

	return ListIterator<T>( item );
}

template <class T, class A>
SYNKRO_INLINE ListIterator<T> List<T,A>::Find( const T& elem )
{
	return Find( elem, _begin );
}

template <class T, class A>
SYNKRO_INLINE ListIterator<T> List<T,A>::FindLast( const T& elem, const ListIterator<T>& it )
{
	if ( !it.IsValid() )
		return ListIterator<T>();

	ListItem<T>* item = it.Item();
	for ( ; (item != _begin) && (elem != item->value); item = item->prev )
	{
	}

	return ListIterator<T>( item );
}

template <class T, class A>
SYNKRO_INLINE ListIterator<T> List<T,A>::FindLast( const T& elem )
{
	return FindLast( elem, _end );
}

template <class T, class A>
SYNKRO_INLINE ListIterator<T> List<T,A>::Insert( const T& elem, const ListIterator<T>& it )
{
	ListItem<T>* item;
	ListItem<T>* old = it.Item();

	if ( (old == _begin) || ((old == _end) && (_size == 0)) )
	{
		if ( _size == 0 )
		{
			_begin = _alloc.Allocate();
			_begin->next = _end;
			_end->prev = _begin;
			item = _begin;
		}
		else
		{
			item = _alloc.Allocate();
			item->prev = _begin->prev;
			item->next = _begin;
			_begin->prev = item;
			_begin = item;
		}		
	}
	else
	{
		item = _alloc.Allocate();
		item->prev = old->prev;
		item->next = old;
		old->prev->next = item;
		old->prev = item;
	}
	item->value = elem;
	++_size;

	return ListIterator<T>( item );
}

template <class T, class A>
SYNKRO_INLINE ListIterator<T> List<T,A>::Insert( const T& elem )
{
	return Insert( elem, _begin );
}

template <class T, class A>
SYNKRO_INLINE ListIterator<T> List<T,A>::Add( const T& elem )
{
	return Insert( elem, _end );
}

template <class T, class A>
SYNKRO_INLINE Bool List<T,A>::Remove( const ListIterator<T>& it )
{
	if ( _size == 0 )
		return false;

	assert( it.IsValid() );

	if ( !it.IsValid() || (it == _end) )
		return false;

	ListItem<T>* item = it.Item();

	if ( item == _begin )
	{
		if ( _begin->next == _end )
		{
			_alloc.Deallocate( _begin );
			_begin = nullptr;
			_end->prev = nullptr;
		}
		else
		{
			_begin = _begin->next;
			_begin->prev = nullptr;
			_alloc.Deallocate( item );
		}
	}
	else
	{
		item->prev->next = item->next;
		item->next->prev = item->prev;
		_alloc.Deallocate( item );
	}
	--_size;

	return true;
}

template <class T, class A>
SYNKRO_INLINE Bool List<T,A>::Remove( const T& elem )
{
	ListIterator<T> it = Find( elem );
	return Remove( it );
}

template <class T, class A>
SYNKRO_INLINE void List<T,A>::Clear()
{
	if ( _size == 0 )
		return;

	ListItem<T>* item = _begin;
	while ( item != _end )
	{
		ListItem<T>* tmp = item;
		item = item->next;
		_alloc.Deallocate( tmp );
	}
	_begin = nullptr;
	_end->prev = nullptr;
	_size = 0;
}

template <class T, class A>
SYNKRO_INLINE void List<T,A>::Sort()
{
	ListItem<T>* begin = _begin;
	ListItem<T>* end = _end->prev;
	for ( ; (begin != end) && (begin->next != end) ; begin = begin->next, end = end->prev )
	{
		for ( ListItem<T>* item = begin->next; item != end; item = item->next )
		{
			if ( item->value < begin->value )
			{
				T tmp = begin->value;
				begin->value = item->value;
				item->value = tmp;
			}
			else if ( end->value item->value )
			{
				T tmp = end->value;
				end->value = item->value;
				item->value = tmp;
			}
		}
	}
}

template <class T, class A>
SYNKRO_INLINE ListIterator<T> List<T,A>::Begin()
{
	return (_size != 0) ? _begin : _end;
}

template <class T, class A>
SYNKRO_INLINE const ListIterator<T> List<T,A>::Begin() const
{
	return (_size != 0) ? _begin : _end;
}

template <class T, class A>
SYNKRO_INLINE ListIterator<T> List<T,A>::End()
{
	return _end;
}

template <class T, class A>
SYNKRO_INLINE const ListIterator<T> List<T,A>::End() const
{
	return _end;
}

template <class T, class A>
SYNKRO_INLINE UInt List<T,A>::Size() const
{	
	return _size;
}

template <class T, class A>
SYNKRO_INLINE Bool List<T,A>::IsEmpty() const
{
	return (_size == 0);
}

template <class T, class A>
SYNKRO_INLINE void List<T,A>::Copy( const List<T,A>& other )
{
	if ( other._size != 0 )
	{
		ListItem<T>* item = other._begin;
		for ( ; item != other._end; item = item->next )
		{
			Add( item->value );
		}
		_size = other._size;
	}
}
