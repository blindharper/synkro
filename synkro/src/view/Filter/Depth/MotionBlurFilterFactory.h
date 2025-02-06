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
// Purpose: Motion blur viewport filter factory.
//==============================================================================
#ifndef _SYNKRO_VIEW_MOTIONBLURFILTERFACTORY_
#define _SYNKRO_VIEW_MOTIONBLURFILTERFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <view/IViewportFilterFactory.h>
#include "MotionBlurFilter.h"


namespace synkro
{


namespace view
{


// Motion blur viewport filter factory.
SYNKRO_FACTORY_BEGIN( MotionBlurFilterFactory, IViewportFilterFactory, ViewportFilter, ViewportFilter::MotionBlur )
	IViewportFilter*	Create( IViewport* viewport, core::IContext* context ) { return new MotionBlurFilter( viewport, context->GetGraphicsSystem()->GetProgram(ViewportFilter::MotionBlur.ToString()) ); }
SYNKRO_FACTORY_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_MOTIONBLURFILTERFACTORY_
