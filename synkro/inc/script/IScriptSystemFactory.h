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
// Purpose: Defines script system factory.
//==============================================================================
#ifndef _SYNKRO_SCRIPT_ISCRIPTSYSTEMFACTORY_
#define _SYNKRO_SCRIPT_ISCRIPTSYSTEMFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace script
{


/**
 * Script system factory.
 */
iface IScriptSystemFactory :
	public core::IFactory
{
public:
	/**
	 * Creates script system.
	 * @param log Log to write debug messages to.
	 * @return Created script system.
	 */
	virtual IScriptSystem*									Create( diag::ILog* log ) = 0;
};


} // script


} // synkro


#endif // _SYNKRO_SCRIPT_ISCRIPTSYSTEMFACTORY_
