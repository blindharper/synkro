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
// Purpose: Defines user interface.
//==============================================================================
#ifndef _SYNKRO_UI_IUI_
#define _SYNKRO_UI_IUI_


#include "config.h"
#include <core/ISystem.h>
#include <lang/Point.h>
#include <lang/Size.h>
#include <ui/ProgressType.h>
#include <ui/Orientation.h>
#include <ui/EditStyle.h>
#include <img/Color.h>


namespace synkro
{


namespace ui
{


/**
 * Graphical user interface.
 */
iface IUi :
	public core::ISystem
{
public:
	/**
	 * Creates frame.
	 * @param parent Parent frame.
	 * @param id Frame identifier.
	 * @param location Frame location.
	 * @param size Frame size.
	 * @param showBorder Indicates whether to show frame border.
	 * @return Created frame.
	 */
	virtual IFrame*											CreateFrame( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, Bool showBorder ) = 0;

	/**
	 * Creates accordion container.
	 * @param parent Parent frame.
	 * @param id Accordion identifier.
	 * @param location Accordion location.
	 * @param size Accordion size.
	 * @return Created accordion container.
	 */
	virtual IAccordion*										CreateAccordion( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size ) = 0;

	/**
	 * Creates angle picker widget of a fixed size.
	 * @param parent Parent widget.
	 * @param id Widget identifier.
	 * @param location Widget location.
	 * @param color Custom widget color. Set to Transparent to use theme color.
	 * @return Created angle picker widget.
	 */
	virtual IAngle*											CreateAngle( IFrame* parent, UInt id, const lang::Point& location, const img::Color& color ) = 0;

	/**
	 * Creates push button widget.
	 * @param parent Parent widget.
	 * @param id Widget identifier.
	 * @param location Widget location.
	 * @param size Widget size.
	 * @param text Text displayed on the button.
	 * @param color Custom widget color. Set to Transparent to use theme color.
	 * @return Created button widget.
	 */
	virtual IButton*										CreateButton( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text, const img::Color& color ) = 0;

	/**
	 * Creates drop list widget.
	 * @param parent Parent widget.
	 * @param id Widget identifier.
	 * @param location Widget location.
	 * @param size Widget size.
	 * @param capacity Maximum number of characters the list can hold. Set to zero to apply default value.
	 * @return Created drop list widget.
	 */
	virtual IDropList*										CreateDropList( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, UInt capacity ) = 0;

	/**
	 * Creates text edit widget.
	 * @param parent Parent widget.
	 * @param id Widget identifier.
	 * @param location Widget location.
	 * @param size Widget size.
	 * @param text Text displayed on the button.
	 8 @param style Text edit style.
	 * @return Created text edit widget.
	 */
	virtual IEdit*											CreateEdit( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text, const EditStyle& style ) = 0;

	/**
	 * Creates list widget.
	 * @param parent Parent widget.
	 * @param id Widget identifier.
	 * @param location Widget location.
	 * @param size Widget size.
	 * @param capacity Maximum number of characters the list can hold. Set to zero to apply default value.
	 * @return Created list widget.
	 */
	virtual IList*											CreateList( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, UInt capacity ) = 0;

	/**
	 * Creates option widget.
	 * @param parent Parent widget.
	 * @param id Widget identifier.
	 * @param location Widget location.
	 * @param size Widget size.
	 * @param text Text displayed on the widget.
	 * @param selected Indicates whether the option is initially selected.
	 * @param color Custom widget color. Set to Transparent to use theme color.
	 * @return Created option widget.
	 */
	virtual IOption*										CreateOption( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const lang::String& text, Bool selected, const img::Color& color ) = 0;

	/**
	 * Creates progress widget.
	 * @param parent Parent widget.
	 * @param id Widget identifier.
	 * @param location Widget location.
	 * @param size Widget size.
	 * @param type Widget type.
	 * @param color Custom widget color. Set to Transparent to use theme color.
	 * @return Created progress widget.
	 */
	virtual IProgress*										CreateProgress( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const ProgressType& type, const img::Color& color ) = 0;

	/**
	 * Creates slider widget.
	 * @param parent Parent widget.
	 * @param id Widget identifier.
	 * @param location Widget location.
	 * @param size Widget size.
	 * @param orientation Slider orientation.
	 * @param minPosition The minimum allowed position.
	 * @param maxPosition The maximum allowed position.
	 * @param color Custom widget color. Set to Transparent to use theme color.
	 * @return Created slider widget.
	 */
	virtual ISlider*										CreateSlider( IFrame* parent, UInt id, const lang::Point& location, const lang::Size& size, const Orientation& orientation, UInt minPosition, UInt maxPosition, const img::Color& color ) = 0;

	/**
	 * Creates switch widget.
	 * @param parent Parent widget.
	 * @param id Widget identifier.
	 * @param location Widget location.
	 * @param width Widget width. The height is calculated based on UI font size.
	 * @param text Text displayed on the widget.
	 * @param on Indicates whether the switch is initially turned on.
	 * @param color Custom widget color. Set to Transparent to use theme color.
	 * @return Created switch widget.
	 */
	virtual ISwitch*										CreateSwitch( IFrame* parent, UInt id, const lang::Point& location, UInt width, const lang::String& text, Bool on, const img::Color& color ) = 0;

	/**
	 * Sets user interface theme.
	 * @param theme User interface theme.
	 */
	virtual void											SetTheme( ITheme* theme ) = 0;

	/**
	 * Sets background color.
	 * @param color User interface background color.
	 */
	virtual void											SetBackColor( const img::Color& color ) = 0;

	/**
	 * Retrieves user interface theme.
	 */
	virtual ITheme*											GetTheme() const = 0;

	/**
	 * Retrieves background color.
	 * @param [out] color Color value.
	 */
	virtual void											GetBackColor( img::Color& color ) const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IUI_
