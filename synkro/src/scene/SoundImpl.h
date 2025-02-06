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
// Purpose: Generic sound implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_SOUNDIMPL_
#define _SYNKRO_SCENE_SOUNDIMPL_


#include "config.h"
#include "NodeImpl.h"
#include <sound/ISound3D.h>
#include <sound/BaseSound3D.h>
#include <audio/IAudioEnvironment.h>


namespace synkro
{


namespace scene
{


// Generic sound implementation.
template <class T>
class SoundImpl :
	public NodeImpl<T>
{
public:
	// Constructor & destructor.
	SoundImpl( ISceneEx* scene, core::IContext* context, const lang::String& name, sound::ISound3D* sound );
	virtual ~SoundImpl();

	// INode methods.
	ISound*													AsSound() const;

	// ISound methods.
	virtual void											Enable( Bool enable );
	virtual void											SetMinDistance( Float distance );
	virtual void											SetMaxDistance( Float distance );
	virtual Bool											IsEnabled() const;
	virtual Float											GetMinDistance() const;
	virtual Float											GetMaxDistance() const;
	virtual IConeSound*										AsCone() const;
	virtual IOmniSound*										AsOmni() const;

protected:
	P(sound::ISound3D)										_sound;
	audio::IAudioEnvironment*								_audioEnvironment;
	audio::ISoundEmitter*									_emitter;
	Bool													_enabled;
};


#include "SoundImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_SOUNDIMPL_
