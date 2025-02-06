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
// Purpose: Defines accordion container.
//==============================================================================
#ifndef _SYNKRO_UI_IACCORDION_
#define _SYNKRO_UI_IACCORDION_


#include "config.h"
#include <ui/IFrame.h>
#include <lang/String.h>


namespace synkro
{


namespace ui
{


/**
 * Accordion container.
 */
iface IAccordion :
	public IFrame
{
public:
	/** 
	 * Creates a panel and adds it to the accordion.
	 * @param text Panel header text.
	 * @return Created panel.
	 */
	virtual IFrame*											CreatePanel( const lang::String& text ) = 0;

	/**
	 * Expands or collapses panel.
	 * @param index Index of the panel.
	 * @param expand True to expand panel, false to collapse it.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											ExpandPanel( UInt index, Bool expand ) = 0;

	/**
	 * Retrieves the total number of panels.
	 */
	virtual UInt											GetPanelCount() const = 0;

	/**
	 * Retrieves a panel by index.
	 * @param index Panel index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IFrame*											GetPanel( UInt index ) const = 0;

	/** 
	 * Retrieves the text of the specified panel.
	 * @param index Panel index.
	 * @exception OutOfRangeException Index is out of range.
	 * @return Panel text.
	 */
	virtual lang::String									GetPanelText( UInt index ) const = 0;

	/**
	 * Indicates if the panel is currently expanded.
	 * @param index Index of the panel to test.
	 * @exception OutOfRangeException Index is out of range.
	 * @return True for expanded panel or false otherwise.
	 */
	virtual Bool											IsPanelExpanded( UInt index ) const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IACCORDION_
