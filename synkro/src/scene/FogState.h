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
// Purpose: Defines fog state.
//==============================================================================
#ifndef _SYNKRO_SCENE_FOGSTATE_
#define _SYNKRO_SCENE_FOGSTATE_


#include "config.h"
#include <math/Vector4.h>


namespace synkro
{


namespace scene
{


// Fog state.
class FogState
{
public:
	// Fog color.
	math::Vector4											FogColor;

	// Start fog distance. Only meaningful for linear fog.
	Float													Start;

	// End fog distance. Only meaningful for linear fog.
	Float													End;

	// Fog density. Ranges is between [0,1]. Only meaningful for exp or exp^2 fog.
	Float													Density;

	// Fog type.
	Int														Type;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_FOGSTATE_
