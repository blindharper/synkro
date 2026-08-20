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
// Purpose: Camera viewport filter implementation.
//==============================================================================
#include "config.h"
#include "CameraFilter.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


CameraFilter::CameraFilter( IViewport* viewport, IProgram* program ) :
	ViewportFilterImpl<ICameraFilter>( viewport, nullptr, program )
{
	// Extract filter parameters.
	_paramFront	= _params->GetParam( L"p_front" );
	_paramBack	= _params->GetParam( L"p_back" );
}


} // view


} // synkro
