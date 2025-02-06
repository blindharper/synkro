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
// Purpose: Defines dropdown list widget.
//==============================================================================
#ifndef _SYNKRO_UI_IDROPLIST_
#define _SYNKRO_UI_IDROPLIST_


#include "config.h"
#include <ui/IList.h>


namespace synkro
{


namespace ui
{


/**
 * Dropdown list widget.
 */
iface IDropList :
	public IList
{
public:
	/** 
	 * Expands or collapses drop list.
	 * @param expand Set to true to expand list, set to false to collapse it.
	 */
	virtual void											Expand( Bool expand ) = 0;
	
	/**
	 * Sets or removes list button highlight.
	 * @param highlight Set to true to highlight button, set to false to remove highlight.
	 */
	virtual void											Highlight( Bool highlight ) = 0;

	/**
	 * Highlights the specified item.
	 * @param index Index of the item to highlight. Set to none to remove highlight.
	 */
	virtual void											HighlightItem( UInt index ) = 0;

	/**
	 * Sets the maximum number of items that are visible when the list is expanded.
	 * @param height New list height.
	 */
	virtual void											SetListHeight( UInt height ) = 0;

	/**
	 * Tests if the list is expanded.
	 */
	virtual Bool											IsExpanded() const = 0;

	/**
	 * Retrieves the index of the currently highlighted item.
	 * @return Index of the currently highlighted item, or none if no item is highlighted.
	 */
	virtual UInt											GetHighlightedItem() const = 0;

	/**
	 * Retrieves item height.
	 */
	virtual UInt											GetListHeight() const = 0;

	/**
	 * Retrieves selected text.
	 */
	virtual lang::String									GetText() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IDROPLIST_
