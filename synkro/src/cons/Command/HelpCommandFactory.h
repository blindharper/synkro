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
// Purpose: "Help" console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_HELPCOMMANDFACTORY_
#define _SYNKRO_CONS_HELPCOMMANDFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <cons/IConsoleCommandFactory.h>
#include "HelpCommand.h"


namespace synkro
{


namespace cons
{


// "Help" console command factory.
SYNKRO_FACTORY_BEGIN( HelpCommandFactory, IConsoleCommandFactory, Iface::ConsoleCommand, 5 )
	IConsoleCommand*	Create( IConsole* console ) { return new HelpCommand(console, L"Displays help on console commands", L"help [command]"); }
	lang::String		GetName() const { return L"help"; }
	lang::String		GetAlias() const { return lang::String::Empty; }
SYNKRO_FACTORY_END()


} // cons


} // synkro


#endif // _SYNKRO_CONS_HELPCOMMANDFACTORY_
