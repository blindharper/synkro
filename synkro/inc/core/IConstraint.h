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
// Purpose: Defines abstract constraint.
//==============================================================================
#ifndef _SYNKRO_CORE_ICONSTRAINT_
#define _SYNKRO_CORE_ICONSTRAINT_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace core
{


/**
 * Abstract constraint.
 */
iface IConstraint :
	public IObject
{
public:
	/**
	 * Applies the constraint.
	 */
	virtual void											Apply() = 0;

	/**
	 * Enables/disables the constraint.
	 * @param enable True to enable the constraint, false to disable it.
	 */
	virtual void											Enable( Bool enable ) = 0;

	/**
	 * Indicates whether the constraint is enabled.
	 */
	virtual Bool											IsEnabled() const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_ICONSTRAINT_
