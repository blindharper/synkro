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
// Purpose: Base sound manager.
//==============================================================================
#ifndef _SYNKRO_SOUND_BASESOUNDMANAGER_
#define _SYNKRO_SOUND_BASESOUNDMANAGER_


#include "config.h"
#include "BaseMusic.h"
#include "BaseVoice.h"


namespace synkro
{


namespace sound
{


// Base sound manager.
class BaseSoundManager
{
public:
	virtual void											AddMusic( BaseMusic* music ) = 0;
	virtual void											AddVoice( BaseVoice* voice ) = 0;
	virtual void											RemoveMusic( BaseMusic* music ) = 0;
	virtual void											RemoveVoice( BaseVoice* voice ) = 0;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_BASESOUNDMANAGER_
