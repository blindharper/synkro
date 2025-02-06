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
// Purpose: Defines triangle mesh list.
//==============================================================================
#ifndef _SYNKRO_CORE_ITRIANGLEMESHLIST_
#define _SYNKRO_CORE_ITRIANGLEMESHLIST_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace core
{


/**
 * Triangle mesh list.
 */
iface ITriangleMeshList :
	public IObject
{
public:
	/**
	 * Sets list size.
	 * @param size New list size.
	 */
	virtual void											SetSize( UInt size ) = 0;

	/**
	 * Adds mesh to the end of the list.
	 * @param mesh Mesh to add.
	 */
	virtual void											Add( scene::ITriangleMesh* mesh ) = 0;

	/**
	 * Sets mesh in the list by index.
	 * @param index Index of the mesh to set.
	 * @param mesh Mesh to set.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											Set( UInt index, scene::ITriangleMesh* mesh ) = 0;

	/**
	 * Retrieves list size.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Returns mesh in the list by index.
	 * @param index Index of the mesh to return.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual scene::ITriangleMesh*							Get( UInt index ) const = 0;
};


} // core


} // synkro


#endif // _SYNKRO_CORE_ITRIANGLEMESHLIST_
