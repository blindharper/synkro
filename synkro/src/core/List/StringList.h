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
#ifndef _SYNKRO_CORE_STRINGLIST_
#define _SYNKRO_CORE_STRINGLIST_


#include "config.h"
#include <core/ObjectImpl.h>
#include <core/IStringList.h>
#include <lang/Vector.h>


namespace synkro
{


namespace core
{


// String list.
class StringList :
	public ObjectImpl<IStringList>
{
public:
	// Constructor.
	StringList( const lang::String& str, Char delim );

	// IStringList methods.
	UInt													GetSize() const;
	lang::String											Get( UInt index ) const;

private:
	lang::Vector<lang::String>								_strings;
};


#include "StringList.inl"


} // core


} // synkro


#endif // _SYNKRO_CORE_STRINGLIST_
