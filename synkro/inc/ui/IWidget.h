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
// Purpose: Defines abstract user interface widget.
//==============================================================================
#ifndef _SYNKRO_UI_IWIDGET_
#define _SYNKRO_UI_IWIDGET_


#include "config.h"
#include <core/IObject.h>
#include <lang/Rect.h>
#include <ui/Anchor.h>
#include <ui/HotKey.h>
#include <ui/CursorType.h>


namespace synkro
{


namespace ui
{


/**
 * Abstract user interface widget.
 */
iface IWidget :
	public core::IObject
{
public:
	/** 
	 * Activates/deactivates widget and sets input focus to it.
	 * @param activate Set to true to activate the widget, set to false to deactivate it.
	 */
	virtual void											Activate( Bool activate ) = 0;

	/** 
	 * Enables/disables widget and all its children.
	 * @param enable Set to true to enable the widget, set to false to disable it.
	 */
	virtual void											Enable( Bool enable ) = 0;

	/** 
	 * Sets widget visibility. Affects visibility of the children widgets as well.
	 * @param show Set to true to make widget visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/** 
	 * Sets degree of widget opacity. Valid range is [0.0-1.0]. Default is 1.0.
	 * @param opacity Widget opacity.
	 */
	virtual void											SetOpacity( Float opacity ) = 0;

	/**
	 * Sets widget location.
	 * @param location Widget location.
	 */
	virtual void											SetLocation( const lang::Point& location ) = 0;

	/**
	 * Sets widget size.
	 * @param size Widget size.
	 */
	virtual void											SetSize( const lang::Size& size ) = 0;

	/**
	 * Sets widget's hot key.
	 * @param key Widget's hot key.
	 */
	virtual void											SetHotKey( const HotKey& key ) = 0;

	/**
	 * Sets widget's anchor.
	 * @param anchor Widget's anchor.
	 */
	virtual void											SetAnchor( const Anchor& anchor ) = 0;

	/**
	 * Sets widget z-order. Widgets with lower z-order are drawn over those with higher z-order.
	 * @param order New z-order value.
	 */
	virtual void											SetZOrder( UInt order ) = 0;

	/**
	 * Sets widget tab-order.
	 * @param order New tab-order value.
	 */
	virtual void											SetTabOrder( UInt order ) = 0;

	/**
	 * Sets user-defined value associated with the widget.
	 * @param data New data.
	 */
	virtual void											SetData( Pointer data ) = 0;

	/**
	 * Retrieves widget activity state.
	 * @return True if the widget is active, false otherwise.
	 */
	virtual Bool											IsActive() const = 0;

	/**
	 * Retrieves widget enabled state.
	 * @return True if the widget is enabled, false otherwise.
	 */
	virtual Bool											IsEnabled() const = 0;

	/**
	 * Retrieves widget visibility state.
	 * @return True if the widget is visible, false otherwise.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Retrieves degree of widget opacity.
	 */
	virtual Float											GetOpacity() const = 0;

	/**
	 * Retrieves widget location.
	 * @param [out] location Widget location.
	 */
	virtual void											GetLocation( lang::Point& location ) const = 0;

	/**
	 * Retrieves widget size.
	 * @param [out] size Widget size.
	 */
	virtual void											GetSize( lang::Size& size ) const = 0;

	/**
	 * Retrieves widget rectangle in screen coordinates.
	 * @param [out] rect Widget rectangle.
	 */
	virtual void											GetRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves visible part of widget rectangle in screen coordinates.
	 * @param [out] rect Widget visible rectangle.
	 */
	virtual void											GetVisibleRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves widget's hot key.
	 * @param [out] key Widget's hot key.
	 */
	virtual void											GetHotKey( HotKey& key ) const = 0;

	/**
	 * Retrieves widget's anchor.
	 */
	virtual Anchor											GetAnchor() const = 0;

	/**
	 * Retrieves widget Z-Order.
	 */
	virtual UInt											GetZOrder() const = 0;

	/**
	 * Retrieves widget tab-order.
	 */
	virtual UInt											GetTabOrder() const = 0;

	/**
	 * Retrieves user-defined value associated with the widget.
	 */
	virtual Pointer											GetData() const = 0;

	/**
	 * Retrieves cursor type associated with the widget.
	 */
	virtual CursorType										GetCursor() const = 0;

	/**
	 * Retrieves widget's parent.
	 */
	virtual IFrame*											GetParent() const = 0;

	/**
	 * Casts widget to angle.
	 * @return Non-null for angle widget, nullptr otherwise.
	 */
	virtual IAngle*											AsAngle() const = 0;

	/**
	 * Casts widget to button.
	 * @return Non-null for button widget, nullptr otherwise.
	 */
	virtual IButton*										AsButton() const = 0;

	/**
	 * Casts widget to drop list.
	 * @return Non-null for drop list widget, nullptr otherwise.
	 */
	virtual IDropList*										AsDropList() const = 0;

	/**
	 * Casts widget to edit.
	 * @return Non-null for edit widget, nullptr otherwise.
	 */
	virtual IEdit*											AsEdit() const = 0;

	/**
	 * Casts widget to label.
	 * @return Non-null for label widget, nullptr otherwise.
	 */
	virtual ILabel*											AsLabel() const = 0;

	/**
	 * Casts widget to list.
	 * @return Non-null for list widget, nullptr otherwise.
	 */
	virtual IList*											AsList() const = 0;

	/**
	 * Casts widget to option.
	 * @return Non-null for option widget, nullptr otherwise.
	 */
	virtual IOption*										AsOption() const = 0;

	/**
	 * Casts widget to picture.
	 * @return Non-null for picture widget, nullptr otherwise.
	 */
	virtual IPicture*										AsPicture() const = 0;

	/**
	 * Casts widget to progress.
	 * @return Non-null for progress widget, nullptr otherwise.
	 */
	virtual IProgress*										AsProgress() const = 0;

	/**
	 * Casts widget to slider.
	 * @return Non-null for slider widget, nullptr otherwise.
	 */
	virtual ISlider*										AsSlider() const = 0;

	/**
	 * Casts widget to switch.
	 * @return Non-null for switch widget, nullptr otherwise.
	 */
	virtual ISwitch*										AsSwitch() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IWIDGET_
