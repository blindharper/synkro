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
// Purpose: Defines hash set iterator.
//==============================================================================
template <class K>
SYNKRO_INLINE SetIterator<K>::SetIterator( SetItem<K>* data, Int cap, Int index )
{
	assert( index >= 0 );
	assert( index <= cap );

	_data	= data;
	_last	= cap-1;
	_index	= index-1;
	_item	= nullptr;
	this->operator++();
}

template <class K>
SYNKRO_INLINE SetIterator<K>::SetIterator() :
	_data( nullptr ),
	_last( 0 ),
	_index( 0 ),
	_item( nullptr )
{
}

template <class K> 
SYNKRO_INLINE SetIterator<K>& SetIterator<K>::operator++()
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

template <class K> 
SYNKRO_INLINE Bool SetIterator<K>::operator==( const SetIterator<K>& other ) const
{
	return _item == other._item;
}

template <class K> 
SYNKRO_INLINE Bool SetIterator<K>::operator!=( const SetIterator<K>& other ) const
{
	return _item != other._item;
}

template <class K> 
SYNKRO_INLINE const K& SetIterator<K>::Key() const
{
	assert( _item != nullptr ); 

	return _item->key;
}
