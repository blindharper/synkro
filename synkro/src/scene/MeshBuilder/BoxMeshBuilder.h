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
// Purpose: Box mesh builder.
//==============================================================================
#ifndef _SYNKRO_SCENE_BOXMESHBUILDER_
#define _SYNKRO_SCENE_BOXMESHBUILDER_


#include "config.h"
#include <core/ObjectImpl.h>
#include <scene/IMeshBuilder.h>
#include <math/Vector2.h>
#include <lang/Vector.h>


namespace synkro
{


namespace scene
{


// Box mesh builder.
class BoxMeshBuilder :
	public core::ObjectImpl<IMeshBuilder>
{
public:
	// Constructor.
	BoxMeshBuilder();

	// IMeshBuilder methods.
	void													Build( IPointMesh* mesh, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform );
	void													Build( ILineMesh* mesh, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform );
	void													Build( ITriangleMesh* mesh, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform );

private:
	lang::Vector<math::Vector3>								_positions;
	lang::Vector<math::Vector3>								_normals;
	lang::Vector<math::Vector2>								_coordinates;
	lang::Vector<UInt>										_indices;
	math::Vector4											_param1;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_BOXMESHBUILDER_
