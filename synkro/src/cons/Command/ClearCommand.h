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
// Purpose: "Clear" console command.
//==============================================================================
#ifndef _SYNKRO_CONS_CLEARCOMMAND_
#define _SYNKRO_CONS_CLEARCOMMAND_


#include "config.h"
#include "ConsoleCommandImpl.h"
#include <cons/IConsoleCommand.h>


namespace synkro
{


namespace cons
{


class ClearCommand :
	public ConsoleCommandImpl<IConsoleCommand>
{
public:
	ClearCommand( IConsole* console, const lang::String& description, const lang::String& syntax );

	// IConsoleCommand methods.
	void													Execute( const lang::String& arg );
};


} // cons


} // synkro


#endif // _SYNKRO_CONS_CLEARCOMMAND_
