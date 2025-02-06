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
// Purpose: "Machine" console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_MACHINECOMMANDFACTORY_
#define _SYNKRO_CONS_MACHINECOMMANDFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <cons/IConsoleCommandFactory.h>
#include "MachineCommand.h"


namespace synkro
{


namespace cons
{


// "Machine" console command factory.
SYNKRO_FACTORY_BEGIN( MachineCommandFactory, IConsoleCommandFactory, Iface::ConsoleCommand, 11 )
	IConsoleCommand*	Create( IConsole* console ) { return new MachineCommand(console, L"Sets or retrieves console script machine", L"machine [name|index]"); }
	lang::String		GetName() const { return L"machine"; }
	lang::String		GetAlias() const { return lang::String::Empty; }
SYNKRO_FACTORY_END()


} // cons


} // synkro


#endif // _SYNKRO_CONS_MACHINECOMMANDFACTORY_
