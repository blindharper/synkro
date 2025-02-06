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
// Purpose: Generic list implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE ListImpl<T>::ListImpl( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size ) :
	WidgetImpl<T>( ui, parent, location, size ),
	_items( A(ListItem) ),
	_selectedIndex( none )
{
}

template <class T>
SYNKRO_INLINE ListImpl<T>::~ListImpl()
{
}

template <class T>
SYNKRO_INLINE void ListImpl<T>::AddItem( const ListItem& item )
{
	_items.Add( item );
}

template <class T>
SYNKRO_INLINE void ListImpl<T>::AddItem( const lang::String& text )
{
	AddItem( ListItem(text, null) );
}

template <class T>
SYNKRO_INLINE void ListImpl<T>::InsertItem( UInt index, const ListItem& item )
{
	assert( index < _items.Size() );

	_items.Insert( index, item );
}

template <class T>
SYNKRO_INLINE void ListImpl<T>::InsertItem( UInt index, const lang::String& text )
{
	assert( index < _items.Size() );

	InsertItem( index, ListItem(text, null) );
}

template <class T>
SYNKRO_INLINE void ListImpl<T>::SetItemText( UInt index, const lang::String& text )
{
	assert( index < _items.Size() );

	_items[index].Text = text;
}

template <class T>
SYNKRO_INLINE void ListImpl<T>::SetItemData( UInt index, Pointer data )
{
	assert( index < _items.Size() );

	_items[index].Data = data;
}

template <class T>
SYNKRO_INLINE void ListImpl<T>::SelectItem( UInt index )
{
	assert( index < _items.Size() );

	_selectedIndex = index;
}

template <class T>
SYNKRO_INLINE void ListImpl<T>::RemoveItem( UInt index )
{
	assert( index < _items.Size() );

	_items.Remove( index );
}

template <class T>
SYNKRO_INLINE void ListImpl<T>::Clear()
{
	_items.Clear();
	_selectedIndex = none;
}

template <class T>
SYNKRO_INLINE void ListImpl<T>::ClearSelection()
{
	_selectedIndex = none;
}

template <class T>
SYNKRO_INLINE UInt ListImpl<T>::GetItemCount() const
{
	return _items.Size();
}

template <class T>
SYNKRO_INLINE void ListImpl<T>::GetItem( UInt index, ListItem& item ) const
{
	assert( index < _items.Size() );

	item = _items[index];
}

template <class T>
SYNKRO_INLINE lang::String ListImpl<T>::GetItemText( UInt index ) const
{
	assert( index < _items.Size() );

	return _items[index].Text;
}

template <class T>
SYNKRO_INLINE Pointer ListImpl<T>::GetItemData( UInt index ) const
{
	assert( index < _items.Size() );

	return _items[index].Data;
}

template <class T>
SYNKRO_INLINE UInt ListImpl<T>::FindItem( const lang::String& text, UInt index ) const
{
	if ( _items.Size() == 0 )
	{
		return none;
	}
	if ( index == none )
	{
		index = 0;
	}
	for ( UInt i = index; i < _items.Size(); ++i )
	{
		if ( _items[i].Text.StartsWith(text, true) )
			return i;
	}
	for ( UInt i = 0; i < index; ++i )
	{
		if ( _items[i].Text.StartsWith(text, true) )
			return i;
	}
	return none;
}

template <class T>
SYNKRO_INLINE UInt ListImpl<T>::GetSelectedItem() const
{
	return _selectedIndex;
}
