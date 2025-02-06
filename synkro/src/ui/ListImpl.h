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
#ifndef _SYNKRO_UI_LISTIMPL_
#define _SYNKRO_UI_LISTIMPL_


#include "config.h"
#include "WidgetImpl.h"
#include <ui/ListItem.h>
#include <lang/Vector.h>


namespace synkro
{


namespace ui
{


// Generic list implementation.
template <class T>
class ListImpl :
	public WidgetImpl<T>
{
public:
	// Constructors & destructors.
	ListImpl( BaseUi* ui, IFrame* parent, const lang::Point& location, const lang::Size& size );
	virtual ~ListImpl();

	// IList methods.
	virtual void											AddItem( const ListItem& item );
	virtual void											AddItem( const lang::String& text );
	virtual void											InsertItem( UInt index, const ListItem& item );
	virtual void											InsertItem( UInt index, const lang::String& text );
	virtual void											SetItemText( UInt index, const lang::String& text );
	virtual void											SetItemData( UInt index, Pointer data );
	virtual void											SelectItem( UInt index );
	virtual void											RemoveItem( UInt index );
	virtual void											Clear();
	virtual void											ClearSelection();
	virtual UInt											GetItemCount() const;
	virtual void											GetItem( UInt index, ListItem& item ) const;
	virtual lang::String									GetItemText( UInt index ) const;
	virtual Pointer											GetItemData( UInt index ) const;
	virtual UInt											FindItem( const lang::String& text, UInt index ) const;
	virtual UInt											GetSelectedItem() const;

protected:
	lang::Vector<ListItem>									_items;
	UInt													_selectedIndex;
};


#include "ListImpl.inl"


} // ui


} // synkro


#endif // _SYNKRO_UI_LISTIMPL_
