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
// Purpose: Defines billboard scene node.
//==============================================================================
#ifndef _SYNKRO_SCENE_IBILLBOARD_
#define _SYNKRO_SCENE_IBILLBOARD_


#include "config.h"
#include <scene/INode.h>


namespace synkro
{


namespace scene
{


/**
 * Billboard node. 2D-geometry always oriented to camera.
 */
iface IBillboard :
	public INode
{
public:
	/** 
	 * Sets billboard visibility.
	 * @param show Set to true to make billboard visible, set to false to hide it.
	 */
	virtual void											Show( Bool show ) = 0;

	/**
	 * Retrieves billboard visibility.
	 * @return True if billboard is visible, or false otherwise.
	 */
	virtual Bool											IsVisible() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IBILLBOARD_
