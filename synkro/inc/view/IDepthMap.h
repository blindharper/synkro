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
// Purpose: Defines depth map.
//==============================================================================
#ifndef _SYNKRO_VIEW_IDEPTHMAP_
#define _SYNKRO_VIEW_IDEPTHMAP_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace view
{


/**
 * Depth map.
 */
iface IDepthMap :
	public core::IObject
{
public:
	/**
	 * Retrieves map width.
	 */
	virtual UInt											GetWidth() const = 0;

	/**
	 * Retrieves map height.
	 */
	virtual UInt											GetHeight() const = 0;

	/**
	 * Retrieves underlying graphics resource.
	 */
	virtual gfx::IResource*									GetResource() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IDEPTHMAP_
