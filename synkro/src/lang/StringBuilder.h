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
// Purpose: Mutable string.
//==============================================================================
#ifndef _SYNKRO_LANG_STRINGBUILDER_
#define _SYNKRO_LANG_STRINGBUILDER_


#include "config.h"
#include <lang/String.h>
#include <lang/Vector.h>


namespace synkro
{


namespace lang
{


// String builder.
class SYNKRO_API StringBuilder
{
public:
	// Constructor.
	StringBuilder();

	// Methods.
	void													Clear();
	void													Append( Char ch );
	void													Append( const Char* text );
	void													Append( const lang::String& text );
	void													Append( Double number, UInt precision );
	void													Append( Double number );
	void													Append( UInt number );
	String													GetString();
	UInt													GetLength() const;

private:
	Vector<Char>											_buffer;
};


} // lang


} // synkro


#endif // _SYNKRO_LANG_STRINGBUILDER_
