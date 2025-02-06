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
// Purpose: Defines base 3D sound.
//==============================================================================
#ifndef _SYNKRO_SOUND_BASESOUND3D_
#define _SYNKRO_SOUND_BASESOUND3D_


#include "config.h"


namespace synkro
{


namespace sound
{


// Base 3D sound.
class BaseSound3D
{
public:
	virtual audio::ISoundEmitter*							GetEmitter() const = 0;
};


// Casts object to BaseSound3D.
#define AsBaseSound3D( OBJ ) dynamic_cast<BaseSound3D*>( OBJ )


} // sound


} // synkro


#endif // _SYNKRO_SOUND_BASESOUND3D_
