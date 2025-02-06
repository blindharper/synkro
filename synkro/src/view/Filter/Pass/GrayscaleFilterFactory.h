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
// Purpose: Grayscale viewport filter factory.
//==============================================================================
#ifndef _SYNKRO_VIEW_GRAYSCALEFILTERFACTORY_
#define _SYNKRO_VIEW_GRAYSCALEFILTERFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <view/IViewportFilterFactory.h>
#include "PassFilter.h"


namespace synkro
{


namespace view
{


// Grayscale viewport filter factory.
SYNKRO_FACTORY_BEGIN( GrayscaleFilterFactory, IViewportFilterFactory, ViewportFilter, ViewportFilter::Grayscale )
	IViewportFilter*	Create( IViewport* viewport, core::IContext* context ) { return new PassFilter( viewport, context->GetGraphicsSystem()->GetProgram(ViewportFilter::Grayscale.ToString()) ); }
SYNKRO_FACTORY_END()


} // view


} // synkro


#endif // _SYNKRO_VIEW_GRAYSCALEFILTERFACTORY_
