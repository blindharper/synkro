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
// Purpose: Cone sound node implementation.
//==============================================================================
#include "config.h"
#include "ConeSound.h"
#include "SoundAnimationController.h"
#include "ParentConstraint.h"
#include "LookAtConstraint.h"


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


ConeSound::ConeSound( ISceneEx* scene, IContext* context, const String& name, ISound3D* sound ) :
	SoundImpl<IConeSound>( scene, context, name, sound )
{
}

INodeAnimationController* ConeSound::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new SoundAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

IParentConstraint* ConeSound::CreateParentConstraint( INode* parent, const Matrix4x4& transform )
{
	return (_parentConstraint == nullptr) ? _parentConstraint = new ParentConstraint( this, parent, transform ) : _parentConstraint;
}

ILookAtConstraint* ConeSound::CreateLookAtConstraint( INode* target )
{
	return (_lookAtConstraint == nullptr) ? _lookAtConstraint = new LookAtConstraint( _context->GetGraphicsSystem(), this, target ) : _lookAtConstraint;
}

void ConeSound::Update()
{
	NodeImpl<IConeSound>::ApplyConstraints( _ctrlAnimation );
}


} // scene


} // synkro
