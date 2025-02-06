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
// Purpose: Implements recorder description.
//==============================================================================
#include "config.h"
#include <audio/RecorderDesc.h>


namespace synkro
{


namespace audio
{


RecorderDesc::RecorderDesc( const lang::String& name, UInt channelCount ) :
	Name( name ),
	ChannelCount( channelCount )
{
}

RecorderDesc::RecorderDesc() :
	ChannelCount( 0 )
{
}


} // audio


} // synkro
