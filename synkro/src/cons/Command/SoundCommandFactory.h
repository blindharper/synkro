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
// Purpose: "Sound" console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_SOUNDCOMMANDFACTORY_
#define _SYNKRO_CONS_SOUNDCOMMANDFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <cons/IConsoleCommandFactory.h>
#include "SoundCommand.h"


namespace synkro
{


namespace cons
{


// "Sound" console command factory.
SYNKRO_FACTORY_BEGIN( SoundCommandFactory, IConsoleCommandFactory, Iface::ConsoleCommand, 8 )
	IConsoleCommand*	Create( IConsole* console ) { return new SoundCommand(console, L"Enables or disables sound", L"sound [on|off]"); }
	lang::String		GetName() const { return L"sound"; }
	lang::String		GetAlias() const { return lang::String::Empty; }
SYNKRO_FACTORY_END()


} // cons


} // synkro


#endif // _SYNKRO_CONS_SOUNDCOMMANDFACTORY_
