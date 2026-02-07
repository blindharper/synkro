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
// Purpose: Defines abstract collision shape.
//==============================================================================
#ifndef _SYNKRO_PHYS_ISHAPE_
#define _SYNKRO_PHYS_ISHAPE_


#include "config.h"
#include <core/IObject.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace phys
{


/**
 * Abstract collision shape.
 */
iface IShape :
	public core::IObject
{
public:
	/**
	 * Sets shape contact offset. This value is used to detect collisions.
	 * @param offset New contact offset. Valid range is (max(0,restOffset),inf).
	 */
	virtual void											SetContactOffset( Float offset ) = 0;

	/**
	 * Sets shape rest offset. Two shapes will come to rest at a distance equal to the sum of their restOffset values.
	 * @param offset New rest offset. Valid range is (-inf,contactOffset).
	 */
	virtual void											SetRestOffset( Float offset ) = 0;

	/**
	 * Sets shape's local transform in actor's space.
	 * @param transform Local shape transform.
	 */
	virtual void											SetLocalTransform( const math::Matrix4x4& transform ) = 0;

	/**
	 * Retrieves shape contact offset.
	 */
	virtual Float											GetContactOffset() const = 0;

	/**
	 * Retrieves shape rest offset.
	 */
	virtual Float											GetRestOffset() const = 0;

	/**
	 * Retrieves shapes's local transform in actor's space.
	 * @param [out] transform Variable where to store transform.
	 */
	virtual void											GetLocalTransform( math::Matrix4x4& transform ) const = 0;

	/**
	 * Retrieves shapes's transform.
	 * @param [out] transform Variable where to store transform.
	 */
	virtual void											GetTransform( math::Matrix4x4& transform ) const = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_ISHAPE_
