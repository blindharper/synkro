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
// Purpose: Generic list widget wrapper implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE ListWrapperImpl<T>::ListWrapperImpl( BaseUiEx* ui, UInt id, IFrame* parent, IList* list ) :
	WidgetWrapperImpl<T>( ui, id, parent, list ),
	_list( list )
{
}

template <class T>
SYNKRO_INLINE ListWrapperImpl<T>::~ListWrapperImpl()
{
}

template <class T>
SYNKRO_INLINE void ListWrapperImpl<T>::AddItem( const ListItem& item )
{
	_list->AddItem( item );
}

template <class T>
SYNKRO_INLINE void ListWrapperImpl<T>::AddItem( const lang::String& text )
{
	_list->AddItem( text );
}

template <class T>
SYNKRO_INLINE void ListWrapperImpl<T>::InsertItem( UInt index, const ListItem& item )
{
	_list->InsertItem( index, item );
}

template <class T>
SYNKRO_INLINE void ListWrapperImpl<T>::InsertItem( UInt index, const lang::String& text )
{
	_list->InsertItem( index, text );
}

template <class T>
SYNKRO_INLINE void ListWrapperImpl<T>::SetItemText( UInt index, const lang::String& text )
{
	_list->SetItemText( index, text );
}

template <class T>
SYNKRO_INLINE void ListWrapperImpl<T>::SetItemData( UInt index, Pointer data )
{
	_list->SetItemData( index, data );
}

template <class T>
SYNKRO_INLINE void ListWrapperImpl<T>::SelectItem( UInt index )
{
	_list->SelectItem( index );
}

template <class T>
SYNKRO_INLINE void ListWrapperImpl<T>::RemoveItem( UInt index )
{
	_list->RemoveItem( index );
}

template <class T>
SYNKRO_INLINE void ListWrapperImpl<T>::Clear()
{
	_list->Clear();
}

template <class T>
SYNKRO_INLINE void ListWrapperImpl<T>::ClearSelection()
{
	_list->ClearSelection();
}

template <class T>
SYNKRO_INLINE UInt ListWrapperImpl<T>::GetItemCount() const
{
	return _list->GetItemCount();
}

template <class T>
SYNKRO_INLINE void ListWrapperImpl<T>::GetItem( UInt index, ListItem& item ) const
{
	_list->GetItem( index, item );
}

template <class T>
SYNKRO_INLINE lang::String ListWrapperImpl<T>::GetItemText( UInt index ) const
{
	return _list->GetItemText( index );
}

template <class T>
SYNKRO_INLINE Pointer ListWrapperImpl<T>::GetItemData( UInt index ) const
{
	return _list->GetItemData( index );
}

template <class T>
SYNKRO_INLINE UInt ListWrapperImpl<T>::FindItem( const lang::String& text, UInt index ) const
{
	return _list->FindItem( text, index );
}

template <class T>
SYNKRO_INLINE UInt ListWrapperImpl<T>::GetItemAt( const lang::Point& location ) const
{
	return _list->GetItemAt( location );
}

template <class T>
SYNKRO_INLINE UInt ListWrapperImpl<T>::GetSelectedItem() const
{
	return _list->GetSelectedItem();
}
