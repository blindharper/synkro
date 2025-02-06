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
// Purpose: Defines abstract mesh builder.
//==============================================================================
#ifndef _SYNKRO_SCENE_IMESHBUILDER_
#define _SYNKRO_SCENE_IMESHBUILDER_


#include "config.h"
#include <core/IObject.h>
#include <lang/Size.h>
#include <math/Vector4.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace scene
{


/**
 * Abstract mesh builder.
 */
iface IMeshBuilder :
	public core::IObject
{
public:
	/**
	 * Builds point mesh geometry according to the given parameters.
	 * @param mesh Mesh to fill with geometry.
	 * @param param1 Set of floating-point parameters.
	 * @param param2 Set of integer parameters.
	 * @param transform Geometry transformation.
	 */
	virtual void											Build( IPointMesh* mesh, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform ) = 0;

	/**
	 * Builds line mesh geometry according to the given parameters.
	 * @param mesh Mesh to fill with geometry.
	 * @param param1 Set of floating-point parameters.
	 * @param param2 Set of integer parameters.
	 * @param transform Geometry transformation.
	 */
	virtual void											Build( ILineMesh* mesh, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform ) = 0;

	/**
	 * Builds triangle mesh geometry according to the given parameters.
	 * @param mesh Mesh to fill with geometry.
	 * @param param1 Set of floating-point parameters.
	 * @param param2 Set of integer parameters.
	 * @param transform Geometry transformation.
	 */
	virtual void											Build( ITriangleMesh* mesh, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IMESHBUILDER_
