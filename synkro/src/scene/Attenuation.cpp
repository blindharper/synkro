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
#include "config.h"
#include <scene/Attenuation.h>


namespace synkro
{


namespace scene
{


const Attenuation Attenuation::Default( 1.0f, 0.0f, 0.0f );


Attenuation::Attenuation( Float constant, Float linear, Float quadratic ) :
	Constant( constant ),
	Linear( linear ),
	Quadratic( quadratic )
{
}

Attenuation::Attenuation() :
	Constant( 1.0f ),
	Linear( 0.0f ),
	Quadratic( 0.0f )
{
}


} // scene


} // synkro
