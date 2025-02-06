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
// Purpose: Defines abstract visual material.
//==============================================================================
#ifndef _SYNKRO_MAT_IVISUALMATERIAL_
#define _SYNKRO_MAT_IVISUALMATERIAL_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace mat
{


/**
 * Abstract visual material.
 */
iface IVisualMaterial :
	public core::IObject
{
public:
	/**
	 * Creates animation controller.
	 * @param animation Optional material animation.
	 * @param listener Controller listener.
	 * @return Created controller.
	 */
	virtual IVisualMaterialAnimationController*				CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener ) = 0;

	/**
	 * Creates triangle list primitive.
	 * @param mesh Mesh that will own the primitive.
	 * @param index Material subset index.
	 * @param vertexCount Total number of vertices in the list.
	 * @param indexCount Number of vertex indices.
	 * @param adjacency Indicates whether the list contains adjacency information.
	 * @return Created triangle list.
	 */
	virtual scene::ITriangleSet*							CreateTriangleList( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency ) = 0;

	/**
	 * Creates triangle strip primitive.
	 * @param mesh Mesh that will own the primitive.
	 * @param index Material subset index.
	 * @param vertexCount Total number of vertices in the strip.
	 * @param indexCount Number of vertex indices.
	 * @param adjacency Indicates whether the strip contains adjacency information.
	 * @return Created triangle strip.
	 */
	virtual scene::ITriangleSet*							CreateTriangleStrip( scene::ITriangleMesh* mesh, UInt index, UInt vertexCount, UInt indexCount, Bool adjacency ) = 0;

	/**
	 * Indicates whether the geometry created with this material has per-vertex color.
	 * @param colored True to enable per-vertex geometry color, false to disable.
	 */
	virtual void											SetColored( Bool colored ) = 0;

	/**
	 * Indicates whether the geometry created with this material has per-vertex color.
	 */
	virtual Bool											IsColored() const = 0;

	/**
	 * Retrieves the total number of sub-materials.
	 */
	virtual UInt											GetSubsetCount() const = 0;

	/**
	 * Casts material to simple material.
	 * @return Non-null for simple material, nullptr otherwise.
	 */
	virtual ISimpleMaterial*								AsSimple() const = 0;

	/**
	 * Casts material to multi-material.
	 * @return Non-null for multi-material, nullptr otherwise.
	 */
	virtual IMultiMaterial*									AsMulti() const = 0;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_IVISUALMATERIAL_
