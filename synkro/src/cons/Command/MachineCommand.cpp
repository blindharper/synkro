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
// Purpose: "Machine" console command.
//==============================================================================
#include "config.h"
#include "MachineCommand.h"
#include <cons/Console.h>
#include <script/IScriptSystemEx.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::script;

//------------------------------------------------------------------------------


namespace synkro
{


namespace cons
{


MachineCommand::MachineCommand( IConsole* console, const String& description, const String& syntax ) :
	ConsoleCommandImpl<IConsoleCommand>( console, description, syntax )
{
}

void MachineCommand::Execute( const String& arg )
{
	Console* con = (Console*)_console;

	if ( arg.IsEmpty() )
	{
		const IScriptMachine* machine = con->GetScriptMachine();
		if ( machine != nullptr )
		{
			con->Print( String::Format(L"Current script machine: {0}", (machine != nullptr) ? machine->GetName() : L"<none>") );
		}
	}
	else
	{
		String nameIndex( arg );
		if ( con->GetScriptSystem() != nullptr )
		{
			if ( nameIndex.IsInteger() )
			{
				const UInt index = CastUInt( nameIndex.ToInteger() );
				if ( index < con->GetScriptSystem()->GetMachineCount() )
				{
					IScriptMachine* machine = con->GetScriptSystem()->GetMachine( index );
					con->SetScriptMachine( machine );
					con->Print( String::Format(L"Script machine switched to {0,q}", machine->GetName()) );
				}
				else
				{
					con->Print( L"Invalid script machine index" );
				}
			}
			else
			{
				IScriptMachine* machine = con->GetScriptSystem()->GetMachine( nameIndex );
				if ( machine != nullptr )
				{
					con->SetScriptMachine( machine );
					con->Print( String::Format(L"Script machine switched to {0,q}", machine->GetName()) );
				}
				else
				{
					con->Print( L"Unknown script machine" );
				}
			}
		}
		else
		{
			con->Print( L"Scripting system is disabled" );
		}
	}
}


} // cons


} // synkro
