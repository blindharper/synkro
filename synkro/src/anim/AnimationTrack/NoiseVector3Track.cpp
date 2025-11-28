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
// Purpose: Implements 3-component vector noise animation track.
//==============================================================================
#include "config.h"
#include "NoiseVector3Track.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace anim
{


NoiseVector3Track::NoiseVector3Track( const String& name ) :
	NoiseTrackImpl<INoiseVector3Track, TYPE_VECTOR3>( name ),
	_magnitude( 1.0f ),
	_shift( Vector3::Origin )
{
}


} // anim


} // synkro
