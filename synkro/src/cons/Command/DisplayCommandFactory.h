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
// Purpose: "Display" console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_DISPLAYCOMMANDFACTORY_
#define _SYNKRO_CONS_DISPLAYCOMMANDFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <cons/IConsoleCommandFactory.h>
#include "DisplayCommand.h"


namespace synkro
{


namespace cons
{


// "Display" console command factory.
SYNKRO_FACTORY_BEGIN( DisplayCommandFactory, IConsoleCommandFactory, Iface::ConsoleCommand, 3 )
	IConsoleCommand*	Create( IConsole* console ) { return new DisplayCommand(console, L"Sets or reports display mode", L"display [toggle|WidthxHeight[ fullscreen|windowed]]"); }
	lang::String		GetName() const { return L"display"; }
	lang::String		GetAlias() const { return lang::String::Empty; }
SYNKRO_FACTORY_END()


} // cons


} // synkro


#endif // _SYNKRO_CONS_DISPLAYCOMMANDFACTORY_
