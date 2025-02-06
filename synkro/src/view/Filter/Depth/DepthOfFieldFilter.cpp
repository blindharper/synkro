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
// Purpose: Depth-of-field viewport filter implementation.
//==============================================================================
#include "config.h"
#include "DepthOfFieldFilter.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


DepthOfFieldFilter::DepthOfFieldFilter( IViewport* viewport, IProgram* program ) :
	DepthFilterImpl<IDepthOfFieldFilter>( viewport, nullptr, program ),
	_focalPlane( 0.0f, 0.0f, 1.0f, -2.5f )
{
	// Extract parameters.
	_paramFocalPlane = _params->GetParam( L"p_focalPlane" );

	// Set default values.
	SetFocalDistance( -2.5f );
}


} // view


} // synkro
