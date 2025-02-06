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
// Purpose: Defines abstract light source node.
//==============================================================================
#ifndef _SYNKRO_SCENE_ILIGHT_
#define _SYNKRO_SCENE_ILIGHT_


#include "config.h"
#include <scene/INode.h>
#include <img/Color.h>


namespace synkro
{


namespace scene
{


/**
 * Abstract light source node.
 */
iface ILight :
	public INode
{
public:
	/** 
	 * Enables/disables light source.
	 * @param enable True to turn the light on, false to turn it off.
	 */
	virtual void											Enable( Bool enable ) = 0;

	/**
	 * Sets light source diffuse color.
	 * @param color Diffuse color.
	 */
	virtual void											SetDiffuseColor( const img::Color& color ) = 0;

	/**
	 * Sets light source ambient color.
	 * @param color Ambient color.
	 */
	virtual void											SetAmbientColor( const img::Color& color ) = 0;

	/**
	 * Sets light source specular color.
	 * @param color Specular color.
	 */
	virtual void											SetSpecularColor( const img::Color& color ) = 0;

	/**
	 * Sets light source intensity.
	 * @param intensity Light intensity. Should be in range [0, 1].
	 */
	virtual void											SetIntensity( Float intensity ) = 0;

	/**
	 * Checks if the light is turned on.
	 */
	virtual Bool											IsEnabled() const = 0;

	/**
	 * Retrieves light source diffuse color.
	 * @param [out] color Diffuse color value.
	 */
	virtual void											GetDiffuseColor( img::Color& color ) const = 0;

	/**
	 * Retrieves light source ambient color.
	 * @param [out] color Ambient color value.
	 */
	virtual void											GetAmbientColor( img::Color& color ) const = 0;

	/**
	 * Retrieves light source specular color.
	 * @param [out] color Specular color value.
	 */
	virtual void											GetSpecularColor( img::Color& color ) const = 0;

	/**
	 * Retrieves light source intensity.
	 */
	virtual Float											GetIntensity() const = 0;

	/**
	 * Casts light to cone light.
	 * @return Non-null for cone light, nullptr otherwise.
	 */
	virtual IConeLight*										AsCone() const = 0;

	/**
	 * Casts light to direct light.
	 * @return Non-null for direct light, nullptr otherwise.
	 */
	virtual IDirectLight*									AsDirect() const = 0;

	/**
	 * Casts light to omni light.
	 * @return Non-null for omni light, nullptr otherwise.
	 */
	virtual IOmniLight*										AsOmni() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ILIGHT_
