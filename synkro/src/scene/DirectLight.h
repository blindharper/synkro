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
#ifndef _SYNKRO_SCENE_DIRECTLIGHT_
#define _SYNKRO_SCENE_DIRECTLIGHT_


#include "config.h"
#include "LightImpl.h"
#include <scene/IDirectLight.h>
#include "BaseNode.h"
#include "BaseLight.h"


namespace synkro
{


namespace scene
{


// Direct light node implementation.
class DirectLight :
	public LightImpl<IDirectLight>,
	public BaseNode,
	public BaseLight
{
public:
	// Constructor.
	DirectLight( ISceneEx* scene, core::IContext* context, const lang::String& name );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	IParentConstraint*										CreateParentConstraint( INode* parent, const math::Matrix4x4& transform );
	ILookAtConstraint*										CreateLookAtConstraint( INode* target );

	// ILight methods.
	IDirectLight*											AsDirect() const;

	// BaseNode methods.
	void													Update();

	// BaseLight methods.
	void													GetState( LightState& state ) const;

private:
	P(ILightAnimationController)							_ctrlAnimation;
};


#include "DirectLight.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_DIRECTLIGHT_
