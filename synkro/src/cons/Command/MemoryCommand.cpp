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
// Purpose: "Memory" console command.
//==============================================================================
#include "config.h"
#include "MemoryCommand.h"
#include <mem/MemoryManager.h>
#include <cons/IConsole.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;
using namespace synkro::mem;

//------------------------------------------------------------------------------


namespace synkro
{


namespace cons
{


MemoryCommand::MemoryCommand( IConsole* console, const String& description, const String& syntax ) :
	ConsoleCommandImpl<IConsoleCommand>( console, description, syntax )
{
}

void MemoryCommand::Execute( const String& arg )
{
	MemoryStats stats;
	MemoryManager::GetStats( stats );

	constexpr Float MB = 1024.0f*1024.0f;
	const Float used = CastFloat(stats.UsedByteCount/MB);
	const Float maximum = CastFloat(stats.MaximumByteCount/MB);
	const Float total = CastFloat(stats.TotalByteCount/MB);

	Print( String::Format(L"Used: {0,#.00} Mb, Maximum: {1,#.00} Mb, Total: {2,#.00} Mb", used, maximum, total) );
}


} // cons


} // synkro
