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
// Purpose: Defines base object interface.
//==============================================================================
#ifndef _SYNKRO_CORE_IOBJECT_
#define _SYNKRO_CORE_IOBJECT_


#include "config.h"


namespace synkro
{


namespace core
{


/**
 * Base object interface.
 * Other interfaces should be inherited from IObject.
 * Multiple interface inheritance is not allowed.
 */
iface IObject
{
public:
	/**
	 * Increments object reference count by one.
	 * @return Object reference count.
	 */
	virtual Int												AddRef() = 0;

	/**
	 * Decrements object reference count by one and destroys the object if its reference count zeroes.
	 * @return Object reference count.
	 */
	virtual Int												Release() = 0;

	/**
	 * Returns internal object identifier.
	 */
	virtual UInt											ID() const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_IOBJECT_
