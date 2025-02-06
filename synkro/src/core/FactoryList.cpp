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
// Purpose: Defines factory list.
//==============================================================================
#include "config.h"
#include "FactoryList.h"
#include <lang/OutOfRangeException.h>


//------------------------------------------------------------------------------

using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace core
{


FactoryList::FactoryList() :
	_items( A(IFactory*) )
{
}

void FactoryList::AddFactory( IFactory* factory )
{
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		if ( _items[i]->GetClassID() == factory->GetClassID() )
		{
			_items[i] = factory;
			return;
		}
	}
	_items.Add( factory );
}

UInt FactoryList::GetFactoryCount() const
{
	return _items.Size();
}

IFactory* FactoryList::GetFactory( UInt index ) const
{
	assert( index < _items.Size() );

	if ( index >= _items.Size()	 )
		throw OutOfRangeException( index, _items.Size() );

	return _items[index];
}

IFactory* FactoryList::GetFactory( const lang::Enum& name ) const
{
	for ( UInt i = 0; i < _items.Size(); ++i )
	{
		if ( _items[i]->GetClassID() == name )
			return _items[i];
	}
	return nullptr;
}


} // core


} // synkro
