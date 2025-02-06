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
// Purpose: 'sound' namespace includes.
//==============================================================================
#ifndef _SYNKRO_SOUND_
#define _SYNKRO_SOUND_


#include <sound/ISound2D.h>
#include <sound/ISound3D.h>
#include <sound/IMusic.h>
#include <sound/IMusicAnimationController.h>
#include <sound/IVoice.h>
#include <sound/ISoundCodec.h>
#include <sound/ISoundCodecFactory.h>
#include <sound/ISoundManager.h>
#include <sound/SoundCodecContext.h>


#define PtrSound2D P(synkro::sound::ISound2D)


namespace synkro
{


/**
 * The 'sound' namespace contains interfaces
 * for loading and capturing sounds and music in various formats.
 */
namespace sound
{
} // sound


} // synkro


#endif // _SYNKRO_SOUND_
