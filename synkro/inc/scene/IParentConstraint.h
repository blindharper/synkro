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
// Purpose: Defines parent constraint.
//==============================================================================
#ifndef _SYNKRO_SCENE_IPARENTCONSTRAINT_
#define _SYNKRO_SCENE_IPARENTCONSTRAINT_


#include "config.h"
#include <core/IConstraint.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace scene
{


/**
 * Parent constraint. Restricts node position.
 */
iface IParentConstraint :
	public core::IConstraint
{
public:
	/**
	 * Sets parent node.
	 * @param parent Parent node.
	 */
	virtual void											SetParent( INode* parent ) = 0;

	/**
	 * Retrieves parent node.
	 */
	virtual INode*											GetParent() const = 0;

	/**
	 * Retrieves node-to-parent transform.
	 * @param [out] transform Variable where to store transform.
	 */
	virtual void											GetTransform( math::Matrix4x4& transform ) const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IPARENTCONSTRAINT_
