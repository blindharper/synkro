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
// Purpose: "Color" console command.
//==============================================================================
#include "config.h"
#include "ColorCommand.h"
#include <cons/Console.h>
#include <ui/IUiEx.h>
#include <ui/ITheme.h>


//------------------------------------------------------------------------------

using namespace synkro::img;
using namespace synkro::lang;
using namespace synkro::ui;

//------------------------------------------------------------------------------


namespace synkro
{


namespace cons
{


ColorCommand::ColorCommand( IConsole* console, const String& description, const String& syntax ) :
	ConsoleCommandImpl<IConsoleCommand>( console, description, syntax )
{
}

void ColorCommand::Execute( const String& arg )
{
	Console* con = (Console*)_console;
	if ( arg.IsEmpty() )
	{
		con->Print( _syntax );
		return;
	}

	const UInt count = arg.EntryCount( L' ' );
	if ( count > 2 )
	{
		con->Print( _syntax );
		return;
	}

	String arg0 = arg.Entry( 0, L' ' );
	String arg1;
	Color color;
	switch ( count )
	{
		case 1:
			if ( arg0.EqualsTo(L"text", true) )
			{
				_console->GetTextColor( color );
			}
			else if ( arg0.EqualsTo(L"theme", true) )
			{
				con->GetUi()->GetTheme()->GetWidgetColor( WidgetState::Normal, color );
			}
			else
			{
				con->Print( _syntax );
				return;
			}
			con->Print( String::Format(L"color: {0}", color.ToString()) );
			break;

		case 2:
			arg1 = arg.Entry( 1, L' ' );
			color = Color( arg1 );
			if ( color == Color::Transparent )
			{
				_console->Echo( String::Format(L"Unknown color: {0}", arg1) );
				return;
			}

			if ( arg0.EqualsTo(L"text", true) )
			{
				_console->SetTextColor( color );
			}
			else if ( arg0.EqualsTo(L"theme", true) )
			{
				con->GetUi()->GetTheme()->SetWidgetColor( WidgetState::Normal, color );
				con->GetUi()->GetTheme()->SetWidgetColor( WidgetState::Active, color*1.4f );
				con->GetUi()->GetTheme()->SetWidgetColor( WidgetState::Hovered, color*1.5f );
			}
			else
			{
				con->Print( _syntax );
				return;
			}
			_console->Echo( String::Format(L"color: {0}", color.ToString()) );
			break;
	}
}


} // cons


} // synkro
