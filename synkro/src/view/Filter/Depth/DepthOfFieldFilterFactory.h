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
// Purpose: Depth-of-field viewport filter factory.
//==============================================================================
#ifndef _SYNKRO_VIEW_DEPTHOFFIELDFILTERFACTORY_
#define _SYNKRO_VIEW_DEPTHOFFIELDFILTERFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <view/IViewportFilterFactory.h>
#include <view/ViewportFilter.h>
#include "DepthOfFieldFilter.h"


namespace synkro
{


namespace view
{


// Depth-of-field viewport filter factory.
SYNKRO_FACTORY_BEGIN( DepthOfFieldFilterFactory, IViewportFilterFactory, ViewportFilter, ViewportFilter::DepthOfField )
	IViewportFilter*	Create( IViewport* viewport, core::IContext* context ) { return new DepthOfFieldFilter( viewport, context->GetGraphicsSystem()->GetProgram(ViewportFilter::DepthOfField.ToString()) ); }
SYNKRO_FACTORY_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_DEPTHOFFIELDFILTERFACTORY_
