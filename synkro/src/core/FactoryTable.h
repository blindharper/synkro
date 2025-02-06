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
// Purpose: Defines factory table.
//==============================================================================
#ifndef _SYNKRO_CORE_FACTORYTABLE_
#define _SYNKRO_CORE_FACTORYTABLE_


#include "config.h"
#include "FactoryList.h"
#include <lang/Map.h>


namespace synkro
{


namespace core
{


// Table of FactoryList.
class FactoryTable
{
public:
	// Constructor.
	FactoryTable();

	// Methods.
	void													Add( const Iface& name, FactoryList& list );
	FactoryList&											Get( const Iface& name );
	const FactoryList&										Get( const Iface& name ) const;
	Bool													Exists( const Iface& name ) const;

private:
	typedef lang::MapPair<UInt, FactoryList>				FactoryListEntry;

	lang::Map<UInt, FactoryList>							_factories;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_FACTORYTABLE_
