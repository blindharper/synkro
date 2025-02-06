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
// Purpose: Depth viewport filter implementation.
//==============================================================================
#include "config.h"
#include "DepthFilter.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


DepthFilter::DepthFilter( IViewport* viewport, IProgram* program ) :
	DepthFilterImpl<IDepthFilter>( viewport, nullptr, program )
{
	// Extract filter parameters.
	_paramFront	= _params->GetParam( L"p_front" );
	_paramBack	= _params->GetParam( L"p_back" );

	// Set default values.
	_params->Set( _paramFront, 0.001f );
	_params->Set( _paramBack, 1000.0f );
}


} // view


} // synkro
