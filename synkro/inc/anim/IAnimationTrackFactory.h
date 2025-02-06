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
// Purpose: Defines animation track factory.
//==============================================================================
#ifndef _SYNKRO_ANIM_IANIMATIONTRACKFACTORY_
#define _SYNKRO_ANIM_IANIMATIONTRACKFACTORY_


#include "config.h"
#include <core/IFactory.h>
#include <anim/AnimationDataType.h>


namespace synkro
{


namespace anim
{


/**
 * Animation track factory. Used to instantiate procedural animation tracks.
 */
iface IAnimationTrackFactory :
	public core::IFactory
{
public:
	/**
	 * Creates animation track.
	 * @param name Track name.
	 * @return Created animation track.
	 */
	virtual IAnimationTrack*								Create( const lang::String& name ) = 0;

	/** 
	 * Retrieves animation track data type.
	 */
	virtual AnimationDataType								GetType() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IANIMATIONTRACKFACTORY_
