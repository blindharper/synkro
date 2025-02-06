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
// Purpose: Defines resource list.
//==============================================================================
#ifndef _SYNKRO_CORE_RESOURCELIST_
#define _SYNKRO_CORE_RESOURCELIST_


#include "config.h"
#include <io/IStreamDirectory.h>
#include <core/IResource.h>
#include <lang/Vector.h>
#include <lang/Ptr.h>


namespace synkro
{


namespace core
{


// Collection of IResource.
class ResourceList
{
public:
	// Constructor.
	ResourceList();

	// Methods.
	void													AddResource( IResource* resource );
	UInt													GetResourceCount() const;
	IResource*												GetResource( UInt index ) const;
	IResource*												GetResourceById( UInt id ) const;
	io::IStreamDirectory*									LoadResource( UInt index );

private:
	struct ResourceItem
	{
		ResourceItem( IResource* resource ) :
			Directory( nullptr ),
			Resource( resource )
		{
		}

		ResourceItem() :
			Directory( nullptr ),
			Resource( nullptr )
		{
		}

		IResource*				Resource;
		P(io::IStreamDirectory) Directory;
	};

	lang::Vector<ResourceItem>								_items;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_RESOURCELIST_
