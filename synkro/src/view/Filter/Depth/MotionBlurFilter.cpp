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
// Purpose: Motion blur viewport filter implementation.
//==============================================================================
#include "config.h"
#include "MotionBlurFilter.h"


//------------------------------------------------------------------------------

using namespace synkro::gfx;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


MotionBlurFilter::MotionBlurFilter( IViewport* viewport, IProgram* program ) :
	DepthFilterImpl<IMotionBlurFilter>( viewport, nullptr, program )
{
	// Extract filter parameters.
	_paramPrevViewProj	= _params->GetParam( L"p_prevViewProj" );
	_paramSampleCount	= _params->GetParam( L"p_sampleCount" );

	// Set default values.
	SetSampleCount( 5 );
}


} // view


} // synkro
