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
// Purpose: Defines light source state.
//==============================================================================
#ifndef _SYNKRO_SCENE_LIGHTSTATE_
#define _SYNKRO_SCENE_LIGHTSTATE_


#include "config.h"
#include <math/Vector4.h>


namespace synkro
{


namespace scene
{


// Light source types.
enum LightType
{
	LIGHT_TYPE_OMNI = 1,
	LIGHT_TYPE_CONE = 2,
	LIGHT_TYPE_DIRECT = 3,
};


// Light state.
class LightState
{
public:
	// Diffuse color of the light source.
	math::Vector4											Diffuse;

	// Ambient color of the light source.
	math::Vector4											Ambient;

	// Specular color of the light source.
	math::Vector4											Specular;

	// Position of the light source.
	math::Vector4											Position;

	// Direction of the light source. For spot and directional lights only.
	math::Vector4											Direction;

	// Distance beyond which the light has no effect.
	Float													Range;

	// Constant attenuation factor.
	Float													ConstAttenuation;

	// Linear attenuation factor.
	Float													LinearAttenuation;

	// Quadratic attenuation factor.
	Float													QuadraticAttenuation;

	// Decrease in illumination between theta and phi.
	Float													Falloff;

	// Inner spotlight cone angle, in radians.
	Float													Theta;
    
	// Outer spotlight cone angle, in radians.
	Float													Phi;

	// Light source type.
	Int														Type;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_LIGHTSTATE_
