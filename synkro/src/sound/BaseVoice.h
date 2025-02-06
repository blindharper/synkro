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
// Purpose: Defines base voice.
//==============================================================================
#ifndef _SYNKRO_SOUND_BASEVOICE_
#define _SYNKRO_SOUND_BASEVOICE_


#include "config.h"


namespace synkro
{


namespace sound
{


// Base voice.
class BaseVoice
{
public:
	virtual void											Update() = 0;
};


// Casts object to BaseVoice.
#define AsBaseVoice( OBJ ) dynamic_cast<BaseVoice*>( OBJ )


} // sound


} // synkro


#endif // _SYNKRO_SOUND_BASEVOICE_
