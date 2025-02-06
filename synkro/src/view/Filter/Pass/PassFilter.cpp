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
#include "config.h"
#include "PassFilter.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


PassFilter::PassFilter( IViewport* viewport, IProgram* program ) :
	ViewportFilterImpl<IViewportFilter>( viewport, nullptr, program )
{
}


} // view


} // synkro
