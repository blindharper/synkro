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
// Purpose: Defines a set of triangle mesh nodes.
//==============================================================================
#ifndef _SYNKRO_SCENE_ITRIANGLEMESHSET_
#define _SYNKRO_SCENE_ITRIANGLEMESHSET_


#include "config.h"
#include <scene/ITriangleMesh.h>


namespace synkro
{


namespace scene
{


/**
 * A set of triangle mesh nodes. Holds several levels of detail.
 */
iface ITriangleMeshSet :
	public ITriangleMesh
{
public:
	/**
	 * Sets minimum mesh screen size, in pixels, at which the level should be activated.
	 * @param index Level index.
	 * @param minSize Screen size.
	 */
	virtual void											SetMinimumLevelSize( UInt index, Float size ) = 0;

	/**
	 * Retrieves the number of levels in the set.
	 */
	virtual UInt											GetLevelCount() const = 0;

	/**
	 * Retrieves minimum mesh screen size, in pixels, at which the level should be activated.
	 * @param index Level index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual Float											GetMinimumLevelSize( UInt index ) const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ITRIANGLEMESHSET_
