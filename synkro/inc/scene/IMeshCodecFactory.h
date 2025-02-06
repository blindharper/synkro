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
// Purpose: Defines mesh codec factory.
//==============================================================================
#ifndef _SYNKRO_SCENE_IMESHCODECFACTORY_
#define _SYNKRO_SCENE_IMESHCODECFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace scene
{


/**
 * Mesh codec factory.
 */
iface IMeshCodecFactory :
	public core::IFactory
{
public:
	/**
	 * Creates mesh codec.
	 * @param context Framework context.
	 */
	virtual IMeshCodec*										Create( core::IContext* context ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IMESHCODECFACTORY_
