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
// Purpose: Omni sound node implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_OMNISOUND_
#define _SYNKRO_SCENE_OMNISOUND_


#include "config.h"
#include "SoundImpl.h"
#include <scene/IOmniSound.h>
#include "BaseNode.h"


namespace synkro
{


namespace scene
{


// Omni sound node implementation.
class OmniSound :
	public SoundImpl<IOmniSound>,
	public BaseNode
{
public:
	// Constructor.
	OmniSound( ISceneEx* scene, core::IContext* context, const lang::String& name, sound::ISound3D* sound );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// ISound methods.
	IOmniSound*												AsOmni() const;

	// BaseNode methods.
	void													Update();

private:
	P(ISoundAnimationController)							_ctrlAnimation;
};


#include "OmniSound.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_OMNISOUND_
