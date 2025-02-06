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
// Purpose: Cone light node implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_CONELIGHT_
#define _SYNKRO_SCENE_CONELIGHT_


#include "config.h"
#include "LightImpl.h"
#include <scene/IConeLight.h>
#include "BaseNode.h"
#include "BaseLight.h"
#include "DebugHelper.h"


namespace synkro
{


namespace scene
{


// Cone light node implementation.
class ConeLight :
	public LightImpl<IConeLight>,
	public BaseNode,
	public BaseLight
{
public:
	// Constructor.
	ConeLight( ISceneEx* scene, core::IContext* context, const lang::String& name );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	IParentConstraint*										CreateParentConstraint( INode* parent, const math::Matrix4x4& transform );
	ILookAtConstraint*										CreateLookAtConstraint( INode* target );

	// ILight methods.
	void													Enable( Bool enable );
	void													SetDiffuseColor( const img::Color& color );
	void													SetIntensity( Float intensity );
	IConeLight*												AsCone() const;

	// IConeLight methods.
	void													SetRange( Float range );
	void													SetAttenuation( const Attenuation& attenuation );
	void													SetInnerAngle( Float angle );
	void													SetOuterAngle( Float angle );
	void													SetFalloff( Float falloff );
	Float													GetRange() const;
	void													GetAttenuation( Attenuation& attenuation ) const;
	Float													GetInnerAngle() const;
	Float													GetOuterAngle() const;
	Float													GetFalloff() const;

	// BaseNode methods.
	void													Update();

	// BaseLight methods.
	void													GetState( LightState& state ) const;

private:
	enum
	{
		SEGMENT_COUNT = 36,
	};

	P(ILightAnimationController)							_ctrlAnimation;
	Attenuation												_attenuation;
	Float													_innerAngle;
	Float													_outerAngle;
	Float													_falloff;
	Float													_range;
	DebugHelper												_cone;

	Float													BuildCone( math::Vector3* vertices, UInt offset, Float angle, Float height );
	void													BuildIndices( UShort* indices, UInt offset, UInt start );
	void													UpdateAngles();
};


#include "ConeLight.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_CONELIGHT_
