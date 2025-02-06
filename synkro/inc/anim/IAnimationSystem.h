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
// Purpose: Defines animation system.
//==============================================================================
#ifndef _SYNKRO_ANIM_IANIMATIONSYSTEM_
#define _SYNKRO_ANIM_IANIMATIONSYSTEM_


#include "config.h"
#include <core/ISystem.h>
#include <anim/AnimationCodec.h>


namespace synkro
{


namespace anim
{


/**
 * Animation system. Provides animation services.
 */
iface IAnimationSystem :
	public core::ISystem
{
public:
	/**
	 * Creates animation set.
	 * @param name Animation set name.
	 * @return Created animation set.
	 */
	virtual IAnimationSet*									CreateAnimationSet( const lang::String& name ) = 0;

	/**
	 * Creates named animation.
	 * @param name Animation name.
	 * @return Created animation.
	 */
	virtual IAnimation*										CreateAnimation( const lang::String& name ) = 0;

	/**
	 * Creates empty animation.
	 * @return Created animation.
	 */
	virtual IAnimation*										CreateAnimation() = 0;

	/**
	 * Creates expression script from text.
	 * @param expression Script text.
	 * @return Created expression script.
	 */
	virtual IExpressionScript*								CreateScript( const lang::String& expression ) = 0;

	/**
	 * Loads animation from a stream. Opens stream for reading and closes it after animation is loaded.
	 * @param stream Stream from which to load animation.
	 * @param type Animation codec type.
	 * @return Loaded animation set if succeeded, or null otherwise.
	 * @exception BadArgumentException Wrong animation type.
	 */
	virtual IAnimationSet*									LoadAnimation( io::IStream* stream, const AnimationCodec& type ) = 0;

	/**
	 * Loads animation from a stream. Opens stream for reading and closes it after animation is loaded. Animation type is guessed from stream name.
	 * @param stream Stream from which to load animation.
	 * @return Loaded animation set if succeeded, or null otherwise.
	 */
	virtual IAnimationSet*									LoadAnimation( io::IStream* stream ) = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IANIMATIONSYSTEM_
