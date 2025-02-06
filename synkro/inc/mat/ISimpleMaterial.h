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
// Purpose: Simple material.
//==============================================================================
#ifndef _SYNKRO_MAT_ISIMPLEMATERIAL_
#define _SYNKRO_MAT_ISIMPLEMATERIAL_


#include "config.h"
#include <mat/IVisualMaterial.h>
#include <mat/LightingModel.h>
#include <img/Color.h>


namespace synkro
{


namespace mat
{


/**
 * Simple material. Defines lighting settings.
 */
iface ISimpleMaterial :
	public IVisualMaterial
{
public:
	/**
	 * Sets material's lighing model. Default is Phong.
	 * @param lightingModel Lighting model.
	 */
	virtual void											SetLightingModel( const LightingModel& lightingModel ) = 0;

	/**
	 * Sets material's diffuse color.
	 * @param color Diffuse color value.
	 */
	virtual void											SetDiffuseColor( const img::Color& color ) = 0;

	/**
	 * Sets material's ambient color.
	 * @param color Ambient color value.
	 */
	virtual void											SetAmbientColor( const img::Color& color ) = 0;

	/**
	 * Sets material's emissive color.
	 * @param color Emissive color value.
	 */
	virtual void											SetEmissiveColor( const img::Color& color ) = 0;

	/**
	 * Sets material's specular color.
	 * @param color Specular color value.
	 */
	virtual void											SetSpecularColor( const img::Color& color ) = 0;

	/**
	 * Sets material's specular highlights sharpness.
	 * @param power Specular highlight sharpness value.
	 */
	virtual void											SetSpecularPower( Float power ) = 0;

	/**
	 * Sets horizontal map tiling.
	 * @param tiling Horizontal tiling.
	 */
	virtual void											SetTilingHorizontal( UInt tiling ) = 0;

	/**
	 * Sets vertical map tiling.
	 * @param tiling Vertical tiling.
	 */
	virtual void											SetTilingVertical( UInt tiling ) = 0;

	/**
	 * Retrieves material's lighing model.
	 */
	virtual LightingModel									GetLightingModel() const = 0;

	/**
	 * Retrieves material's diffuse color.
	 * @param [out] color Diffuse color value.
	 */
	virtual void											GetDiffuseColor( img::Color& color ) const = 0;

	/**
	 * Retrieves material's ambient color.
	 * @param [out] color Ambient color value.
	 */
	virtual void											GetAmbientColor( img::Color& color ) const = 0;

	/**
	 * Retrieves material's emissive color.
	 * @param [out] color Emissive color value.
	 */
	virtual void											GetEmissiveColor( img::Color& color ) const = 0;

	/**
	 * Retrieves material's specular color.
	 * @param [out] color Specular color value.
	 */
	virtual void											GetSpecularColor( img::Color& color ) const = 0;

	/**
	 * Retrieves material's specular highlights power.
	 */
	virtual Float											GetSpecularPower() const = 0;

	/**
	 * Retrieves horizontal map tiling.
	 */
	virtual UInt											GetTilingHorizontal() const = 0;

	/**
	 * Retrieves vertical map tiling.
	 */
	virtual UInt											GetTilingVertical() const = 0;

	/**
	 * Retrieves diffuse map.
	 */
	virtual IMaterialMap*									GetDiffuseMap() const = 0;

	/**
	 * Casts material to opaque material.
	 * @return Non-null for opaque material, nullptr otherwise.
	 */
	virtual IOpaqueMaterial*								AsOpaque() const = 0;

	/**
	 * Casts material to transparent material.
	 * @return Non-null for transparent material, nullptr otherwise.
	 */
	virtual ITransparentMaterial*							AsTransparent() const = 0;
};


} // mat


} // synkro


#endif // _SYNKRO_MAT_ISIMPLEMATERIAL_
