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
// Purpose: "Version" console command.
//==============================================================================
#include "config.h"
#include "VersionCommand.h"
#include <cons/Console.h>
#include <core/Version.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace cons
{


VersionCommand::VersionCommand( IConsole* console, const String& description, const String& syntax ) :
	ConsoleCommandImpl<IConsoleCommand>( console, description, syntax )
{
}

void VersionCommand::Execute( const String& arg )
{
	Print( Version::Current.ToString() );
}


} // cons


} // synkro
