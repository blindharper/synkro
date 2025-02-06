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
// Purpose: Defines frame container.
//==============================================================================
#ifndef _SYNKRO_UI_IFRAME_
#define _SYNKRO_UI_IFRAME_


#include "config.h"
#include <core/IObject.h>
#include <lang/Point.h>
#include <lang/Size.h>
#include <lang/Rect.h>
#include <ui/Anchor.h>


namespace synkro
{


namespace ui
{


/**
 * Container for other widgets.
 */
iface IFrame :
	public core::IObject
{
public:
	/** 
	 * Sets frames visibility.
	 * @param show Set to true to make frame visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/** 
	 * Sets frame border visibility.
	 * @param show Set to true to make border visible, set to false to hide it.
	 */
	virtual void											ShowBorder( Bool show ) = 0;

	/**
	 * Sets frame location.
	 * @param location Frame location.
	 */
	virtual void											SetLocation( const lang::Point& location ) = 0;

	/**
	 * Sets frame size.
	 * @param size Frame size.
	 */
	virtual void											SetSize( const lang::Size& size ) = 0;

	/**
	 * Sets frame anchor.
	 * @param anchor Frame anchor.
	 */
	virtual void											SetAnchor( const Anchor& anchor ) = 0;

	/**
	 * Retrieves the total number of child widgets.
	 */
	virtual UInt											GetWidgetCount() const = 0;

	/**
	 * Retrieves a child widget by index.
	 * @param index Widget index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IWidget*										GetWidget( UInt index ) const = 0;

	/**
	 * Retrieves the total number of child frames.
	 */
	virtual UInt											GetFrameCount() const = 0;

	/**
	 * Retrieves a child frame by index.
	 * @param index Frame index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IFrame*											GetFrame( UInt index ) const = 0;

	/**
	 * Retrieves frame location.
	 * @param [out] location Frame location.
	 */
	virtual void											GetLocation( lang::Point& location ) const = 0;

	/**
	 * Retrieves frame size.
	 * @param [out] size Frame size.
	 */
	virtual void											GetSize( lang::Size& size ) const = 0;

	/**
	 * Retrieves frame rectangle in screen coordinates.
	 * @param [out] rect Frame rectangle.
	 */
	virtual void											GetRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves visible part of frame rectangle in screen coordinates.
	 * @param [out] rect Frame visible rectangle.
	 */
	virtual void											GetVisibleRect( lang::Rect& rect ) const = 0;

	/**
	 * Retrieves frame anchor.
	 */
	virtual Anchor											GetAnchor() const = 0;

	/**
	 * Retrieves frame parent.
	 */
	virtual IFrame*											GetParent() const = 0;

	/**
	 * Retrieves frame visibility state.
	 * @return True if the frame is visible, false otherwise.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Retrieves frame border visibility state.
	 * @return True if the border is visible, false otherwise.
	 */
	virtual Bool											IsBorderVisible() const = 0;

	/**
	 * Casts frame to accordion container.
	 * @return Non-null for accordion, nullptr otherwise.
	 */
	virtual IAccordion*										AsAccordion() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IFRAME_
