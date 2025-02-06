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
// Purpose: Defines extended graphics system.
//==============================================================================
#ifndef _SYNKRO_GFX_IGRAPHICSSYSTEMEX_
#define _SYNKRO_GFX_IGRAPHICSSYSTEMEX_


#include "config.h"
#include <gfx/IGraphicsSystem.h>
#include <gfx/GraphicsStats.h>
#include <img/PixelFormat.h>


namespace synkro
{


namespace gfx
{


/**
 * Extended graphics system.
 */
iface IGraphicsSystemEx :
	public IGraphicsSystem
{
public:
	/**
	 * Creates customizable data format.
	 * @return Created data format.
	 */
	virtual IDataFormatEx*									CreateDataFormat() = 0;

	/**
	 * Creates overlay rendering queue.
	 * @param width Overlay width.
	 * @param height Overlay height.
	 * @return Created rendering queue.
	 */
	virtual IOverlayRenderQueue*							CreateRenderQueue( UInt width, UInt height ) = 0;

	/**
	 * Creates scene rendering queue.
	 * @return Created rendering queue.
	 */
	virtual ISceneRenderQueue*								CreateRenderQueue() = 0;

	/**
	 * Creates overlay rendering map.
	 * @param queue Source rendering queue.
	 * @param target Color rendering target.
	 * @return Created rendering map.
	 * @exception BadArgumentException queue is null.
	 * @exception BadArgumentException target is null.
	 */
	virtual IPlainRenderMap*								CreateRenderMap( IOverlayRenderQueue* queue, IPlainRenderTexture* target ) = 0;

	/**
	 * Creates plain rendering map.
	 * @param queue Source rendering queue.
	 * @param colorTarget Color rendering target.
	 * @param depthTarget Depth rendering target.
	 * @return Created rendering map.
	 * @exception BadArgumentException queue is null.
	 * @exception BadArgumentException colorTarget is null.
	 * @exception BadArgumentException depthTarget is null.
	 */
	virtual IPlainRenderMap*								CreateRenderMap( ISceneRenderQueue* queue, IPlainRenderTexture* colorTarget, IPlainDepthTexture* depthTarget ) = 0;

	/**
	 * Creates cube rendering map.
	 * @param queue Source rendering queue.
	 * @param colorTarget Color rendering target.
	 * @param depthTarget Depth rendering target.
	 * @return Created rendering map.
	 * @exception BadArgumentException queue is null.
	 * @exception BadArgumentException colorTarget is null.
	 * @exception BadArgumentException depthTarget is null.
	 */
	virtual ICubeRenderMap*									CreateRenderMap( ISceneRenderQueue* queue, ICubeRenderTexture* colorTarget, ICubeDepthTexture* depthTarget ) = 0;

	/**
	 * Creates virtual rendering window.
	 * @param width Window width.
	 * @param height Window height.
	 * @param format Pixel format.
	 * @param sampleCount Number of samples per texel.
	 * @param sampleQuality Image quality level.
	 * @return Created window.
	 */
	virtual IVirtualRenderWindow*							CreateRenderWindow( UInt width, UInt height, const img::PixelFormat& format, UInt sampleCount, UInt sampleQuality ) = 0;

	/**
	 * Retrieves program by name.
	 * @param name Program unique name.
	 * @return Requested program, if one exists, nullptr otherwise.
	 */
	virtual IProgram*										GetProgram( const lang::String& name ) const = 0;

	/**
	 * Retrieves the total number of created graphics devices.
	 */
	virtual UInt											GetDeviceCount() const = 0;

	/**
	 * Retrieves created graphics device by index.
	 * @param index Index of the graphics device to retrieve.
	 * @return Requested graphics device.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IGraphicsDeviceEx*								GetDevice( UInt index ) const = 0;

	/**
	 * Retrieves default graphics device.
	 * @return Default graphics device.
	 */
	virtual IGraphicsDeviceEx*								GetDevice() const = 0;

	/**
	 * Retrieves the total number of frame windows.
	 */
	virtual UInt											GetFrameWindowCount() const = 0;

	/**
	 * Retrieves frame window by index.
	 * @param index Window index.
	 * @return Requested window.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IFrameRenderWindowEx*							GetFrameWindow( UInt index ) const = 0;

	/**
	 * Retrieves the total number of view windows.
	 */
	virtual UInt											GetViewWindowCount() const = 0;

	/**
	 * Retrieves view window by index.
	 * @param index Window index.
	 * @return Requested window.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IViewRenderWindowEx*							GetViewWindow( UInt index ) const = 0;

	/**
	 * Retrieves the total number of virtual windows.
	 */
	virtual UInt											GetVirtualWindowCount() const = 0;

	/**
	 * Retrieves virtual window by index.
	 * @param index Window index.
	 * @return Requested window.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IVirtualRenderWindow*							GetVirtualWindow( UInt index ) const = 0;

	/**
	 * Retrieves system statistics.
	 */
	virtual void											GetStats( GraphicsStats& stats ) const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IGRAPHICSSYSTEMEX_
