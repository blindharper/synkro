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
// Purpose: Defines scene node list.
//==============================================================================
#ifndef _SYNKRO_CORE_INODELIST_
#define _SYNKRO_CORE_INODELIST_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace core
{


/**
 * Scene node list.
 */
iface INodeList :
	public IObject
{
public:
	/**
	 * Sets list size.
	 * @param size New list size.
	 */
	virtual void											SetSize( UInt size ) = 0;

	/**
	 * Adds node to the end of the list.
	 * @param node Node to add.
	 */
	virtual void											Add( scene::INode* node ) = 0;

	/**
	 * Sets node in the list by index.
	 * @param index Index of the node to set.
	 * @param node Node to set.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											Set( UInt index, scene::INode* node ) = 0;

	/**
	 * Retrieves list size.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Returns node in the list by index.
	 * @param index Index of the node to return.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual scene::INode*									Get( UInt index ) const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_INODELIST_
