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
// Purpose: Defines animation codec factory.
//==============================================================================
#ifndef _SYNKRO_ANIM_IANIMATIONCODECFACTORY_
#define _SYNKRO_ANIM_IANIMATIONCODECFACTORY_


#include "config.h"
#include <core/IFactory.h>


namespace synkro
{


namespace anim
{


/**
 * Animation codec factory.
 */
iface IAnimationCodecFactory :
	public core::IFactory
{
public:
	/**
	 * Creates animation codec.
	 * @param context Framework context.
	 */
	virtual IAnimationCodec*								Create( core::IContext* context ) = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IANIMATIONCODECFACTORY_
