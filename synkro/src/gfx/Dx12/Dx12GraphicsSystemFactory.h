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
// Purpose: DirectX 12 graphics system factory.
//==============================================================================
#ifndef _SYNKRO_GFX_DX12GRAPHICSSYSTEMFACTORY_
#define _SYNKRO_GFX_DX12GRAPHICSSYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <gfx/IGraphicsSystemFactory.h>
#include <gfx/GraphicsSystem.h>
#include "Dx12GraphicsSystem.h"


namespace synkro
{


namespace gfx
{


// DirectX 12 graphics system factory.
SYNKRO_FACTORY_BEGIN( Dx12GraphicsSystemFactory, IGraphicsSystemFactory, GraphicsSystem, GraphicsSystem::DirectX12 )
	IGraphicsSystem*	Create( win::IWindowSystemEx* windowSystem, diag::ILog* log ) { return new Dx12GraphicsSystem(log); }
SYNKRO_FACTORY_END()


} // gfx


} // synkro


#endif // _SYNKRO_GFX_DX12GRAPHICSSYSTEMFACTORY_
