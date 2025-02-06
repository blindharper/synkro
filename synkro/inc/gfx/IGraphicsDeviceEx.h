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
// Purpose: Defines extended graphics device.
//==============================================================================
#ifndef _SYNKRO_GFX_IGRAPHICSDEVICEEX_
#define _SYNKRO_GFX_IGRAPHICSDEVICEEX_


#include "config.h"
#include <gfx/IGraphicsDevice.h>


namespace synkro
{


namespace gfx
{


/**
 * Extended graphics device.
 */
iface IGraphicsDeviceEx :
	public IGraphicsDevice
{
public:
	/**
	 * Retrieves program by name.
	 * @param name Program unique name.
	 * @return Requested program, if one exists, nullptr otherwise.
	 */
	virtual IProgram*										GetProgram( const lang::String& name ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IGRAPHICSDEVICEEX_
