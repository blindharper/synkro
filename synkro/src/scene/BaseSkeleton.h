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
// Purpose: Defines base skeleton.
//==============================================================================
#ifndef _SYNKRO_SCENE_BASESKELETON_
#define _SYNKRO_SCENE_BASESKELETON_


#include "config.h"
#include <math/Matrix4x4.h>


namespace synkro
{


namespace scene
{


// Base skeleton.
class BaseSkeleton
{
public:
	virtual void											SetBoneTransform( UInt index, const math::Matrix4x4& transform ) = 0;
	virtual void											GetBoneTransform( UInt index, math::Matrix4x4& transform ) const = 0;
	virtual void											GetBoneOffset( UInt index, math::Matrix4x4& offset ) const = 0;
	virtual IBone*											GetBoneParent( UInt index ) const = 0;
	virtual lang::String									GetBoneName( UInt index ) const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BASESKELETON_
