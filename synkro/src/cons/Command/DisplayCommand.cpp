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
// Purpose: "Display" console command.
//==============================================================================
#include "config.h"
#include "DisplayCommand.h"
#include <cons/Console.h>
#include <gfx/IGraphicsSystemEx.h>
#include <gfx/IFrameRenderWindowEx.h>


//------------------------------------------------------------------------------

using namespace synkro::gfx;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace cons
{


DisplayCommand::DisplayCommand( IConsole* console, const String& description, const String& syntax ) :
	ConsoleCommandImpl<IConsoleCommand>( console, description, syntax )
{
}

void DisplayCommand::Execute( const String& arg )
{
	DisplayMode displayMode;
	Console* con = (Console*)_console;
	IGraphicsSystemEx* graphicsSystem = con->GetGraphicsSystem();

	if ( arg.IsEmpty() )
	{
		// Print current display mode.		
		graphicsSystem->GetFrameWindow( 0 )->GetDisplayMode( displayMode );
		con->Print( displayMode.ToString(DisplayModeFormat::Complete) );
	}
	else if ( arg.EqualsTo(L"toggle", true) )
	{
		// Toggle fullscreen.
		graphicsSystem->GetFrameWindow( 0 )->GetDisplayMode( displayMode );
		displayMode.Fullscreen = !displayMode.Fullscreen;
		graphicsSystem->GetFrameWindow( 0 )->SetDisplayMode( displayMode );
		_console->Echo( displayMode.ToString(DisplayModeFormat::Complete) );
	}
	else
	{
		// Set new display mode.
		const UInt count = arg.EntryCount( L' ' );
		if ( count > 2 )
		{
			con->Print( _syntax );
			return;
		}
		
		String arg0 = arg.Entry( 0, L' ' );
		String arg1;
		Bool fullscreen = false;
		switch ( count )
		{
			case 1:
				graphicsSystem->GetFrameWindow( 0 )->GetDisplayMode( displayMode );
				fullscreen = displayMode.Fullscreen;
				break;

			case 2:
				arg1 = arg.Entry( 1, L' ' );
				if ( arg1.EqualsTo(L"full", true) || arg1.EqualsTo(L"fullscreen", true) )
				{
					fullscreen = true;
				}
				else if ( !arg1.EqualsTo(L"win", true) && !arg1.EqualsTo(L"windowed", true) )
				{
					con->Print( _syntax );
					return;
				}
				break;
		}

		try
		{
			if ( arg0.EqualsTo(L"Min", true) || arg0.EqualsTo(L"Minimum", true) )
				displayMode = DisplayMode::Minimum;
			else if ( arg0.EqualsTo(L"BelowMedium", true) )
				displayMode = DisplayMode::BelowMedium;
			else if ( arg0.EqualsTo(L"Med", true) || arg0.EqualsTo(L"Medium", true) )
				displayMode = DisplayMode::Medium;
			else if ( arg0.EqualsTo(L"AboveMedium", true) )
				displayMode = DisplayMode::AboveMedium;
			else if ( arg0.EqualsTo(L"Max", true) || arg0.EqualsTo(L"Maximum", true) )
				displayMode = DisplayMode::Maximum;
			else
				displayMode = DisplayMode( arg0, fullscreen );

			displayMode.Fullscreen = fullscreen;
			graphicsSystem->GetFrameWindow( 0 )->SetDisplayMode( displayMode );
			_console->Echo( displayMode.ToString(DisplayModeFormat::Complete) );
		}
		catch ( const Exception& ex )
		{
			con->Print( ex.Message() );
		}
	}
}


} // cons


} // synkro
