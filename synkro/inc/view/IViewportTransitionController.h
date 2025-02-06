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
// Purpose: Defines viewport transition controller.
//==============================================================================
#ifndef _SYNKRO_VIEW_IVIEWPORTTRANSITIONCONTROLLER_
#define _SYNKRO_VIEW_IVIEWPORTTRANSITIONCONTROLLER_


#include "config.h"
#include <core/IController.h>
#include <view/TransitionEffect.h>


namespace synkro
{


namespace view
{


/**
 * Viewport transition controller.
 */
iface IViewportTransitionController :
	public core::IController
{
public:
	/**
	 * Removes all keys from the controller.
	 */
	virtual void											Clear() = 0;

	/**
	 * Creates a key at the given moment in time.
	 * @param time Moment of time for which to create the key.
	 * @param viewport Key viewport.
	 * @param effect Key transition effect.
	 */
	virtual void											SetKey( Double time, IViewport* viewport, const TransitionEffect& effect ) = 0;

	/**
	 * Creates a key at the given moment in time. Transition effect is defaulted to Step.
	 * @param time Moment of time for which to create the key.
	 * @param viewport Key viewport.
	 */
	virtual void											SetKey( Double time, IViewport* viewport ) = 0;

	/**
	 * Sets the number of transition loops. Set to 0 to loop forever.
	 * @param loopCount Number of loops.
	 */
	virtual void											SetLoopCount( UInt loopCount ) = 0;

	/**
	 * Retrieves the total number of keys in the controller.
	 */
	virtual UInt											GetKeyCount() const = 0;

	/**
	 * Retrieves key time by index.
	 * @param index Key index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual Double											GetKeyTime( UInt index ) const = 0;

	/**
	 * Retrieves key effect by index.
	 * @param index Key index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual TransitionEffect								GetKeyEffect( UInt index ) const = 0;

	/**
	 * Retrieves key viewport by index.
	 * @param index Key index.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IViewport*										GetKeyViewport( UInt index ) const = 0;

	/**
	 * Retrieves transition loop count.
	 */
	virtual UInt											GetLoopCount() const = 0;
};


} // view


} // synkro


#endif // _SYNKRO_VIEW_IVIEWPORTTRANSITIONCONTROLLER_
