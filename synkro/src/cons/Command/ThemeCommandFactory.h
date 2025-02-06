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
// Purpose: "Theme" console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_THEMECOMMANDFACTORY_
#define _SYNKRO_CONS_THEMECOMMANDFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <cons/IConsoleCommandFactory.h>
#include "ThemeCommand.h"


namespace synkro
{


namespace cons
{


// "Theme" console command factory.
SYNKRO_FACTORY_BEGIN( ThemeCommandFactory, IConsoleCommandFactory, Iface::ConsoleCommand, 10 )
	IConsoleCommand*	Create( IConsole* console ) { return new ThemeCommand(console, L"Sets UI theme", L"theme [name]"); }
	lang::String		GetName() const { return L"theme"; }
	lang::String		GetAlias() const { return lang::String::Empty; }
SYNKRO_FACTORY_END()


} // cons


} // synkro


#endif // _SYNKRO_CONS_THEMECOMMANDFACTORY_
