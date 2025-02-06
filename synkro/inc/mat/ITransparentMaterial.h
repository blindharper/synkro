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
// Purpose: Transparent material.
//==============================================================================
#ifndef _SYNKRO_MAT_ITRANSPARENTMATERIAL_
#define _SYNKRO_MAT_ITRANSPARENTMATERIAL_


#include "config.h"
#include <mat/ISimpleMaterial.h>
#include <gfx/BlendMode.h>
#include <gfx/BlendOperation.h>


namespace synkro
{


namespace mat
{


/**
 * Transparent material.
 */
iface ITransparentMaterial :
	public ISimpleMaterial
{
public:
	/**
	 * Sets material's opacity. Default is 0.5.
	 * @param opacity Material opacity. Valid range is [0.0-1.0].
	 */
	virtual void											SetOpacity( Float opacity ) = 0;

	/**
	 * Sets source blending mode for color channels. Default is One.
	 * @param mode Blending mode.
	 */
	virtual void											SetColorSourceMode( const gfx::BlendMode& mode ) = 0;

	/**
	 * Sets source blending mode for alpha channel. Default is One.
	 * @param mode Blending mode.
	 */
	virtual void											SetAlphaSourceMode( const gfx::BlendMode& mode ) = 0;

	/**
	 * Sets destination blending mode for color channels. Default is Zero.
	 * @param mode Blending mode.
	 */
	virtual void											SetColorDestinationMode( const gfx::BlendMode& mode ) = 0;

	/**
	 * Sets destination blending mode for alpha channel. Default is Zero.
	 * @param mode Blending mode.
	 */
	virtual void											SetAlphaDestinationMode( const gfx::BlendMode& mode ) = 0;

	/**
	 * Sets blending operation for color channels. Default is Add.
	 * @param operation Blending operation.
	 */
	virtual void											SetColorOperation( const gfx::BlendOperation& operation ) = 0;

	/**
	 * Sets blending operation for alpha channel. Default is Add.
	 * @param operation Blending operation.
	 */
	virtual void											SetAlphaOperation( const gfx::BlendOperation& operation ) = 0;

	/**
	 * Retrieves material's opacity.
	 */
	virtual Float											GetOpacity() const = 0;

	/**
	 * Retrieves source blending mode for color channels.
	 */
	virtual gfx::BlendMode									GetColorSourceMode() const = 0;

	/**
	 * Retrieves source blending mode for alpha channel.
	 */
	virtual gfx::BlendMode									GetAlphaSourceMode() const = 0;

	/**
	 * Retrieves destination blending mode for color channels.
	 */
	virtual gfx::BlendMode									GetColorDestinationMode() const = 0;

	/**
	 * Retrieves destination blending mode for alpha channel.
	 */
	virtual gfx::BlendMode									GetAlphaDestinationMode() const = 0;

	/**
	 * Retrieves blending operation for color channels.
	 */
	virtual gfx::BlendOperation								GetColorOperation() const = 0;

	/**
	 * Retrieves blending operation for alpha channel.
	 */
	virtual gfx::BlendOperation								GetAlphaOperation() const = 0;

	/**
	 * Retrieves opacity map.
	 */
	virtual IMaterialMap*									GetOpacityMap() const = 0;

	/**
	 * Creates an exact copy of the material.
	 */
	virtual ITransparentMaterial*							Clone() const = 0;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_ITRANSPARENTMATERIAL_
