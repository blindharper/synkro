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
// Purpose: Win32 window system factory.
//==============================================================================
#ifndef _SYNKRO_WIN_WIN32WINDOWSYSTEMFACTORY_
#define _SYNKRO_WIN_WIN32WINDOWSYSTEMFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <win/IWindowSystemFactory.h>
#include <win/WindowSystem.h>
#include "Win32WindowSystem.h"


namespace synkro
{


namespace win
{


// Win32 window system factory.
SYNKRO_FACTORY_BEGIN( Win32WindowSystemFactory, IWindowSystemFactory, WindowSystem, WindowSystem::Win32 )
	IWindowSystem*	Create( Pointer module, diag::ILog* log ) { return new Win32WindowSystem(module, log); }
SYNKRO_FACTORY_END()


} // win


} // synkro


#endif // _SYNKRO_WIN_WIN32WINDOWSYSTEMFACTORY_
