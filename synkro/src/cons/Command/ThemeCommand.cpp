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
// Purpose: "Theme" console command.
//==============================================================================
#include "config.h"
#include "ThemeCommand.h"
#include <cons/Console.h>
#include <ui/IUiEx.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::ui;

//------------------------------------------------------------------------------


namespace synkro
{


namespace cons
{


ThemeCommand::ThemeCommand( IConsole* console, const String& description, const String& syntax ) :
	ConsoleCommandImpl<IConsoleCommand>( console, description, syntax )
{
}

void ThemeCommand::Execute( const String& arg )
{
	Console* con = (Console*)_console;

	if ( arg.IsEmpty() )
	{
		ThemeName name = con->GetUi()->GetThemeName();
		con->Print( name.ToString() );
	}
	else
	{
		ThemeName name( arg );
		if ( name != ThemeName::Custom )
		{
			con->GetUi()->SetThemeName( name );
		}
		else
		{
			con->Print( L"Unknown theme." );
		}
	}
}


} // cons


} // synkro
