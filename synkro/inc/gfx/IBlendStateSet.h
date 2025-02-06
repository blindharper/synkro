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
// Purpose: Defines blend state set.
//==============================================================================
#ifndef _SYNKRO_GFX_IBLENDSTATESET_
#define _SYNKRO_GFX_IBLENDSTATESET_


#include "config.h"
#include <gfx/IRenderState.h>
#include <gfx/BlendMode.h>
#include <gfx/BlendOperation.h>
#include <img/PixelChannel.h>


namespace synkro
{


namespace gfx
{


/**
 * Blend state set.
 */
iface IBlendStateSet :
	public IRenderState
{
public:
	/**
	 * Turns blending for all rendering targets on or off. Default is false.
	 * @param enable True to enable blending, false to disable it.
	 */
	virtual void											Enable( Bool enable ) = 0;

	/**
	 * Turns alpha-to-coverage multisampling technique on or off. Default is false.
	 * @param enable True to enable alpha-to-coverage, false to disable it.
	 */
	virtual void											EnableAlphaToCoverage( Bool enable ) = 0;

	/**
	 * Sets source blending mode for both color and alpha channels of all rendering targets. Default is One.
	 * @param mode Blending mode.
	 */
	virtual void											SetSrcMode( const BlendMode& mode ) = 0;

	/**
	 * Sets source blending mode for color channels of all rendering targets. Default is One.
	 * @param mode Blending mode.
	 */
	virtual void											SetColorSrcMode( const BlendMode& mode ) = 0;

	/**
	 * Sets source blending mode for alpha channel of all rendering targets. Default is One.
	 * @param mode Blending mode.
	 */
	virtual void											SetAlphaSrcMode( const BlendMode& mode ) = 0;

	/**
	 * Sets destination blending mode for both color and alpha channels of all rendering targets. Default is Zero.
	 * @param mode Blending mode.
	 */
	virtual void											SetDstMode( const BlendMode& mode ) = 0;

	/**
	 * Sets destination blending mode for color channels of all rendering targets. Default is Zero.
	 * @param mode Blending mode.
	 */
	virtual void											SetColorDstMode( const BlendMode& mode ) = 0;

	/**
	 * Sets destination blending mode for alpha channel of all rendering targets. Default is Zero.
	 * @param mode Blending mode.
	 */
	virtual void											SetAlphaDstMode( const BlendMode& mode ) = 0;

	/**
	 * Sets blending operation for both color and alpha channels of all rendering targets. Default is Add.
	 * @param operation Blending operation.
	 */
	virtual void											SetOperation( const BlendOperation& operation ) = 0;

	/**
	 * Sets blending operation for color channels of all rendering targets. Default is Add.
	 * @param operation Blending operation.
	 */
	virtual void											SetColorOperation( const BlendOperation& operation ) = 0;

	/**
	 * Sets blending operation for alpha channel of all rendering targets. Default is Add.
	 * @param operation Blending operation.
	 */
	virtual void											SetAlphaOperation( const BlendOperation& operation ) = 0;

	/**
	 * Sets per-pixel write mask applied to values written into all rendering targets. Default is All.
	 * @param channels Per-pixel write mask.
	 */
	virtual void											SetWriteChannels( const img::PixelChannel& channels ) = 0;

	/**
	 * Indicates whether the alpha-to-coverage multisampling technique is enabled.
	 * @return True if alpha-to-coverage is enabled, or false otherwise.
	 */
	virtual Bool 											IsAlphaToCoverageEnabled() const = 0;

	/**
	 * Retrieves the total number of rendering targets.
	 */
	virtual UInt											GetSize() const = 0;

	/**
	 * Retrieves blend state for a particular rendering target.
	 * @param index Rendering target index.
	 * @return Requested blend state.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IBlendState*									Get( UInt index ) const = 0;

	/**
	 * Produces an exact copy of the blend state set.
	 * @return Newly created blend state set.
	 */
	virtual IBlendStateSet*									Clone() const = 0;
};


} // gfx


} // synkro


#endif // _SYNKRO_GFX_IBLENDSTATESET_
