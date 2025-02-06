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
// Purpose: Defines hash map iterator.
//==============================================================================
template <class K, class T>
SYNKRO_INLINE MapIterator<K,T>::MapIterator( MapPair<K,T>* data, Int cap, Int index )
{
	assert( index >= 0 );
	assert( index <= cap );

	_data	= data;
	_last	= cap-1;
	_index	= index-1;
	_item	= nullptr;
	this->operator++();
}

template <class K, class T>
SYNKRO_INLINE MapIterator<K,T>::MapIterator() :
	_data( nullptr ),
	_last( 0 ),
	_index( 0 ),
	_item( nullptr )
{
}

template <class K, class T> 
SYNKRO_INLINE MapIterator<K,T>& MapIterator<K,T>::operator++()
{
	do
	{
		if ( _item != nullptr )
		{
			_item = _item->next;
		}

		if ( (_item == nullptr) && (_index < _last) )
		{
			_item = &_data[ ++_index ];
		}

	} while ( (_item != nullptr) && !_item->used );

	return *this;
}

template <class K, class T> 
SYNKRO_INLINE Bool MapIterator<K,T>::operator==( const MapIterator<K,T>& other ) const
{
	return _item == other._item;
}

template <class K, class T> 
SYNKRO_INLINE Bool MapIterator<K,T>::operator!=( const MapIterator<K,T>& other ) const
{
	return _item != other._item;
}

template <class K, class T> 
SYNKRO_INLINE const K& MapIterator<K,T>::Key() const
{
	assert( _item != nullptr ); 

	return _item->key;
}

template <class K, class T> 
SYNKRO_INLINE T& MapIterator<K,T>::Value() const
{
	assert( _item != nullptr ); 

	return _item->value;
}
