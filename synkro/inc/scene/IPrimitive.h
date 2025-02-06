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
// Purpose: Defines abstract geometric primitive.
//==============================================================================
#ifndef _SYNKRO_SCENE_IPRIMITIVE_
#define _SYNKRO_SCENE_IPRIMITIVE_


#include "config.h"
#include <core/IObject.h>
#include <math/Matrix4x4.h>
#include <lang/Range.h>
#include <img/Color.h>


namespace synkro
{


namespace scene
{


/**
 * Geometric primitive.
 */
iface IPrimitive :
	public core::IObject
{
public:
	/**
	 * Creates primitive controller.
	 * @param animation Optional node animation.
	 * @param listener Controller listener.
	 * @return Created controller.
	 */
	virtual IPrimitiveAnimationController*					CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener ) = 0;

	/** 
	 * Shows or hides primitive.
	 * @param show Set to true to make primitive visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/**
	 * Sets the range of active primitive elements.
	 * @param range Element range.
	 */
	virtual void											SetElementRange( const lang::Range& range ) = 0;

	/**
	 * Sets the range of active primitive instances.
	 * @param range Instance range.
	 */
	virtual void											SetInstanceRange( const lang::Range& range ) = 0;

	/**
	 * Sets primitive transformation.
	 * @param transform Primitive transformation.
	 */
	virtual void											SetTransform( const math::Matrix4x4& transform ) = 0;

	/**
	 * Sets primitive's owner transformation.
	 * @param transform Owner transformation.
	 */
	virtual void											SetOwnerTransform( const math::Matrix4x4& transform ) = 0;

	/**
	 * Sets primitive instance transformation.
	 * @param index Instance index.
	 * @param transform Instance transformation.
	 */
	virtual void											SetInstanceTransform( UInt index, const math::Matrix4x4& transform ) = 0;

	/**
	 * Sets primitive instance color.
	 * @param index Instance index.
	 * @param color Instance color.
	 */
	virtual void											SetInstanceColor( UInt index, const img::Color& color ) = 0;

	/**
	 * Reallocates primitive's vertices and indices.
	 * @param vertexCount New number of vertices in the primitive.
	 * @param indexCount New number of vertex indices in the primitive.
	 */
	virtual void											Resize( UInt vertexCount, UInt indexCount ) = 0;

	/**
	 * Retrieves primitive visibility.
	 */
	virtual Bool											IsVisible() const = 0;

	/**
	 * Retrieves the range of active primitive elements.
	 * @param [out] range Element range.
	 */
	virtual void											GetElementRange( lang::Range& range ) const = 0;

	/**
	 * Retrieves the range of active primitive instances.
	 * @param [out] range Instance range.
	 */
	virtual void											GetInstanceRange( lang::Range& range ) const = 0;

	/**
	 * Retrieves total number of primitive vertices.
	 */
	virtual UInt											GetVertexCount() const = 0;

	/**
	 * Retrieves total number of primitive indices.
	 */
	virtual UInt											GetIndexCount() const = 0;

	/**
	 * Retrieves total number of primitive elements.
	 * That would be the number of indices for indexed primitives, or the number of vertices otherwise.
	 */
	virtual UInt											GetElementCount() const = 0;

	/**
	 * Retrieves primitive transformation.
	 * @param [out] transform Primitive transformation.
	 */
	virtual void											GetTransform( math::Matrix4x4& transform ) const = 0;

	/**
	 * Retrieves primitive's center of masses.
	 * @param [out] center Primitive's center.
	 */
	virtual void											GetCenter( math::Vector3& center ) const = 0;

	/**
	 * Retrieves primitive's bounding sphere.
	 * @return Bounding sphere.
	 */
	virtual Float											GetBoundSphere() const = 0;

	/**
	 * Casts primitive to point set.
	 * @return Non-null for point set, nullptr otherwise.
	 */
	virtual IPointSet*										AsPointSet() const = 0;

	/**
	 * Casts primitive to line set.
	 * @return Non-null for line set, nullptr otherwise.
	 */
	virtual ILineSet*										AsLineSet() const = 0;

	/**
	 * Casts primitive to triangle set.
	 * @return Non-null for triangle set, nullptr otherwise.
	 */
	virtual ITriangleSet*									AsTriangleSet() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IPRIMITIVE_
