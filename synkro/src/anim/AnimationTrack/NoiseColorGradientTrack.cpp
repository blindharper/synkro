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
// Purpose: Implements color gradient noise animation track.
//==============================================================================
#include "config.h"
#include "NoiseColorGradientTrack.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


NoiseColorGradientTrack::NoiseColorGradientTrack( const String& name ) :
	NoiseTrackImpl<INoiseColorGradientTrack, TYPE_COLOR_GRADIENT>( name ),
	_gradientType( GradientType::Vertical )
{
}


} // anim


} // synkro
