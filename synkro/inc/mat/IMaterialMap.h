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
// Purpose: Defines base map.
//==============================================================================
#ifndef _SYNKRO_MAT_IMATERIALMAP_
#define _SYNKRO_MAT_IMATERIALMAP_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>


namespace synkro
{


namespace mat
{


/**
 * Base map.
 */
iface IMaterialMap :
	public core::IObject
{
public:
	/**
	 * Sets map image.
	 * @param image Map image.
	 * @exception BadArgumentException Image format is not suitable for this particular map.
	 */
	virtual void											SetImage( img::IImage* image ) = 0;

	/**
	 * Sets map strength. Valid range is [0.0 - 1.0]
	 * @param amount Map strength.
	 */
	virtual void											SetAmount( Float amount ) = 0;

	/**
	 * Sets optional map name.
	 * @param name Map name.
	 */
	virtual void											SetName( const lang::String& name ) = 0;

	/**
	 * Retrieves map image.
	 */
	virtual img::IImage*									GetImage() const = 0;

	/**
	 * Retrieves map strength.
	 */
	virtual Float											GetAmount() const = 0;

	/**
	 * Retrieves map name.
	 */
	virtual lang::String									GetName() const = 0;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_IMATERIALMAP_
