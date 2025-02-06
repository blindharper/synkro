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
// Purpose: Defines light attenuation.
//==============================================================================
#ifndef _SYNKRO_SCENE_ATTENUATION_
#define _SYNKRO_SCENE_ATTENUATION_


#include "config.h"


namespace synkro
{


namespace scene
{


/**
 * Light attenuation.
 */
class SYNKRO_API Attenuation
{
public:
	/** Creates attenuation with the given attributes. */
	Attenuation( Float constant, Float linear, Float quadratic );

	/** Creates default attenuation. */
	Attenuation();

	/** Default attenuation. */
	static const Attenuation								Default;

	/** Constant attenuation. */
	Float													Constant;

	/** Linear attenuation. */
	Float													Linear;

	/** Quadratic attenuation. */
	Float													Quadratic;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ATTENUATION_
