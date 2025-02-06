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
// Purpose: Defines rasterizer state.
//==============================================================================
#ifndef _SYNKRO_GFX_IRASTERIZERSTATE_
#define _SYNKRO_GFX_IRASTERIZERSTATE_


#include "config.h"
#include <gfx/IRenderState.h>
#include <gfx/CullMode.h>
#include <gfx/FillMode.h>


namespace synkro
{


namespace gfx
{


/**
 * Rasterizer state.
 */
iface IRasterizerState :
	public IRenderState
{
public:
	/**
	 * Sets face culling mode. Default is Back.
	 * @param cull Culling mode.
	 */
	virtual void											SetCullMode( const CullMode& cull ) = 0;

	/**
	 * Sets face filling mode. Default is Solid.
	 * @param fill Filling mode.
	 */
	virtual void											SetFillMode( const FillMode& fill ) = 0;

	/**
	 * Sets depth value added to a pixel. Default is 0.0f.
	 * @param bias Depth bias value.
	 */
	virtual void											SetDepthBias( Float bias ) = 0;

	/**
	 * Sets the maximum depth bias of a pixel. Default is 0.0f.
	 * @param clamp Depth clamp value.
	 */
	virtual void											SetDepthBiasClamp( Float clamp ) = 0;

	/**
	 * Sets a scalar on a given pixel's slope. Default is 0.0f.
	 * @param bias Depth dias value.
	 */
	virtual void											SetSlopeScaledDepthBias( Float bias ) = 0;

	/**
	 * Turns scissor test on or off. Default is false.
	 * @param enable True to enable scissor test, false to disable it.
	 */
	virtual void											EnableScissor( Bool enable ) = 0;

	/**
	 * Turns multisample antialiasing on or off. Default is false.
	 * @param enable True to enable multisample antialiasing, false to disable it.
	 */
	virtual void											EnableMultisample( Bool enable ) = 0;

	/**
	 * Turns line antialiasing on or off. Valid only if multisampling is off. Default is false.
	 * @param enable True to enable line antialiasing, false to disable it.
	 */
	virtual void											EnableAntialiasing( Bool enable ) = 0;

	/**
	 * Retrieves face culling mode.
	 */
	virtual CullMode										GetCullMode() const = 0;

	/**
	 * Retrieves face filling mode.
	 */
	virtual FillMode										GetFillMode() const = 0;

	/**
	 * Retrieves depth value added to a given pixel.
	 */
	virtual Float											GetDepthBias() const = 0;

	/**
	 * Retrieves maximum depth bias of a pixel.
	 */
	virtual Float											GetDepthBiasClamp() const = 0;

	/**
	 * Retrieves a scalar on a given pixel's slope.
	 */
	virtual Float											GetSlopeScaledDepthBias() const = 0;

	/**
	 * Indicates whether the scissor test is on or off.
	 */
	virtual Bool											IsScissorEnabled() const = 0;

	/**
	 * Indicates whether the multisample antialiasing is on or off.
	 */
	virtual Bool											IsMultisampleEnabled() const = 0;

	/**
	 * Indicates whether the line antialiasing is on or off.
	 */
	virtual Bool											IsAntialiasingEnabled() const = 0;

	/**
	 * Produces an exact copy of rasterizer state.
	 * @return Newly created rasterizer state.
	 */
	virtual IRasterizerState*								Clone() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IRASTERIZERSTATE_
