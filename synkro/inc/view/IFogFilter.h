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
// Purpose: Defines fog viewport filter.
//==============================================================================
#ifndef _SYNKRO_VIEW_IFOGFILTER_
#define _SYNKRO_VIEW_IFOGFILTER_


#include "config.h"
#include <view/IDepthFilter.h>
#include <scene/FogType.h>
#include <img/Color.h>


namespace synkro
{


namespace view
{


/**
 * Fog viewport filter.
 */
iface IFogFilter :
	public IDepthFilter
{
public:
	/**
	 * Sets fog color. Default is LightGray.
	 * @param color Fog color.
	 */
	virtual void											SetColor( const img::Color& color ) = 0;

	/**
	 * Sets fog density. Valid range is [0,1]. Only meaningful for exponential fog. Default is 0.01.
	 * @param density Fog density.
	 */
	virtual void											SetDensity( Float density ) = 0;

	/**
	 * Sets fog start distance. Only meaningful for linear fog. Default is 0.0.
	 * @param start Start distance.
	 */
	virtual void											SetStart( Float start ) = 0;

	/**
	 * Sets fog end distance. Only meaningful for linear fog. Default is 100.0.
	 * @param end End distance.
	 */
	virtual void											SetEnd( Float end ) = 0;

	/**
	 * Sets fog type. Default is Linear.
	 * @param type Fog type.
	 */
	virtual void											SetType( const scene::FogType& type ) = 0;

	/**
	 * Retrieves fog color.
	 * @param [out] color Fog color.
	 */
	virtual void											GetColor( img::Color& color ) const = 0;

	/**
	 * Retrieves fog density. Only meaningful for exponential fog.
	 */
	virtual Float											GetDensity() const = 0;

	/**
	 * Retrieves fog start distance. Only meaningful for linear fog.
	 */
	virtual Float											GetStart() const = 0;

	/**
	 * Retrieves fog end distance. Only meaningful for linear fog.
	 */
	virtual Float											GetEnd() const = 0;

	/**
	 * Retrieves fog type.
	 */
	virtual scene::FogType									GetType() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IFOGFILTER_
