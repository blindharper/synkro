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
// Purpose: Implements player description.
//==============================================================================
#include "config.h"
#include <audio/PlayerDesc.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


PlayerDesc::PlayerDesc( const String& name, const SoundFormat& format, UInt memorySize ) :
	Name( name ),
	Format( format ),
	MemorySize( memorySize )
{
}

PlayerDesc::PlayerDesc() :
	Format( SoundFormat::Unknown ),
	MemorySize( 0 )
{
}


} // audio


} // synkro
