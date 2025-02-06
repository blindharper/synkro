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
// Purpose: Defines abstract rendering object.
//==============================================================================
#ifndef _SYNKRO_GFX_IRENDEROBJECT_
#define _SYNKRO_GFX_IRENDEROBJECT_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Abstract rendering object.
 */
iface IRenderObject :
	public core::IObject
{
public:
	/**
	 * Enables/disables object rendering.
	 */
	virtual void											Enable( Bool enable ) = 0;

	/**
	 * Checks whether object rendering is enabled.
	 */
	virtual Bool											IsEnabled() const = 0;

	/**
	 * Retrieves program used to render the object.
	 */
	virtual IProgram*										GetProgram() const = 0;
	
	/**
	 * Retrieves object geometry.
	 */
	virtual IPrimitiveEx*									GetData() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRENDEROBJECT_
