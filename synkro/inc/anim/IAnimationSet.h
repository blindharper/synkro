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
// Purpose: Defines animation set.
//==============================================================================
#ifndef _SYNKRO_ANIM_IANIMATIONSET_
#define _SYNKRO_ANIM_IANIMATIONSET_


#include "config.h"
#include <core/IObject.h>
#include <anim/AnimationCodec.h>


namespace synkro
{


namespace anim
{


/**
 * Collection of animations.
 */
iface IAnimationSet :
	public core::IObject
{
public:
	/**
	 * Saves animation set to the stream in the given format.
	 * @param stream Stream to which to save animation set.
	 * @param type Animation codec type.
	 */
	virtual void											Save( io::IStream* stream, const AnimationCodec& type ) = 0;

	/**
	 * Saves animation set to the stream in the given format. Animation type is guessed from stream name.
	 * @param stream Stream to which to save animation set.
	 */
	virtual void											Save( io::IStream* stream ) = 0;

	/**
	 * Asynchronously saves animation set to the stream in the given format.
	 * @param stream Stream to which to save animation set.
	 * @param type Animation codec type.
	 */
	virtual void											SaveAsync( io::IStream* stream, const AnimationCodec& type ) = 0;

	/**
	 * Asynchronously saves animation set to the stream in the given format. Animation type is guessed from stream name.
	 * @param stream Stream to which to save animation set.
	 */
	virtual void											SaveAsync( io::IStream* stream ) = 0;

	/**
	 * Create animation and adds it to the collection.
	 * @param name Animation name.
	 * @return Created animation.
	 * @exception BadArgumentException Animation with the specified name already exists.
	 */
	virtual IAnimation*										CreateAnimation( const lang::String& name ) = 0;

	/**
	 * Retrieves the number of animations in the collection.
	 */
	virtual UInt											GetAnimationCount() const = 0;

	/**
	 * Retrieves animation by index.
	 * @param index Index of the animation to retrieve.
	 * @return Requested animation.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IAnimation*										GetAnimation( UInt index ) const = 0;

	/**
	 * Retrieves animation by name.
	 * @param name Animation name.
	 * @return Requested animation, if found, nullptr otherwise.
	 */
	virtual IAnimation*										GetAnimation( const lang::String& name ) const = 0;

	/**
	 * Retrieves animation set name.
	 */
	virtual lang::String									GetName() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IANIMATIONSET_
