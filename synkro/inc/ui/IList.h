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
// Purpose: Defines list widget.
//==============================================================================
#ifndef _SYNKRO_UI_ILIST_
#define _SYNKRO_UI_ILIST_


#include "config.h"
#include <ui/IWidget.h>
#include <ui/ListItem.h>


namespace synkro
{


namespace ui
{


/**
 * List widget.
 */
iface IList :
	public IWidget
{
public:
	/** 
	 * Adds an item to the end of the list.
	 * @param item Item to add.
	 */
	virtual void											AddItem( const ListItem& item ) = 0;

	/** 
	 * Adds an item to the end of the list.
	 * @param text Text to display at the item's rectangle.
	 */
	virtual void											AddItem( const lang::String& text ) = 0;

	/** 
	 * Adds an item to the given position in the list.
	 * @param index Position at which to insert the item.
	 * @param item Item to insert.
	 */
	virtual void											InsertItem( UInt index, const ListItem& item ) = 0;

	/** 
	 * Adds an item to the given position in the list.
	 * @param index Position at which to insert the item.
	 * @param text Text to display at the item's rectangle.
	 */
	virtual void											InsertItem( UInt index, const lang::String& text ) = 0;

	/** 
	 * Sets the text for the specified item.
	 * @param index Index of the item for which to set text.
	 * @param text New item text.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											SetItemText( UInt index, const lang::String& text ) = 0;

	/** 
	 * Sets user-defined data for the specified item.
	 * @param index Index of the item for which to set data.
	 * @param data New item data.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											SetItemData( UInt index, Pointer data ) = 0;

	/**
	 * Selects the specified item.
	 * @param index Index of the item to select. Set to none to remove selection.
	 */
	virtual void											SelectItem( UInt index ) = 0;

	/**
	 * Removes an item from the list.
	 * @param index Index of the item to remove.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											RemoveItem( UInt index ) = 0;

	/**
	 * Removes all the items from the list.
	 */
	virtual void											Clear() = 0;

	/**
	 * Removes selection from the list.
	 */
	virtual void											ClearSelection() = 0;

	/**
	 * Retrieves the total number of items in the list.
	 */
	virtual UInt											GetItemCount() const = 0;

	/** 
	 * Retrieves an item by index.
	 * @param index Index of the item to retrieve.
	 * @param [out] item Requested item.
	 */
	virtual void											GetItem( UInt index, ListItem& item ) const = 0;

	/**
	 * Retrieves item text by index.
	 * @param index Index of the item which text to retrieve.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual lang::String									GetItemText( UInt index ) const = 0;

	/**
	 * Retrieves item data by index.
	 * @param index Index of the item which data to retrieve.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual Pointer											GetItemData( UInt index ) const = 0;

	/**
	 * Retrieves the index of the item whose text starts with the specified text.
	 * @param text Text to search for.
	 * @param index Index at which to start searching.
	 * @return Index of the item, if found, or none otherwise.
	 */
	virtual UInt											FindItem( const lang::String& text, UInt index ) const = 0;

	/**
	 * Retrieves the index of the item which is located at given point.
	 * @param location Location in screen coordinates.
	 * @return Index of the item, if there is an item at given location, or none otherwise.
	 */
	virtual UInt											GetItemAt( const lang::Point& location ) const = 0;

	/**
	 * Retrieves the index of the currently selected item.
	 * @return Index of the currently selected item, or none if no item is selected.
	 */
	virtual UInt											GetSelectedItem() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_ILIST_
