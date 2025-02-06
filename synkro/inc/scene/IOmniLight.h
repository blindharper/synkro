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
// Purpose: Defines omni light node.
//==============================================================================
#ifndef _SYNKRO_SCENE_IOMNILIGHT_
#define _SYNKRO_SCENE_IOMNILIGHT_


#include "config.h"
#include <scene/ILight.h>
#include <scene/Attenuation.h>


namespace synkro
{


namespace scene
{


/**
 * Omni light node.
 */
iface IOmniLight :
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
	 * Retrieves light range.
	 */
	virtual Float											GetRange() const = 0;

	/**
	 * Retrieves light attenuation.
	 * @param [out] attenuation Light attenuation.
	 */
	virtual void											GetAttenuation( Attenuation& attenuation ) const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IOMNILIGHT_
