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
// Purpose: Defines linked list iterator.
//==============================================================================
template <class T>
SYNKRO_INLINE ListIterator<T>::ListIterator( ListItem<T>* item ) :
	_item( item )
{
}

template <class T>
SYNKRO_INLINE ListIterator<T>::ListIterator() :
	_item( nullptr )
{
}

template <class T>
SYNKRO_INLINE ListIterator<T>& ListIterator<T>::operator++()
{
	assert( _item != nullptr );

	_item = _item->next;
	return *this;
}

template <class T>
SYNKRO_INLINE ListIterator<T> ListIterator<T>::operator++( Int )
{
	assert( _item != nullptr );
	
	ListIterator<T> it( _item );
	_item = _item->next;
	return it;
}

template <class T>
SYNKRO_INLINE ListIterator<T>& ListIterator<T>::operator--()
{
	assert( _item != nullptr );

	_item = _item->prev;
	return *this;
}

template <class T>
SYNKRO_INLINE ListIterator<T> ListIterator<T>::operator--( Int )
{
	assert( _item != nullptr );
	
	ListIterator<T> it( _item );
	_item = _item->prev;
	return it;
}

template <class T>
SYNKRO_INLINE Bool ListIterator<T>::operator==( const ListIterator<T>& other ) const
{
	return _item == other._item;
}

template <class T>
SYNKRO_INLINE Bool ListIterator<T>::operator!=( const ListIterator<T>& other ) const
{
	return _item != other._item;
}

template <class T>
SYNKRO_INLINE T& ListIterator<T>::operator*() const
{
	assert( _item != nullptr );

	return _item->value;
}

template <class T>
SYNKRO_INLINE T& ListIterator<T>::operator->() const
{
	assert( _item != nullptr );

	return _item->value;
}

template <class T>
SYNKRO_INLINE Bool ListIterator<T>::IsValid() const
{
	return _item && _item->value;
}

template <class T>
SYNKRO_INLINE ListItem<T>* ListIterator<T>::Item() const
{
	return _item;
}
