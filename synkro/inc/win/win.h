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
// Purpose: 'win' namespace includes.
//==============================================================================
#ifndef _SYNKRO_WIN_
#define _SYNKRO_WIN_


#include <win/IIconWindow.h>
#include <win/IFrameWindowEx.h>
#include <win/IViewWindowEx.h>
#include <win/IMonitor.h>
#include <win/IWindowSystemEx.h>
#include <win/IWindowSystemFactory.h>
#include <win/WindowListener.h>
#include <win/WindowSystem.h>


#define PtrIconWindow P(synkro::win::IIconWindow)


namespace synkro
{


/**
 * The 'win' namespace contains interfaces for creating
 * windows that will host graphics stuff.
 */
namespace win
{
} // win


} // synkro


#endif // _SYNKRO_WIN_
