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
// Purpose: Logical sound listener.
//==============================================================================
#include "config.h"
#include "SoundListener.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


SoundListener::SoundListener( ISoundListener* listener ) :
	_listener( listener ),
	_readonly( true )
{
}

SoundListener::SoundListener( const SoundListener& other ) :
	_listener( other._listener->Clone() ),
	_readonly( false )
{
}


} // audio


} // synkro
