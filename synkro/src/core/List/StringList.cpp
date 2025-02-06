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
// Purpose: String list implementation.
//==============================================================================
#include "config.h"
#include "StringList.h"


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


StringList::StringList( const String& str, Char delim ) :
	_strings( A(String) )
{
	Vector<Char> buffer( A(Char) );

	for ( UInt i = 0; i < str.Length(); ++i )
	{
		const Char ch = str[i];
		if ( ch == delim )
		{
			buffer.Add( L'\0' );
			_strings.Add( String(buffer.Begin()) );
			buffer.Clear();
			continue;
		}
		buffer.Add( ch );
	}

	if ( buffer.Size() > 0 )
	{
		buffer.Add( L'\0' );
		_strings.Add( String(buffer.Begin()) );
		buffer.Clear();
	}
	else if ( _strings.IsEmpty() )
	{
		_strings.Add( String::Empty );
	}
}


} // core


} // synkro
