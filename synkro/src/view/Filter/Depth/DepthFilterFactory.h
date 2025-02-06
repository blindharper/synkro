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
// Purpose: Depth buffer viewport filter factory.
//==============================================================================
#ifndef _SYNKRO_VIEW_DEPTHFILTERFACTORY_
#define _SYNKRO_VIEW_DEPTHFILTERFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <view/IViewportFilterFactory.h>
#include <view/ViewportFilter.h>
#include "DepthFilter.h"


namespace synkro
{


namespace view
{


// Depth buffer viewport filter factory.
SYNKRO_FACTORY_BEGIN( DepthFilterFactory, IViewportFilterFactory, ViewportFilter, ViewportFilter::Depth )
	IViewportFilter*	Create( IViewport* viewport, core::IContext* context ) { return new DepthFilter( viewport, context->GetGraphicsSystem()->GetProgram(ViewportFilter::Depth.ToString()) ); }
SYNKRO_FACTORY_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_DEPTHFILTERFACTORY_
