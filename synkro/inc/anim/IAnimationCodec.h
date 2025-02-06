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
// Purpose: Defines abstract animation codec.
//==============================================================================
#ifndef _SYNKRO_ANIM_IANIMATIONCODEC_
#define _SYNKRO_ANIM_IANIMATIONCODEC_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace anim
{


/**
 * Abstract animation codec.
 */
iface IAnimationCodec :
	public core::IObject
{
public:
	/**
	 * Loads animation set from stream.
	 * @param stream Stream to load animation set from.
	 * @exception BadArgumentException Bad stream.
	 */
	virtual IAnimationSet*									Load( io::IStream* stream ) = 0;

	/**
	 * Saves animation set to stream.
	 * @param animation Animation set to save.
	 * @param stream Stream to save animation set to.
	 * @exception BadArgumentException Bad stream.
	 * @exception BadArgumentException Bad animation set.
	 */
	virtual void											Save( const IAnimationSet* animation, io::IStream* stream ) = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IANIMATIONCODEC_
