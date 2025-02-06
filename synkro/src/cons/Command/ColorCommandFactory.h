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
// Purpose: "Color" console command factory.
//==============================================================================
#ifndef _SYNKRO_CONS_COLORCOMMANDFACTORY_
#define _SYNKRO_CONS_COLORCOMMANDFACTORY_


#include "config.h"
#include <core/FactoryImpl.h>
#include <cons/IConsoleCommandFactory.h>
#include "ColorCommand.h"


namespace synkro
{


namespace cons
{


// "Color" console command factory.
SYNKRO_FACTORY_BEGIN( ColorCommandFactory, IConsoleCommandFactory, Iface::ConsoleCommand, 2 )
	IConsoleCommand*	Create( IConsole* console ) { return new ColorCommand(console, L"Gets or sets console text or UI color", L"color text|theme [color]"); }
	lang::String		GetName() const { return L"color"; }
	lang::String		GetAlias() const { return lang::String::Empty; }
SYNKRO_FACTORY_END()


} // cons


} // synkro


#endif // _SYNKRO_CONS_COLORCOMMANDFACTORY_
