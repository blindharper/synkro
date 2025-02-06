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
// Purpose: Defines sound codec factory.
//==============================================================================
#ifndef _SYNKRO_SOUND_ISOUNDCODECFACTORY_
#define _SYNKRO_SOUND_ISOUNDCODECFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace sound
{


/**
 * Sound codec factory.
 */
iface ISoundCodecFactory :
	public core::IFactory
{
public:
	/**
	 * Creates sound codec.
	 */
	virtual ISoundCodec*									Create() = 0;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_ISOUNDCODECFACTORY_
