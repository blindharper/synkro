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
// Purpose: Binary animation codec factory.
//==============================================================================
#ifndef _SYNKRO_ANIM_BINANIMATIONCODECFACTORY_
#define _SYNKRO_ANIM_BINANIMATIONCODECFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <anim/IAnimationCodecFactory.h>
#include <anim/AnimationCodec.h>
#include "BinAnimationCodec.h"


namespace synkro
{


namespace anim
{


// Binary animation codec factory.
SYNKRO_FACTORY_BEGIN( BinAnimationCodecFactory, IAnimationCodecFactory, AnimationCodec, AnimationCodec::Bin )
	IAnimationCodec*	Create( core::IContext* context ) { return new BinAnimationCodec(context); }
SYNKRO_FACTORY_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_BINANIMATIONCODECFACTORY_
