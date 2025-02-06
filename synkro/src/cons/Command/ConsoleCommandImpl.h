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
// Purpose: Generic console command implementation.
//==============================================================================
#ifndef _SYNKRO_CONS_CONSOLECOMMANDIMPL_
#define _SYNKRO_CONS_CONSOLECOMMANDIMPL_


#include "config.h"
#include <core/ObjectImpl.h>
#include <cons/IConsole.h>
#include <cons/BaseConsole.h>


namespace synkro
{


namespace cons
{


// Generic console command implementation.
template <class T>
class ConsoleCommandImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructors & destructors.
	ConsoleCommandImpl( IConsole* console, const lang::String& description, const lang::String& syntax );
	virtual ~ConsoleCommandImpl();

	// IConsoleCommand methods.
	virtual lang::String									GetDescription() const;
	virtual lang::String									GetSyntax() const;

protected:
	IConsole*												_console;
	BaseConsole*											_baseConsole;
	lang::String											_description;
	lang::String											_syntax;

	void													Print( const lang::String& text );
};


#include "ConsoleCommandImpl.inl"


} // cons


} // synkro


#endif // _SYNKRO_CONS_CONSOLECOMMANDIMPL_
