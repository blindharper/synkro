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
// Purpose: Defines blend state.
//==============================================================================
#ifndef _SYNKRO_GFX_IBLENDSTATE_
#define _SYNKRO_GFX_IBLENDSTATE_


#include "config.h"
#include <core/IObject.h>
#include <gfx/BlendMode.h>
#include <gfx/BlendOperation.h>
#include <img/PixelChannel.h>


namespace synkro
{


namespace gfx
{


/**
 * Blend state for a particular rendering target.
 */
iface IBlendState :
	public core::IObject
{
public:
	/**
	 * Turns blending on or off. Default is false.
	 * @param enable True to enable blending, false to disable it.
	 */
	virtual void											Enable( Bool enable ) = 0;

	/**
	 * Sets source blending mode for both color and alpha channels. Default is One.
	 * @param mode Blending mode.
	 */
	virtual void											SetSrcMode( const BlendMode& mode ) = 0;

	/**
	 * Sets source blending mode for color channels. Default is One.
	 * @param mode Blending mode.
	 */
	virtual void											SetColorSrcMode( const BlendMode& mode ) = 0;

	/**
	 * Sets source blending mode for alpha channel. Default is One.
	 * @param mode Blending mode.
	 */
	virtual void											SetAlphaSrcMode( const BlendMode& mode ) = 0;

	/**
	 * Sets destination blending mode for both color and alpha channels. Default is Zero.
	 * @param mode Blending mode.
	 */
	virtual void											SetDstMode( const BlendMode& mode ) = 0;

	/**
	 * Sets destination blending mode for color channels. Default is Zero.
	 * @param mode Blending mode.
	 */
	virtual void											SetColorDstMode( const BlendMode& mode ) = 0;

	/**
	 * Sets destination blending mode for alpha channel. Default is Zero.
	 * @param mode Blending mode.
	 */
	virtual void											SetAlphaDstMode( const BlendMode& mode ) = 0;

	/**
	 * Sets blending operation for both color and alpha channels. Default is Add.
	 * @param operation Blending operation.
	 */
	virtual void											SetOperation( const BlendOperation& operation ) = 0;

	/**
	 * Sets blending operation for color channels. Default is Add.
	 * @param operation Blending operation.
	 */
	virtual void											SetColorOperation( const BlendOperation& operation ) = 0;

	/**
	 * Sets blending operation for alpha channel. Default is Add.
	 * @param operation Blending operation.
	 */
	virtual void											SetAlphaOperation( const BlendOperation& operation ) = 0;

	/**
	 * Sets per-pixel write mask applied to values written into the rendering target. Default is All.
	 * @param channels Per-pixel write mask.
	 */
	virtual void											SetWriteChannels( const img::PixelChannel& channels ) = 0;

	/**
	 * Indicates whether the blending is enabled.
	 * @return True if blending is enabled, or false otherwise.
	 */
	virtual Bool											IsEnabled() const = 0;

	/**
	 * Retrieves source blending mode for color channels.
	 */
	virtual BlendMode										GetColorSrcMode() const = 0;

	/**
	 * Retrieves source blending mode for alpha channel.
	 */
	virtual BlendMode										GetAlphaSrcMode() const = 0;

	/**
	 * Retrieves destination blending mode for color channels.
	 */
	virtual BlendMode										GetColorDstMode() const = 0;

	/**
	 * Retrieves destination blending mode for alpha channel.
	 */
	virtual BlendMode										GetAlphaDstMode() const = 0;

	/**
	 * Retrieves blending operation for color channels.
	 */
	virtual BlendOperation									GetColorOperation() const = 0;

	/**
	 * Retrieves blending operation for alpha channel.
	 */
	virtual BlendOperation									GetAlphaOperation() const = 0;

	/**
	 * Retrieves per-pixel write mask applied to values written into the rendering target.
	 */
	virtual img::PixelChannel								GetWriteChannels() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IBLENDSTATE_
