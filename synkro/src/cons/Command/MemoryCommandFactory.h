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
// Purpose: "Memory" console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_MEMORYCOMMANDFACTORY_
#define _SYNKRO_CONS_MEMORYCOMMANDFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <cons/IConsoleCommandFactory.h>
#include "MemoryCommand.h"


namespace synkro
{


namespace cons
{


// "Memory" console command factory.
SYNKRO_FACTORY_BEGIN( MemoryCommandFactory, IConsoleCommandFactory, Iface::ConsoleCommand, 6 )
	IConsoleCommand*	Create( IConsole* console ) { return new MemoryCommand(console, L"Display memory usage statistics", L"memory"); }
	lang::String		GetName() const { return L"memory"; }
	lang::String		GetAlias() const { return L"mem"; }
SYNKRO_FACTORY_END()


} // cons


} // synkro


#endif // _SYNKRO_CONS_MEMORYCOMMANDFACTORY_
