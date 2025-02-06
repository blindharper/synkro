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
// Purpose: Defines viewport filter factory.
//==============================================================================
#ifndef _SYNKRO_VIEW_IVIEWPORTFILTERFACTORY_
#define _SYNKRO_VIEW_IVIEWPORTFILTERFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace view
{


/**
 * Viewport filter factory.
 */
iface IViewportFilterFactory :
	public core::IFactory
{
public:
	/**
	 * Creates viewport filter.
	 * @param viewport Owner viewport.
	 * @param context Framework context.
	 */
	virtual IViewportFilter*								Create( IViewport* viewport, core::IContext* context ) = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IVIEWPORTFILTERFACTORY_
