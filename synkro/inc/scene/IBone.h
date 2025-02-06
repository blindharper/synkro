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
// Purpose: Defines triangle mesh bone.
//==============================================================================
#ifndef _SYNKRO_SCENE_IBONE_
#define _SYNKRO_SCENE_IBONE_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace scene
{


/**
 * Triangle mesh bone.
 */
iface IBone :
	public core::IObject
{
public:
	/**
	 * Sets bone transformation.
	 * @param transform Bone transformation.
	 */
	virtual void											SetTransform( const math::Matrix4x4& transform ) = 0;

	/**
	 * Retrieves bone transformation.
	 * @param [out] transform Variable where to store transform.
	 */
	virtual void											GetTransform( math::Matrix4x4& transform ) const = 0;

	/**
	 * Retrieves bone offset.
	 * @param [out] offset Variable where to store offset.
	 */
	virtual void											GetOffset( math::Matrix4x4& offset ) const = 0;

	/**
	 * Retrieves bone's direct parent. 
	 */
	virtual IBone*											GetParent() const = 0;

	/**
	 * Retrieves bone name.
	 */
	virtual lang::String									GetName() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IBONE_
