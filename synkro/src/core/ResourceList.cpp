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
#include "config.h"
#include "ResourceList.h"
#include <lang/OutOfRangeException.h>


//------------------------------------------------------------------------------

using namespace synkro::io;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


ResourceList::ResourceList() :
	_items( A(ResourceItem) )
{
}

void ResourceList::AddResource( IResource* resource )
{
	_items.Add( resource );
}

UInt ResourceList::GetResourceCount() const
{
	return _items.Size();
}

IResource* ResourceList::GetResource( UInt index ) const
{
	assert( index < _items.Size() );

	if ( index >= _items.Size()	 )
		throw OutOfRangeException( index, _items.Size() );

	return _items[index].Resource;
}

IResource* ResourceList::GetResourceById( UInt id ) const
{
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		if ( _items[i].Resource->ID() == id )
			return _items[i].Resource;
	}

	return nullptr;
}

IStreamDirectory* ResourceList::LoadResource( UInt index )
{
	assert( index < _items.Size() );

	if ( index >= _items.Size()	 )
		throw OutOfRangeException( index, _items.Size() );

	if ( _items[index].Directory == nullptr )
	{
		_items[index].Directory = _items[index].Resource->Load();
	}

	return _items[index].Directory;
}


} // core


} // synkro
