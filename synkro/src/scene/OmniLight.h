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
// Purpose: Omni light node implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_OMNILIGHT_
#define _SYNKRO_SCENE_OMNILIGHT_


#include "config.h"
#include "LightImpl.h"
#include <scene/IOmniLight.h>
#include "BaseNode.h"
#include "BaseLight.h"
#include "DebugHelper.h"


namespace synkro
{


namespace scene
{


// Omni light node implementation.
class OmniLight :
	public LightImpl<IOmniLight>,
	public BaseNode,
	public BaseLight
{
public:
	// Constructor.
	OmniLight( ISceneEx* scene, core::IContext* context, const lang::String& name );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// ILight methods.
	void													Enable( Bool enable );
	void													SetDiffuseColor( const img::Color& color );
	void													SetIntensity( Float intensity );
	IOmniLight*												AsOmni() const;

	// IOmniLight methods.
	void													SetRange( Float range );
	void													SetAttenuation( const Attenuation& attenuation );
	Float													GetRange() const;
	void													GetAttenuation( Attenuation& attenuation ) const;

	// BaseNode methods.
	void													Update();

	// BaseLight methods.
	void													GetState( LightState& state ) const;

private:
	P(ILightAnimationController)							_ctrlAnimation;
	Attenuation												_attenuation;
	Float													_range;
	DebugHelper												_omni;
};


#include "OmniLight.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_OMNILIGHT_
