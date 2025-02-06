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
// Purpose: Defines picture widget.
//==============================================================================
#ifndef _SYNKRO_UI_IPICTURE_
#define _SYNKRO_UI_IPICTURE_


#include "config.h"
#include <ui/IWidget.h>


namespace synkro
{


namespace ui
{


/**
 * Picture widget. Displays a single static image.
 */
iface IPicture :
	public IWidget
{
public:
	/**
	 * Retrieves picture content.
	 */
	virtual img::IImage*									GetImage() const = 0;
};


} // ui


} // synkro


#endif // _SYNKRO_UI_IPICTURE_
