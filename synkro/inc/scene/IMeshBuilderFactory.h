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
// Purpose: Defines mesh builder factory.
//==============================================================================
#ifndef _SYNKRO_SCENE_IMESHBUILDERFACTORY_
#define _SYNKRO_SCENE_IMESHBUILDERFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace scene
{


/**
 * Mesh builder factory.
 */
iface IMeshBuilderFactory :
	public core::IFactory
{
public:
	/**
	 * Creates mesh builder.
	 */
	virtual IMeshBuilder*									Create() = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IMESHBUILDERFACTORY_
