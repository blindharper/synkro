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
// Purpose: Defines list widget item.
//==============================================================================
#ifndef _SYNKRO_UI_LISTITEM_
#define _SYNKRO_UI_LISTITEM_


#include "config.h"
#include <lang/String.h>


namespace synkro
{


namespace ui
{


/**
 * List item.
 */
class SYNKRO_API ListItem
{
public:
	/** Creates a list item with the specified properties. */
	ListItem( const lang::String& text, Pointer data );

	/** Creates a list item with the specified text. */
	ListItem( const lang::String& text );

	/** Creates default list item. */
	ListItem();

	/** Text displayed in the item. */
	lang::String											Text;

	/** User defined data. */
	Pointer													Data;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_LISTITEM_
