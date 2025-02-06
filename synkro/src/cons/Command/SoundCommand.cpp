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
// Purpose: "Sound" console command.
//==============================================================================
#include "config.h"
#include "SoundCommand.h"
#include <cons/Console.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace cons
{


SoundCommand::SoundCommand( IConsole* console, const String& description, const String& syntax ) :
	ConsoleCommandImpl<IConsoleCommand>( console, description, syntax )
{
}

void SoundCommand::Execute( const String& arg )
{
	Console* con = (Console*)_console;

	if ( arg.IsEmpty() )
	{
		con->Print( con->IsSoundEnabled() ? L"Sound enabled" : L"Sound disabled" );
	}
	else
	{
		if ( arg.EqualsTo(L"on", true) )
		{
			con->EnableSound( true );
			_console->Echo( L"Sound enabled" );
		}
		else if ( arg.EqualsTo("off", true) )
		{
			con->EnableSound( false );
			_console->Echo( L"Sound disabled" );
		}
		else
		{
			con->Print( L"Invalid command argument." );
		}
	}
}


} // cons


} // synkro
