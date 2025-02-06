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
// Purpose: "Version" console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_VERSIONCOMMANDFACTORY_
#define _SYNKRO_CONS_VERSIONCOMMANDFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <cons/IConsoleCommandFactory.h>
#include "VersionCommand.h"


namespace synkro
{


namespace cons
{


// "Version" console command factory.
SYNKRO_FACTORY_BEGIN( VersionCommandFactory, IConsoleCommandFactory, Iface::ConsoleCommand, 9 )
	IConsoleCommand*	Create( IConsole* console ) { return new VersionCommand(console, L"Prints current Synkro version", L"version"); }
	lang::String		GetName() const { return L"version"; }
	lang::String		GetAlias() const { return L"ver"; }
SYNKRO_FACTORY_END()


} // cons


} // synkro


#endif // _SYNKRO_CONS_VERSIONCOMMANDFACTORY_
