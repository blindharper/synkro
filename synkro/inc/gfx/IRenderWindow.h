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
// Purpose: Defines rendering window.
//==============================================================================
#ifndef _SYNKRO_GFX_IRENDERWINDOW_
#define _SYNKRO_GFX_IRENDERWINDOW_


#include "config.h"
#include <core/IObject.h>
#include <img/PixelFormat.h>
#include <math/Vector4.h>


namespace synkro
{


namespace gfx
{


/**
 * Rendering window.
 */
iface IRenderWindow :
	public core::IObject
{
public:
	/**
	 * Binds window to the pipeline.
	 * @return True, if the window has been successfully bound, false otherwise.
	 */
	virtual Bool											Bind() = 0;

	/**
	 * Clears window's color buffer with the default color.
	 */
	virtual void											Clear() = 0;

	/**
	 * Presents rendering results to the window.
	 * @return True, if succeded, false otherwise.
	 */
	virtual Bool											Present() = 0;

	/**
	 * Sets color used to clear window's color buffer.
	 * @param color Default color value.
	 */
	virtual void											SetDefaultColor( const math::Vector4& color ) = 0;

	/**
	 * Retrieves color used to clear window's color buffer.
	 * @param [out] color Default color value.
	 */
	virtual void											GetDefaultColor( math::Vector4& color ) const = 0;

	/**
	 * Retrieves window's pixel format for client.
	 */
	virtual img::PixelFormat								GetClientPixelFormat() const = 0;

	/**
	 * Retrieves window's internal pixel format.
	 */
	virtual img::PixelFormat								GetPixelFormat() const = 0;

	/**
	 * Retrieves window width.
	 */
	virtual UInt											GetWidth() const = 0;

	/**
	 * Retrieves window height.
	 */
	virtual UInt											GetHeight() const = 0;

	/**
	 * Retrieves window sample count.
	 */
	virtual UInt											GetSampleCount() const = 0;

	/**
	 * Retrieves device that created the window.
	 */
	virtual IGraphicsDevice*								GetDevice() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRENDERWINDOW_
