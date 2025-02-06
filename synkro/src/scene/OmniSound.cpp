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
#include "config.h"
#include "OmniSound.h"
#include "SoundAnimationController.h"


namespace synkro
{


namespace scene
{


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;
using namespace synkro::sound;

//------------------------------------------------------------------------------


OmniSound::OmniSound( ISceneEx* scene, IContext* context, const String& name, ISound3D* sound ) :
	SoundImpl<IOmniSound>( scene, context, name, sound )
{
	_sound->SetInnerAngle( Math::TwoPi );
	_sound->SetOuterAngle( Math::TwoPi );
}

INodeAnimationController* OmniSound::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new SoundAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

void OmniSound::Update()
{
	NodeImpl<IOmniSound>::ApplyConstraints( _ctrlAnimation );
}


} // scene


} // synkro
