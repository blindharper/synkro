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
// Purpose: "Echo" console command.
//==============================================================================
#include "config.h"
#include "EchoCommand.h"
#include <cons/Console.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace cons
{


EchoCommand::EchoCommand( IConsole* console, const String& description, const String& syntax ) :
	ConsoleCommandImpl<IConsoleCommand>( console, description, syntax )
{
}

void EchoCommand::Execute( const String& arg )
{
	Console* con = (Console*)_console;

	if ( arg.IsEmpty() )
	{
		con->Print( con->IsEchoEnabled() ? L"Echo enabled" : L"Echo disabled" );
	}
	else
	{
		if ( arg.EqualsTo(L"on", true) )
		{
			con->EnableEcho( true );
			con->Print( L"Echo enabled" );
		}
		else if ( arg.EqualsTo("off", true) )
		{
			con->EnableEcho( false );
			con->Print( L"Echo disabled" );
		}
		else
		{
			con->Print( L"Invalid command argument." );
		}
	}
}


} // cons


} // synkro
