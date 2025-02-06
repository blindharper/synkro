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
#include "config.h"
#include "ClearCommand.h"
#include <cons/IConsole.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace cons
{


ClearCommand::ClearCommand( IConsole* console, const String& description, const String& syntax ) :
	ConsoleCommandImpl<IConsoleCommand>( console, description, syntax )
{
}

void ClearCommand::Execute( const String& arg )
{
	_console->Clear();
}


} // cons


} // synkro
