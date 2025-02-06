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
// Purpose: Direct light node implementation.
//==============================================================================
#include "config.h"
#include "DirectLight.h"
#include "LightAnimationController.h"
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

//------------------------------------------------------------------------------


DirectLight::DirectLight( ISceneEx* scene, IContext* context, const String& name ) :
	LightImpl<IDirectLight>( scene, context, AsBaseScene(scene)->GetLightName(name) )
{
}

INodeAnimationController* DirectLight::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new LightAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

IParentConstraint* DirectLight::CreateParentConstraint( INode* parent, const Matrix4x4& transform )
{
	return (_parentConstraint == nullptr) ? _parentConstraint = new ParentConstraint( this, parent, transform ) : _parentConstraint;
}

ILookAtConstraint* DirectLight::CreateLookAtConstraint( INode* target )
{
	return (_lookAtConstraint == nullptr) ? _lookAtConstraint = new LookAtConstraint( _context->GetGraphicsSystem(), this, target ) : _lookAtConstraint;
}

void DirectLight::Update()
{
	NodeImpl<IDirectLight>::ApplyConstraints( _ctrlAnimation );
}

void DirectLight::GetState( LightState& state ) const
{
	Matrix4x4 trans;
	GetWorldTransform( trans );
	Vector4 rot( trans.Forward() );
	state.Type		= LIGHT_TYPE_DIRECT;
	state.Diffuse	= ToVector( _diffuseColor*_intensity );
	state.Ambient	= ToVector( _ambientColor*_intensity );
	state.Specular	= ToVector( _specularColor*_intensity );
	state.Direction = rot.Normalize();
}


} // scene


} // synkro
