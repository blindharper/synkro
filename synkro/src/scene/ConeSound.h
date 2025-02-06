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
#ifndef _SYNKRO_SCENE_CONESOUND_
#define _SYNKRO_SCENE_CONESOUND_


#include "config.h"
#include "SoundImpl.h"
#include <scene/IConeSound.h>
#include "BaseNode.h"


namespace synkro
{


namespace scene
{


// Cone sound node implementation.
class ConeSound :
	public SoundImpl<IConeSound>,
	public BaseNode
{
public:
	// Constructor.
	ConeSound( ISceneEx* scene, core::IContext* context, const lang::String& name, sound::ISound3D* sound );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	IParentConstraint*										CreateParentConstraint( INode* parent, const math::Matrix4x4& transform );
	ILookAtConstraint*										CreateLookAtConstraint( INode* target );

	// ISound methods.
	IConeSound*												AsCone() const;

	// IConeSound methods.
	void													SetInnerAngle( Float angle );
	void													SetOuterAngle( Float angle );
	void													SetInnerVolume( Float volume );
	void													SetOuterVolume( Float volume );
	void													SetInnerReverb( Float reverb );
	void													SetOuterReverb( Float reverb );
	Float													GetInnerAngle() const;
	Float													GetOuterAngle() const;
	Float													GetInnerVolume() const;
	Float													GetOuterVolume() const;
	Float													GetInnerReverb() const;
	Float													GetOuterReverb() const;

	// BaseNode methods.
	void													Update();

private:
	P(ISoundAnimationController)							_ctrlAnimation;
};


#include "ConeSound.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_CONESOUND_
