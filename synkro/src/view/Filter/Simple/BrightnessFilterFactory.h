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
// Purpose: Brightness viewport filter factory.
//==============================================================================
#ifndef _SYNKRO_VIEW_BRIGHTNESSFILTERFACTORY_
#define _SYNKRO_VIEW_BRIGHTNESSFILTERFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <view/IViewportFilterFactory.h>
#include <view/ViewportFilter.h>
#include "SimpleFilter.h"


namespace synkro
{


namespace view
{


// Brightness viewport filter factory.
SYNKRO_FACTORY_BEGIN( BrightnessFilterFactory, IViewportFilterFactory, ViewportFilter, ViewportFilter::Brightness )
	IViewportFilter*	Create( IViewport* viewport, core::IContext* context ) { return new SimpleFilter( viewport, context->GetAnimationSystem(), context->GetGraphicsSystem()->GetProgram(ViewportFilter::Brightness.ToString()) ); }
SYNKRO_FACTORY_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_BRIGHTNESSFILTERFACTORY_
