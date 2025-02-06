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
template <class T>
SYNKRO_INLINE ConsoleCommandImpl<T>::ConsoleCommandImpl( IConsole* console, const lang::String& description, const lang::String& syntax ) :
	_console( console ),
	_baseConsole( AsBaseConsole(console) ),
	_description( description ),
	_syntax( syntax )
{
}

template <class T>
SYNKRO_INLINE ConsoleCommandImpl<T>::~ConsoleCommandImpl()
{
}

template <class T>
SYNKRO_INLINE lang::String ConsoleCommandImpl<T>::GetDescription() const
{
	return _description;
}

template <class T>
SYNKRO_INLINE lang::String ConsoleCommandImpl<T>::GetSyntax() const
{
	return _syntax;
}

template <class T>
SYNKRO_INLINE void ConsoleCommandImpl<T>::Print( const lang::String& text )
{
	_baseConsole->Print( text );
}
