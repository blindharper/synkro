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
// Purpose: Defines "Look At" constraint.
//==============================================================================
#ifndef _SYNKRO_SCENE_ILOOKATCONSTRAINT_
#define _SYNKRO_SCENE_ILOOKATCONSTRAINT_


#include "config.h"
#include <core/IConstraint.h>


namespace synkro
{


namespace scene
{


/**
 * "Look At" constraint. Restricts node orientation.
 */
iface ILookAtConstraint :
	public core::IConstraint
{
public:
	/**
	 * Sets node to look at.
	 * @param target Target node.
	 */
	virtual void											SetTarget( INode* target ) = 0;

	/**
	 * Retrieves target node.
	 */
	virtual INode*											GetTarget() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ILOOKATCONSTRAINT_
