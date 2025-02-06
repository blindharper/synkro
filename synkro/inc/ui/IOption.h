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
// Purpose: Defines option widget.
//==============================================================================
#ifndef _SYNKRO_UI_IOPTION_
#define _SYNKRO_UI_IOPTION_


#include "config.h"
#include <ui/IWidget.h>


namespace synkro
{


namespace ui
{


/**
 * Option widget.
 */
iface IOption :
	public IWidget
{
public:
	/**
	 * Selects or unselects the option.
	 * @param select True to select option, false to unselect option.
	 */
	virtual void											Select( Bool select ) = 0;

	/** 
	 * Sets or removes option highlight.
	 * @param highlight Set to true to highlight option, set to false to remove highlight.
	 */
	virtual void											Highlight( Bool highlight ) = 0;

	/**
	 * Sets the text that is displayed on the option.
	 * @param text Option text.
	 */
	virtual void											SetText( const lang::String& text ) = 0;
	
	/**
	 * Tests if the option is selected.
	 */
	virtual Bool											IsSelected() const = 0;

	/**
	 * Retrieves option text.
	 */
	virtual lang::String									GetText() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IOPTION_
