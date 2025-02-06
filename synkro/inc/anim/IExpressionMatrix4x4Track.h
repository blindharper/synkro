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
// Purpose: Defines expression track for a 4x4 matrix.
//==============================================================================
#ifndef _SYNKRO_ANIM_IEXPRESSIONMATRIX4X4TRACK_
#define _SYNKRO_ANIM_IEXPRESSIONMATRIX4X4TRACK_


#include "config.h"
#include <anim/IAnimationMatrix4x4Track.h>


namespace synkro
{


namespace anim
{


/**
 * Expression track for a 4x4 matrix.
 */
iface IExpressionMatrix4x4Track :
	public IAnimationMatrix4x4Track
{
public:
	/**
	 * Sets track length, in seconds.
	 * @param length Track length.
	 */
	virtual void											SetLength( Double length ) = 0;

	/**
	 * Retrieves track's expression script.
	 */
	virtual IExpressionScript*								GetScript() const = 0;
};


} // anim


} // synkro


#endif // _SYNKRO_ANIM_IEXPRESSIONMATRIX4X4TRACK_
