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
// Purpose: Defines resource set.
//==============================================================================
#ifndef _SYNKRO_GFX_IRESOURCESET_
#define _SYNKRO_GFX_IRESOURCESET_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace gfx
{


/**
 * Resource collection.
 */
iface IResourceSet :
	public core::IObject
{
public:
	/**
	 * Binds resources to the pipeline.
	 */
	virtual void											Bind() = 0;

	/**
	 * Unbinds resources from the pipeline.
	 */
	virtual void											Unbind() = 0;

	/**
	 * Sets resource at the given index.
	 * @param index Resource index.
	 * @param resource Resource to set.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											Set( UInt index, IResource* resource ) = 0;

	/**
	 * Retrieves the total number of resources in the set.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Retrieves resource by index.
	 * @param index Resource index.
	 * @return Requested resource.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IResource*										Get( UInt index ) const = 0;

	/**
	 * Produces an exact copy of resource set.
	 * @param ownerID Identifer of the owner. An owner is the object invoking resource set's methods.
	 * @return Newly created resource set.
	 */
	virtual IResourceSet*									Clone( UInt ownerID ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRESOURCESET_
