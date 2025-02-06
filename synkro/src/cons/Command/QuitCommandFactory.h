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
// Purpose: "Quit" console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_QUITCOMMANDFACTORY_
#define _SYNKRO_CONS_QUITCOMMANDFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <cons/IConsoleCommandFactory.h>
#include "QuitCommand.h"


namespace synkro
{


namespace cons
{


// "Quit" console command factory.
SYNKRO_FACTORY_BEGIN( QuitCommandFactory, IConsoleCommandFactory, Iface::ConsoleCommand, 7 )
	IConsoleCommand*	Create( IConsole* console ) { return new QuitCommand(console, L"Deactivates the console", L"quit"); }
	lang::String		GetName() const { return L"quit"; }
	lang::String		GetAlias() const { return lang::String::Empty; }
SYNKRO_FACTORY_END()


} // cons


} // synkro


#endif // _SYNKRO_CONS_QUITCOMMANDFACTORY_
