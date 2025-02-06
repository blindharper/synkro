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
// Purpose: DirectX 11 graphics system factory.
//==============================================================================
#ifndef _SYNKRO_GFX_DX11GRAPHICSSYSTEMFACTORY_
#define _SYNKRO_GFX_DX11GRAPHICSSYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <gfx/IGraphicsSystemFactory.h>
#include <gfx/GraphicsSystem.h>
#include "Dx11GraphicsSystem.h"


namespace synkro
{


namespace gfx
{


// DirectX 11 graphics system factory.
SYNKRO_FACTORY_BEGIN( Dx11GraphicsSystemFactory, IGraphicsSystemFactory, GraphicsSystem, GraphicsSystem::DirectX11 )
	IGraphicsSystem*	Create( win::IWindowSystemEx* windowSystem, diag::ILog* log ) { return new Dx11GraphicsSystem(log); }
SYNKRO_FACTORY_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX11GRAPHICSSYSTEMFACTORY_
