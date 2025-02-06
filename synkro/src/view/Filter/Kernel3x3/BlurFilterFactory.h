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
// Purpose: Blur viewport filter factory.
//==============================================================================
#ifndef _SYNKRO_VIEW_BLURFILTERFACTORY_
#define _SYNKRO_VIEW_BLURFILTERFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <view/IViewportFilterFactory.h>
#include <view/ViewportFilter.h>
#include "Kernel3x3Filter.h"


namespace synkro
{


namespace view
{


// Blur viewport filter factory.
SYNKRO_FACTORY_BEGIN( BlurFilterFactory, IViewportFilterFactory, ViewportFilter, ViewportFilter::Blur )
	IViewportFilter*	Create( IViewport* viewport, core::IContext* context ) { return new Kernel3x3Filter( viewport, context->GetAnimationSystem(), context->GetGraphicsSystem()->GetProgram(ViewportFilter::Blur.ToString()) ); }
SYNKRO_FACTORY_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_BLURFILTERFACTORY_
