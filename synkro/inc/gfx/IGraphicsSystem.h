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
// Purpose: Defines abstract graphics system.
//==============================================================================
#ifndef _SYNKRO_GFX_IGRAPHICSSYSTEM_
#define _SYNKRO_GFX_IGRAPHICSSYSTEM_


#include "config.h"
#include <core/ISystem.h>
#include <gfx/GraphicsDeviceDesc.h>


namespace synkro
{


namespace gfx
{


/**
 * Abstract graphics system.
 */
iface IGraphicsSystem :
	public core::ISystem
{
public:
	/**
	 * Initializes one of the devices installed in the system.
	 * @param index Index of the graphics device to intialize.
	 * @return Created graphics device.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IGraphicsDevice*								CreateDevice( UInt index ) = 0;

	/**
	 * Retrieves the total number of graphics devices installed in the system.
	 */
	virtual UInt											GetTotalDeviceCount() const = 0;

	/**
	 * Retrieves device description by index.
	 * @param index Index of the device.
	 * @param [out] desc Device description.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual void											GetDeviceDesc( UInt index, GraphicsDeviceDesc& desc ) const = 0;

	/** 
	 * Retrieves factory interface identifier.
	 * @return Interface identifier.
	 */
	virtual lang::String									GetName() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IGRAPHICSSYSTEM_
