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
// Purpose: Pass-through viewport filter implementation.
//==============================================================================
#ifndef _SYNKRO_VIEW_PASSFILTER_
#define _SYNKRO_VIEW_PASSFILTER_


#include "config.h"
#include <view/Filter/ViewportFilterImpl.h>
#include <view/IViewportFilter.h>


namespace synkro
{


namespace view
{


// Pass-through viewport filter implementation.
class PassFilter :
	public ViewportFilterImpl<IViewportFilter>
{
public:
	// Constructor.
	PassFilter( IViewport* viewport, gfx::IProgram* program );
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_PASSFILTER_
