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
// Purpose: Implements color noise animation track.
//==============================================================================
#include "config.h"
#include "NoiseColorTrack.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


NoiseColorTrack::NoiseColorTrack( const String& name ) :
	NoiseTrackImpl<INoiseColorTrack, TYPE_COLOR>( name )
{
}


} // anim


} // synkro
