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
// Purpose: Normal builder helper.
//==============================================================================
#ifndef _SYNKRO_SCENE_NORMALBUILDER_
#define _SYNKRO_SCENE_NORMALBUILDER_


#include "config.h"
#include <math/Vector3.h>


namespace synkro
{


namespace scene
{


// Normal builder helper.
class NormalBuilder
{
public:
	template <class I> void									GenerateNormals( const I* indices, UInt indexCount, const math::Vector3* vertices, math::Vector3* normals, Bool smooth );
};


#include "NormalBuilder.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_NORMALBUILDER_
