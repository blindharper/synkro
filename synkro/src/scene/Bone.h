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
// Purpose: Bone implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_BONE_
#define _SYNKRO_SCENE_BONE_


#include "config.h"
#include <core/ObjectImpl.h>
#include <scene/IBone.h>
#include "BaseSkeleton.h"


namespace synkro
{


namespace scene
{


// Skeleton bone implementation.
class Bone :
	public core::ObjectImpl<IBone>
{
public:
	// Constructors.
	Bone( BaseSkeleton* skeleton, UInt index );
	Bone( BaseSkeleton* skeleton, const Bone* other );
	Bone();

	// IBone methods.
	void													SetTransform( const math::Matrix4x4& transform );
	void													GetTransform( math::Matrix4x4& transform ) const;
	void													GetOffset( math::Matrix4x4& offset ) const;
	IBone*													GetParent() const;
	lang::String											GetName() const;

private:
	BaseSkeleton*											_skeleton;
	UInt													_index;
};


#include "Bone.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BONE_
