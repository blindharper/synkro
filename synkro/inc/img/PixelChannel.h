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
// Purpose: Defines pixel channel.
//==============================================================================
#ifndef _SYNKRO_IMG_PIXELCHANNEL_
#define _SYNKRO_IMG_PIXELCHANNEL_


#include "config.h"
#include <lang/Flag.h>


namespace synkro
{


namespace img
{


/**
 * Pixel channel.
 */
SYNKRO_FLAG_BEGIN( PixelChannel )
	/** Red channel. */
	SYNKRO_FLAG_CONST( PixelChannel, Red )

	/** Green channel. */
	SYNKRO_FLAG_CONST( PixelChannel, Green )

	/** Blue channel. */
	SYNKRO_FLAG_CONST( PixelChannel, Blue )

	/** Alpha channel. */
	SYNKRO_FLAG_CONST( PixelChannel, Alpha )

	/** All channels. */
	SYNKRO_FLAG_CONST( PixelChannel, All )

	/** Creates pixel channel from string. */
	PixelChannel( const lang::String& channel );

	/** Converts pixel channel to string. */
	lang::String											ToString() const;
SYNKRO_FLAG_END()


} // img


} // synkro


#endif // _SYNKRO_IMG_PIXELCHANNEL_
