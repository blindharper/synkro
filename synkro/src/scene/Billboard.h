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
// Purpose: Billboard node implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_BILLBOARD_
#define _SYNKRO_SCENE_BILLBOARD_


#include "config.h"
#include "NodeImpl.h"
#include <scene/IBillboard.h>
#include "BaseBillboard.h"
#include <gfx/ISceneRenderObject.h>
#include <gfx/IBlendStateSet.h>
#include <gfx/IDepthStencilState.h>
#include <gfx/IRasterizerState.h>


namespace synkro
{


namespace scene
{


// Billboard node implementation.
class Billboard :
	public NodeImpl<IBillboard>,
	public BaseBillboard
{
public:
	// Constructors.
	Billboard( ISceneEx* scene, core::IContext* context, const lang::String& name, img::IImage* image, Float width, Float height );
	Billboard( const Billboard& other );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimationSet* animations, anim::AnimationListener* listener );
	void													SetTransform( const math::Matrix4x4& transform );
	void													SetOrientation( const math::Quaternion& orientation );
	void													SetOrientationYaw( Float yaw );
	void													SetOrientationPitch( Float pitch );
	void													SetOrientationRoll( Float roll );
	IBillboard*												AsBillboard() const;

	// IBillboard methods.
	void													Show( Bool show );
	Bool													IsVisible() const;

	// BaseBillboard methods.
	void													Update( view::IViewport* viewport );

private:
	P(INodeAnimationController)								_ctrlAnimation;
	P(gfx::ISceneRenderObject)								_billboard;
	P(gfx::IBlendStateSet)									_blendStates;
	P(gfx::IDepthStencilState)								_depthStencilState;
	P(gfx::IRasterizerState)								_rasterizerState;
	lang::String											_paramName;

	void													ThrowError();
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BILLBOARD_
