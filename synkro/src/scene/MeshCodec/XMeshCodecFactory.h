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
// Purpose: DirectX mesh codec factory.
//==============================================================================
#ifndef _SYNKRO_SCENE_XMESHCODECFACTORY_
#define _SYNKRO_SCENE_XMESHCODECFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <core/IContext.h>
#include <scene/IMeshCodecFactory.h>
#include <scene/MeshCodec.h>
#include "XMeshCodec.h"


namespace synkro
{


namespace scene
{


// DirectX mesh codec factory.
SYNKRO_FACTORY_BEGIN( XMeshCodecFactory, IMeshCodecFactory, MeshCodec, MeshCodec::X )
	IMeshCodec*		Create( core::IContext* context ) { return new XMeshCodec( context->GetSceneManager(), context->GetMaterialManager(), context->GetImageManager(), context->GetAnimationSystem() ); }
SYNKRO_FACTORY_END()


} // scene


} // synkro


#endif // _SYNKRO_SCENE_XMESHCODECFACTORY_
