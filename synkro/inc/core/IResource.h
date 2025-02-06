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
// Purpose: Defines resource directory.
//==============================================================================
#ifndef _SYNKRO_CORE_IRESOURCE_
#define _SYNKRO_CORE_IRESOURCE_


#include "config.h"
#include <core/ResourceType.h>


namespace synkro
{


namespace core
{


/**
 * Resource directory.
 */
iface IResource
{
public:
	/**
	 * Loads resource and provides read-only access to it.
	 */
	virtual io::IStreamDirectory*							Load() = 0;

	/**
	 * Retrieves resource type.
	 */
	virtual ResourceType									GetType() const = 0;

	/**
	 * Returns resource identifier.
	 */
	virtual UInt											ID() const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_IRESOURCE_
