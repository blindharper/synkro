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
// Purpose: "Echo" console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_ECHOCOMMANDFACTORY_
#define _SYNKRO_CONS_ECHOCOMMANDFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <cons/IConsoleCommandFactory.h>
#include "EchoCommand.h"


namespace synkro
{


namespace cons
{


// "Echo" console command factory.
SYNKRO_FACTORY_BEGIN( EchoCommandFactory, IConsoleCommandFactory, Iface::ConsoleCommand, 4 )
	IConsoleCommand*	Create( IConsole* console ) { return new EchoCommand(console, L"Enables or disables echo", L"echo [on|off]"); }
	lang::String		GetName() const { return L"echo"; }
	lang::String		GetAlias() const { return lang::String::Empty; }
SYNKRO_FACTORY_END()


} // cons


} // synkro


#endif // _SYNKRO_CONS_ECHOCOMMANDFACTORY_
