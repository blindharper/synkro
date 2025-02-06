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
// Purpose: Xml animation codec factory.
//==============================================================================
#ifndef _SYNKRO_ANIM_XMLANIMATIONCODECFACTORY_
#define _SYNKRO_ANIM_XMLANIMATIONCODECFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <anim/IAnimationCodecFactory.h>
#include <anim/AnimationCodec.h>
#include "XmlAnimationCodec.h"


namespace synkro
{


namespace anim
{


// Xml animation codec factory.
SYNKRO_FACTORY_BEGIN( XmlAnimationCodecFactory, IAnimationCodecFactory, AnimationCodec, AnimationCodec::Xml )
	IAnimationCodec*	Create( core::IContext* context ) { return new XmlAnimationCodec(context); }
SYNKRO_FACTORY_END()


} // anim


} // synkro


#endif // _SYNKRO_ANIM_XMLANIMATIONCODECFACTORY_
