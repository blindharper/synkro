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
// Purpose: "Quit" console command.
//==============================================================================
#ifndef _SYNKRO_CONS_QUITCOMMAND_
#define _SYNKRO_CONS_QUITCOMMAND_


#include "config.h"
#include "ConsoleCommandImpl.h"
#include <cons/IConsoleCommand.h>


namespace synkro
{


namespace cons
{


class QuitCommand :
	public ConsoleCommandImpl<IConsoleCommand>
{
public:
	QuitCommand( IConsole* console, const lang::String& description, const lang::String& syntax );

	// IConsoleCommand methods.
	void													Execute( const lang::String& arg );
};


} // cons


} // synkro


#endif // _SYNKRO_CONS_QUITCOMMAND_
