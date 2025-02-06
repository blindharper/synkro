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
// Purpose: Defines binary tree iterator.
//==============================================================================
template <class T>
SYNKRO_INLINE BtreeIterator<T>::BtreeIterator( BtreeItem<T>* item ) :
	_item( item )
{
}

template <class T>
SYNKRO_INLINE BtreeIterator<T>::BtreeIterator() :
	_item( nullptr )
{
}

template <class T>
SYNKRO_INLINE Bool BtreeIterator<T>::IsValid() const
{
	return _item != nullptr;
}

template <class T>
SYNKRO_INLINE Bool BtreeIterator<T>::operator==( const BtreeIterator<T>& other ) const
{
	return _item == other._item;
}

template <class T>
SYNKRO_INLINE Bool BtreeIterator<T>::operator!=( const BtreeIterator<T>& other ) const
{
	return _item != other._item;
}

template <class T>
SYNKRO_INLINE T& BtreeIterator<T>::operator*() const
{
	assert( _item != nullptr );

	return _item->value;
}

template <class T>
SYNKRO_INLINE BtreeIterator<T>& BtreeIterator<T>::operator++( Int )
{
	assert( _item != nullptr );

	if ( _item->next->child != nullptr )
	{
		BtreeNode<T>* child = _item->next->child;
		while ( (child != nullptr) && (child->first->child != nullptr) )
		{
			child = child->first->child;
		}
		_item = child->first;
	}
	else
	{
		if ( _item->next != _item->owner->last )
		{
			_item = _item->next;
		}
		else
		{
			if ( _item->owner->parent != nullptr )
			{
				if ( _item->owner->parent == _item->owner->parent->owner->last )
				{
					BtreeItem<T>* parent = _item->owner->parent;
					while ( (parent != nullptr) && (parent == parent->owner->last) )
					{
						parent = parent->owner->parent;
					}
					_item = parent;
				}
				else
				{
					_item = _item->owner->parent;
				}
			}
			else
			{
				_item = nullptr;
			}
		}
	}

	return *this;
}
