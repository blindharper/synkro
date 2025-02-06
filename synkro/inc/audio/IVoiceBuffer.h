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
// Purpose: Defines voice buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_IVOICEBUFFER_
#define _SYNKRO_AUDIO_IVOICEBUFFER_


#include "config.h"
#include <audio/IAudioBuffer.h>


namespace synkro
{


namespace audio
{


/**
 * Voice buffer.
 */
iface IVoiceBuffer :
	public IAudioBuffer
{
public:
	/** 
	 * Enables or disables acoustic echo suppression.
	 * @param suppress Indicates whether to suppress acoustic echo.
	 */
	virtual void											SuppressEcho( Bool suppress ) = 0;

	/** 
	 * Enables or disables noise suppression.
	 * @param suppress Indicates whether to suppress noise.
	 */
	virtual void											SuppressNoise( Bool suppress ) = 0;

	/** 
	 * Indicates whether to suppress acoustic echo.
	 */
	virtual Bool											IsEchoSuppressed() const = 0;

	/** 
	 * Indicates whether to suppress noise.
	 */
	virtual Bool											IsNoiseSuppressed() const = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_IVOICEBUFFER_
