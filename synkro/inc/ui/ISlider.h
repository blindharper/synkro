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
// Purpose: Defines slider widget.
//==============================================================================
#ifndef _SYNKRO_UI_ISLIDER_
#define _SYNKRO_UI_ISLIDER_


#include "config.h"
#include <ui/IWidget.h>
#include <ui/Orientation.h>


namespace synkro
{


namespace ui
{


/**
 * Slider widget.
 */
iface ISlider :
	public IWidget
{
public:
	/**
	 * Sets or removes slider highlight.
	 * @param highlight Set to true to highlight slider, set to false to remove highlight.
	 */
	virtual void											Highlight( Bool highlight ) = 0;

	/**
	 * Sets minimum slider position.
	 * @param minPosition The minimum allowed slider position.
	 */
	virtual void											SetMinPosition( UInt minPosition ) = 0;

	/**
	 * Sets maximum slider position.
	 * @param maxPosition The maximum allowed slider position.
	 */
	virtual void											SetMaxPosition( UInt maxPosition ) = 0;

	/**
	 * Sets slider position.
	 * @param position New slider position.
	 */
	virtual void											SetPosition( UInt position ) = 0;

	/**
	 * Retrieves slider orientation.
	 */
	virtual Orientation										GetOrientation() const = 0;

	/**
	 * Retrieves the minimum allowed slider position.
	 */
	virtual UInt											GetMinPosition() const = 0;

	/**
	 * Retrieves the maximum allowed slider position.
	 */
	virtual UInt											GetMaxPosition() const = 0;

	/**
	 * Retrieves current slider position.
	 */
	virtual UInt											GetPosition() const = 0;

	/**
	 * Retrieves slider thumb size.
	 * @param [out] size Thumb size.
	 */
	virtual void											GetThumbSize( lang::Size& size ) const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_ISLIDER_
