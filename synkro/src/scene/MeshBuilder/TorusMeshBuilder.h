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
// Purpose: Torus mesh builder.
//==============================================================================
#ifndef _SYNKRO_SCENE_TORUSMESHBUILDER_
#define _SYNKRO_SCENE_TORUSMESHBUILDER_


#include "config.h"
#include <core/ObjectImpl.h>
#include <scene/IMeshBuilder.h>
#include <scene/NormalBuilder.h>


namespace synkro
{


namespace scene
{


// Torus mesh builder.
class TorusMeshBuilder :
	public core::ObjectImpl<IMeshBuilder>,
	public NormalBuilder
{
public:
	// Constructor.
	TorusMeshBuilder();

	// IMeshBuilder methods.
	void													Build( IPointMesh* mesh, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform );
	void													Build( ILineMesh* mesh, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform );
	void													Build( ITriangleMesh* mesh, const math::Vector4& param1, const lang::Size& param2, const math::Matrix4x4& transform );
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_TORUSMESHBUILDER_
