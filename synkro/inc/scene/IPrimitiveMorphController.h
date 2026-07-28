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
// Purpose: Defines morph controller for primitive.
//==============================================================================
#ifndef _SYNKRO_SCENE_IPRIMITIVEMORPHCONTROLLER_
#define _SYNKRO_SCENE_IPRIMITIVEMORPHCONTROLLER_


#include "config.h"
#include <anim/IPlaybackAnimationController.h>


namespace synkro
{


namespace scene
{


/**
 * Morph controller for primitive.
 */
iface IPrimitiveMorphController :
	public anim::IPlaybackAnimationController
{
public:
	/**
	 * Adds morph channel.
	 * @param name Morph channel name.
	 * @param channel Morph channel geometry.
	 * @exception BadArgumentException Invalid morph channel.
	 * @exception BadArgumentException Morph channel with this name already exists.
	 * @exception BadArgumentException Channel's vertex count doesn't match that of target primitive.
	 */
	virtual void											AddChannel( const lang::String& name, IPrimitive* channel ) = 0;

	/**
	 * Creates keyframed track controlling channel weight.
	 * @param channel Morph channel name.
	 * @return Created channel weight track.
	 * @exception BadArgumentException Unknown channel name.
	 * @exception BadArgumentException Channel track already exists.
	 */
	virtual anim::IKeyframedFloatTrack*						CreateChannelWeightTrack( const lang::String& channel ) = 0;

	/**
	 * Creates expression track controlling channel weight.
	 * @param channel Morph channel name.
	 * @param script Expression script.
	 * @return Created channel weight track.
	 * @exception BadArgumentException Unknown channel name.
	 * @exception BadArgumentException Channel track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateChannelWeightTrack( const lang::String& channel, anim::IExpressionScript* script ) = 0;

	/**
	 * Creates expression track controlling channel weight.
	 * @param channel Morph channel name.
	 * @param expression Expression text.
	 * @return Created channel weight track.
	 * @exception BadArgumentException Unknown channel name.
	 * @exception BadArgumentException Channel track already exists.
	 */
	virtual anim::IExpressionFloatTrack*					CreateChannelWeightTrack( const lang::String& channel, const lang::String& expression ) = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_IPRIMITIVEMORPHCONTROLLER_
