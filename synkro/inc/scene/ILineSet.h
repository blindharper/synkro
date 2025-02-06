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
// Purpose: Defines line set primitive.
//==============================================================================
#ifndef _SYNKRO_SCENE_ILINESET_
#define _SYNKRO_SCENE_ILINESET_


#include "config.h"
#include <scene/IPrimitive.h>
#include <img/Color.h>


namespace synkro
{


namespace scene
{


/**
 * A collection of lines.
 */
iface ILineSet :
	public IPrimitive
{
public:
	/**
	 * Sets vertex position coordinates.
	 * @param positions Array of vertex positions.
	 * @param start Index of the starting vertex.
	 * @param count Total number of vertices.
	 */
	virtual void											SetPositions( const math::Vector3* positions, UInt start, UInt count ) = 0;

	/**
	 * Sets vertex position coordinates in 4D.
	 * @param positions Array of vertex positions.
	 * @param start Index of the starting vertex.
	 * @param count Total number of vertices.
	 */
	virtual void											SetPositions( const math::Vector4* positions, UInt start, UInt count ) = 0;

	/**
	 * Sets vertex colors.
	 * @param colors Array of vertex colors.
	 * @param start Index of the starting vertex.
	 * @param count Total number of vertices.
	 */
	virtual void											SetColors( const img::Color* colors, UInt start, UInt count ) = 0;

	/**
	 * Sets element indices.
	 * @param indices Index data.
	 * @param start Index of the starting vertex.
	 * @param count Total number of indices to set.
	 */
	virtual void											SetIndices( const UInt* indices, UInt start, UInt count ) = 0;

	/**
	 * Sets all vertex color to the same value.
	 * @param color Color to assign to vertices.
	 */
	virtual void											SetColor( const img::Color& color ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ILINESET_
