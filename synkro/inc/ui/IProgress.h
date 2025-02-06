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
// Purpose: Defines progress indicator widget.
//==============================================================================
#ifndef _SYNKRO_UI_IPROGRESS_
#define _SYNKRO_UI_IPROGRESS_


#include "config.h"
#include <ui/IWidget.h>
#include <ui/ProgressType.h>


namespace synkro
{


namespace ui
{


/**
 * Progress indicator widget.
 */
iface IProgress :
	public IWidget
{
public:
	/**
	 * Sets maximum value corresponding to 100 percents.
	 * @param value The maximum allowed value.
	 */
	virtual void											SetMaxValue( UInt value ) = 0;

	/**
	 * Sets current progress value.
	 * @param value Current progress value.
	 */
	virtual void											SetValue( UInt value ) = 0;

	/**
	 * Shows or hides text over the widget.
	 * @param show Set to true to show text or false to hide it.
	 */
	virtual void											ShowText( Bool show ) = 0;

	/** 
	 * Retrieves widget type.
	 */
	virtual ProgressType									GetType() const = 0;

	/**
	 * Retrieves the maximum allowed value.
	 */
	virtual UInt											GetMaxValue() const = 0;

	/**
	 * Retrieves current progress value.
	 */
	virtual UInt											GetValue() const = 0;

	/**
	 * Indicates whether the text is visible.
	 */
	virtual Bool											IsTextVisible() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IPROGRESS_
