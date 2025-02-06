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
// Purpose: Defines angle picker widget.
//==============================================================================
#ifndef _SYNKRO_UI_IANGLE_
#define _SYNKRO_UI_IANGLE_


#include "config.h"
#include <ui/IWidget.h>


namespace synkro
{


namespace ui
{


/**
 * Angle picker widget.
 */
iface IAngle :
	public IWidget
{
public:
	/**
	 * Sets or removes angle picker highlight.
	 * @param highlight Set to true to highlight angle picker, set to false to remove highlight.
	 */
	virtual void											Highlight( Bool highlight ) = 0;

	/**
	 * Sets angle value. Valid range is [0.0, 360.0].
	 * @param value New angle value.
	 */
	virtual void											SetValue( Float value ) = 0;

	/**
	 * Retrieves angle value.
	 */
	virtual Float											GetValue() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IANGLE_
