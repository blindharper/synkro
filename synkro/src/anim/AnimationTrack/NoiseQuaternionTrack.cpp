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
// Purpose: Implements quaternion noise animation track.
//==============================================================================
#include "config.h"
#include "NoiseQuaternionTrack.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


NoiseQuaternionTrack::NoiseQuaternionTrack( const String& name ) :
	NoiseTrackImpl<INoiseQuaternionTrack, TYPE_QUATERNION>( name ),
	_magnitude( 1.0f )
{
}


} // anim


} // synkro
