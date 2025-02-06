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
// Purpose: Defines mesh builder types.
//==============================================================================
#ifndef _SYNKRO_SCENE_MESHBUILDER_
#define _SYNKRO_SCENE_MESHBUILDER_


#include "config.h"
#include <lang/Enum.h>


namespace synkro
{


namespace scene
{


/**
 * Mesh builder types.
 */
SYNKRO_ENUM_BEGIN( MeshBuilder )
	/**
	 * Custom mesh.
	 */
	SYNKRO_ENUM_CONST( MeshBuilder, Custom )

	/**
	 * Box mesh.
	 *
	 * Parameters:
	 * param1.x: width.
	 * param1.y: depth.
	 * param1.z: height.
	 */
	SYNKRO_ENUM_CONST( MeshBuilder, Box )

	/**
	 * Cone mesh.
	 *
	 * Parameters:
	 * param1.x: radius.
	 * param1.y: height.
	 *
	 * param2.Width: stackCount.
	 * param2.Height: sliceCount.
	 */
	SYNKRO_ENUM_CONST( MeshBuilder, Cone )

	/**
	 * Cylinder mesh.
	 *
	 * Parameters:
	 * param1.x: radius.
	 * param1.y: height.
	 *
	 * param2.Width: stackCount.
	 * param2.Height: sliceCount.
	 */
	SYNKRO_ENUM_CONST( MeshBuilder, Cylinder )

	/**
	 * Ellipsoid mesh.
	 *
	 * Parameters:
	 * param1.x: radiusX.
	 * param1.y: radiusY.
	 * param1.z: radiusZ.
	 *
	 * param2.Width: stackCount.
	 * param2.Height: sliceCount.
	 */
	SYNKRO_ENUM_CONST( MeshBuilder, Ellipsoid )

	/**
	 * Plane mesh.
	 *
	 * Parameters:
	 * param1.x: width.
	 * param1.y: depth.
	 *
	 * param2.Width: segmentCount.
	 */
	SYNKRO_ENUM_CONST( MeshBuilder, Plane )

	/**
	 * Pyramid mesh.
	 *
	 * Parameters:
	 * param1.x: width.
	 * param1.y: depth.
	 * param1.z: height.
	 */
	SYNKRO_ENUM_CONST( MeshBuilder, Pyramid )

	/**
	 * Torus mesh.
	 *
	 * Parameters:
	 * param1.x: radiusMinor.
	 * param1.y: radiusMajor.
	 *
	 * param2.Width: ringCount.
	 * param2.Height: sideCount.
	 */
	SYNKRO_ENUM_CONST( MeshBuilder, Torus )

	/**
	 * Converts mesh builder type to string.
	 */
	lang::String											ToString() const;
SYNKRO_ENUM_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_MESHBUILDER_
