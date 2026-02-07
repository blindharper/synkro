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
// Purpose: Defines rigid actor.
//==============================================================================
#ifndef _SYNKRO_PHYS_IRIGIDACTOR_
#define _SYNKRO_PHYS_IRIGIDACTOR_


#include "config.h"
#include <phys/IActor.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace phys
{


/**
 * Rigid actor.
 */
iface IRigidActor :
	public IActor
{
public:
	/**
	 * Sets actor's world space transform.
	 * @param transform World space transform.
	 */
	virtual void											SetWorldTransform( const math::Matrix4x4& transform ) = 0;

	/**
	 * Retrieves actor's world space transform.
	 * @param [out] transform Variable where to store transform.
	 */
	virtual void											GetWorldTransform( math::Matrix4x4& transform ) const = 0;

	/**
	 * Retrieves actor's shape.
	 * @return Requested shape.
	 */
	virtual IShape*											GetShape() const = 0;
};


} // phys


} // synkro


#endif // _SYNKRO_PHYS_IRIGIDACTOR_
