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
// Purpose: Defines resource table.
//==============================================================================
#include "config.h"
#include "ResourceTable.h"


namespace synkro
{


namespace core
{


ResourceTable::ResourceTable() :
	_resources( A(ResourceListEntry) )
{
}

void ResourceTable::Add( const ResourceType& type, ResourceList& list )
{
	_resources[type] = list;
}

ResourceList& ResourceTable::Get( const ResourceType& type )
{
	return _resources[type];
}

const ResourceList& ResourceTable::Get( const ResourceType& type ) const
{
	return _resources[type];
}

Bool ResourceTable::Exists( const ResourceType& type ) const
{
	return _resources.ContainsKey( type );
}


} // core


} // synkro
