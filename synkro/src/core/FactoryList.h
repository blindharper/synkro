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
#ifndef _SYNKRO_CORE_FACTORYLIST_
#define _SYNKRO_CORE_FACTORYLIST_


#include "config.h"
#include <core/IFactory.h>
#include <lang/Vector.h>


namespace synkro
{


namespace core
{


// Collection of IFactory.
class FactoryList
{
public:
	// Constructor.
	FactoryList();

	// Methods.
	void													AddFactory( IFactory* factory );
	UInt													GetFactoryCount() const;
	IFactory*												GetFactory( UInt index ) const;
	IFactory*												GetFactory( const lang::Enum& name ) const;

private:
	lang::Vector<IFactory*>									_items;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_FACTORYLIST_
