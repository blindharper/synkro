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
// Purpose: Defines stream system factory.
//==============================================================================
#ifndef _SYNKRO_IO_ISTREAMSYSTEMFACTORY_
#define _SYNKRO_IO_ISTREAMSYSTEMFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace io
{


/**
 * Stream system factory.
 */
iface IStreamSystemFactory :
	public core::IFactory
{
public:
	/**
	 * Creates a stream system.
	 * @param log Log to write debug messages to.
	 * @return Created stream system.
	 */
	virtual IStreamSystem*									Create( diag::ILog* log ) = 0;
};


} // io


} // synkro


#endif // _SYNKRO_IO_ISTREAMSYSTEMFACTORY_
