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
// Purpose: Defines string list.
//==============================================================================
#ifndef _SYNKRO_CORE_ISTRINGLIST_
#define _SYNKRO_CORE_ISTRINGLIST_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>


namespace synkro
{


namespace core
{


/**
 * String list.
 */
iface IStringList :
	public IObject
{
public:
	/**
	 * Retrieves list size.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Returns string in the list by index.
	 * @param index Index of the string to return.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual lang::String									Get( UInt index ) const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_ISTRINGLIST_
