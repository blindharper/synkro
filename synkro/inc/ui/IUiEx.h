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
// Purpose: Defines extended user interface.
//==============================================================================
#ifndef _SYNKRO_UI_IUIEX_
#define _SYNKRO_UI_IUIEX_


#include "config.h"
#include <ui/IUi.h>
#include <ui/ThemeName.h>


namespace synkro
{


namespace ui
{


/**
 * Extended user interface.
 */
iface IUiEx :
	public IUi
{
public:
	/** 
	 * Shows or hides user interface.
	 * @param show Set to true to show user interface, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/** 
	 * Enables/disables user interface.
	 * @param enable Set to true to enable user interface, set to false to disable it.
	 */
	virtual void											Enable( Bool enable ) = 0;

	/**
	 * Registers user interface event listener.
	 * @param listener Event listener.
	 */
	virtual void											Listen( UiListener* listener ) = 0;

	/**
	 * Applies the specified theme to all widgets.
	 * @param theme Theme to apply.
	 */
	virtual void											SetThemeName( const ThemeName& theme ) = 0;

	/**
	 * Creates user interface from a script.
	 * @param stream Stream containing UI definition.
	 */
	virtual void											Load( io::IStream* stream ) = 0;

	/**
	 * Creates label widget.
	 * @param parent Parent widget.
	 * @param id Widget identifier.
	 * @param location Label location.
	 * @param size Label size.
	 * @param text Text displayed on the label.
	 * @return Created label widget.
	 */
	virtual ILabel*											CreateLabel( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text ) = 0;

	/**
	 * Creates picture widget.
	 * @param parent Parent widget.
	 * @param id Widget identifier.
	 * @param location Picture location.
	 * @param size Picture size.
	 * @param image Picture content.
	 * @return Created picture widget.
	 */
	virtual IPicture*										CreatePicture( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, img::IImage* image ) = 0;

	/**
	 * Retrieves frame by identifier.
	 * @param id Frame identifier.
	 * @return Requested frame, if found, or nullptr if no frame exists with the given identifier.
	 */
	virtual IFrame*											GetFrame( UInt id ) const = 0;

	/**
	 * Retrieves widget by identifier.
	 * @param id Widget identifier.
	 * @return Requested widget, if found, or nullptr if no widget exists with the given identifier.
	 */
	virtual IWidget*										GetWidget( UInt id ) const = 0;

	/**
	 * Retrieves cursor pointer.
	 */
	virtual ICursor*										GetCursor() const = 0;

	/**
	 * Retrieves current theme name.
	 */
	virtual ThemeName										GetThemeName() const = 0;

	/**
	 * Retrieves user interface visibility state.
	 * @return True if user interface is visible, false otherwise.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Retrieves user interface enabled state.
	 * @return True if user interface is enabled, false otherwise.
	 */
	virtual Bool											IsEnabled() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IUIEX_
