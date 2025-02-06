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
// Purpose: Defines graphics system factory.
//==============================================================================
#ifndef _SYNKRO_GFX_IGRAPHICSSYSTEMFACTORY_
#define _SYNKRO_GFX_IGRAPHICSSYSTEMFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace gfx
{


/**
 * Graphics system factory.
 */
iface IGraphicsSystemFactory :
	public core::IFactory
{
public:
	/**
	 * Creates graphics system.
	 * @param windowSystem Window system.
	 * @param log Log to write debug messages to.
	 * @return Created graphics system.
	 */
	virtual IGraphicsSystem*								Create( win::IWindowSystemEx* windowSystem, diag::ILog* log ) = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IGRAPHICSSYSTEMFACTORY_
