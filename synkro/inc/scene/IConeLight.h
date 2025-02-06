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
// Purpose: Defines cone light node.
//==============================================================================
#ifndef _SYNKRO_SCENE_ICONELIGHT_
#define _SYNKRO_SCENE_ICONELIGHT_


#include "config.h"
#include <scene/ILight.h>
#include <scene/Attenuation.h>


namespace synkro
{


namespace scene
{


/**
 * Cone light node.
 */
iface IConeLight :
	public ILight
{
public:
	/**
	 * Sets light range.
	 * @param range Light range.
	 */
	virtual void											SetRange( Float range ) = 0;

	/**
	 * Sets light attenuation.
	 * @param attenuation Light attenuation.
	 */
	virtual void											SetAttenuation( const Attenuation& attenuation ) = 0;

	/**
	 * Sets cone's inner angle. Default is Pi.
	 * @param angle Cone's inner angle, in radians.
	 */
	virtual void											SetInnerAngle( Float angle ) = 0;

	/**
	 * Sets cone's outer angle. Default is Pi.
	 * @param angle Cone'a outer angle, in radians.
	 */
	virtual void											SetOuterAngle( Float angle ) = 0;

	/**
	 * Sets decrease in illumination between cone's inner edge and the outer edge.
	 * @param falloff Falloff value.
	 */
	virtual void											SetFalloff( Float falloff ) = 0;

	/**
	 * Retrieves light range.
	 */
	virtual Float											GetRange() const = 0;

	/**
	 * Retrieves light attenuation.
	 * @param [out] attenuation Light attenuation.
	 */
	virtual void											GetAttenuation( Attenuation& attenuation ) const = 0;

	/**
	 * Retrieves cone's inner angle.
	 */
	virtual Float											GetInnerAngle() const = 0;

	/**
	 * Retrieves cone's outer angle.
	 */
	virtual Float											GetOuterAngle() const = 0;

	/**
	 * Retrieves decrease in illumination between cone's inner edge and the outer edge.
	 */
	virtual Float											GetFalloff() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ICONELIGHT_
