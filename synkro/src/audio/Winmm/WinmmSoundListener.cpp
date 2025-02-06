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
// Purpose: WinMM sound listener implementation.
//==============================================================================
#include "config.h"
#include "WinmmSoundListener.h"


namespace synkro
{


namespace audio
{


WinmmSoundListener::WinmmSoundListener()
{
}

WinmmSoundListener::~WinmmSoundListener()
{
}

void WinmmSoundListener::Bind()
{
	// Do nothing.
}

ISoundListener* WinmmSoundListener::Clone() const
{
	return (ISoundListener*)this;
}


} // audio


} // synkro
