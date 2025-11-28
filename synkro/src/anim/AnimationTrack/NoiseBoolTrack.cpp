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
// Purpose: Implements boolean noise animation track.
//==============================================================================
#include "config.h"
#include "NoiseBoolTrack.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


NoiseBoolTrack::NoiseBoolTrack( const String& name ) :
	NoiseTrackImpl<INoiseBoolTrack, TYPE_BOOL>( name )
{
}


} // anim


} // synkro
