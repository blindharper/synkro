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
#ifndef _SYNKRO_CORE_RESOURCETABLE_
#define _SYNKRO_CORE_RESOURCETABLE_


#include "config.h"
#include "ResourceList.h"
#include <core/ResourceType.h>
#include <lang/Map.h>


namespace synkro
{


namespace core
{


// Table of ResourceList.
class ResourceTable
{
public:
	// Constructor.
	ResourceTable();

	// Methods.
	void													Add( const ResourceType& type, ResourceList& list );
	ResourceList&											Get( const ResourceType& type );
	const ResourceList&										Get( const ResourceType& type ) const;
	Bool													Exists( const ResourceType& type ) const;

private:
	typedef lang::MapPair<ResourceType, ResourceList>		ResourceListEntry;

	lang::Map<ResourceType, ResourceList>					_resources;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_RESOURCETABLE_
