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
// Purpose: "Clear" console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_CLEARCOMMANDFACTORY_
#define _SYNKRO_CONS_CLEARCOMMANDFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <cons/IConsoleCommandFactory.h>
#include "ClearCommand.h"


namespace synkro
{


namespace cons
{


// "Clear" console command factory.
SYNKRO_FACTORY_BEGIN( ClearCommandFactory, IConsoleCommandFactory, Iface::ConsoleCommand, 1 )
	IConsoleCommand*	Create( IConsole* console ) { return new ClearCommand(console, L"Clears console buffer", L"clear"); }
	lang::String		GetName() const { return L"clear"; }
	lang::String		GetAlias() const { return L"cls"; }
SYNKRO_FACTORY_END()


} // cons


} // synkro


#endif // _SYNKRO_CONS_CLEARCOMMANDFACTORY_
