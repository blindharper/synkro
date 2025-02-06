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
#include "config.h"
#include "FactoryTable.h"


namespace synkro
{


namespace core
{


FactoryTable::FactoryTable() :
	_factories( A(FactoryListEntry) )
{
}

void FactoryTable::Add( const Iface& name, FactoryList& list )
{
	_factories[name] = list;
}

FactoryList& FactoryTable::Get( const Iface& name )
{
	return _factories[name];
}

const FactoryList& FactoryTable::Get( const Iface& name ) const
{
	return _factories[name];
}

Bool FactoryTable::Exists( const Iface& name ) const
{
	return _factories.ContainsKey( name );
}


} // core


} // synkro
