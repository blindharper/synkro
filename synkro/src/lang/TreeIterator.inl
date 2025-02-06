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
// Purpose: Defines tree iterator.
//==============================================================================
template <class T>
SYNKRO_INLINE TreeIterator<T>::TreeIterator( TreeItem<T>* item ) :
	_item( item )
{
}

template <class T>
SYNKRO_INLINE TreeIterator<T>::TreeIterator() :
	_item( nullptr )
{
}

template <class T>
SYNKRO_INLINE TreeIterator<T>& TreeIterator<T>::operator--()
{
	assert( _item != nullptr );

	_item = _item->parent;
	return *this;
}

template <class T>
SYNKRO_INLINE TreeIterator<T>& TreeIterator<T>::operator--( Int )
{
	assert( _item != nullptr );

	_item = _item->prev;
	return *this;
}

template <class T>
SYNKRO_INLINE TreeIterator<T>& TreeIterator<T>::operator++()
{
	assert( _item != nullptr );

	_item = _item->child;
	return *this;
}

template <class T>
SYNKRO_INLINE TreeIterator<T>& TreeIterator<T>::operator++( Int )
{
	assert( _item != nullptr );

	_item = _item->next;
	return *this;
}

template <class T>
SYNKRO_INLINE Bool TreeIterator<T>::operator==( const TreeIterator<T>& other ) const
{
	return _item == other._item;
}

template <class T>
SYNKRO_INLINE Bool TreeIterator<T>::operator!=( const TreeIterator<T>& other ) const
{
	return _item != other._item;
}

template <class T>
SYNKRO_INLINE T& TreeIterator<T>::operator*() const
{
	assert( _item != nullptr );

	return _item->value;
}

template <class T>
SYNKRO_INLINE T& TreeIterator<T>::operator->() const
{
	assert( _item != nullptr );

	return _item->value;
}

template <class T>
SYNKRO_INLINE Bool TreeIterator<T>::IsValid() const
{
	return _item != nullptr;
}

template <class T>
SYNKRO_INLINE TreeItem<T>* TreeIterator<T>::Item() const
{
	return _item;
}
