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
// Purpose: Color viewport filter factory.
//==============================================================================
#ifndef _SYNKRO_VIEW_COLORFILTERFACTORY_
#define _SYNKRO_VIEW_COLORFILTERFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <view/IViewportFilterFactory.h>
#include <view/ViewportFilter.h>
#include "ColorFilter.h"


namespace synkro
{


namespace view
{


// Color viewport filter factory.
SYNKRO_FACTORY_BEGIN( ColorFilterFactory, IViewportFilterFactory, ViewportFilter, ViewportFilter::Color )
	IViewportFilter*	Create( IViewport* viewport, core::IContext* context ) { return new ColorFilter( viewport, context->GetAnimationSystem(), context->GetGraphicsSystem()->GetProgram(ViewportFilter::Color.ToString()) ); }
SYNKRO_FACTORY_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_COLORFILTERFACTORY_
