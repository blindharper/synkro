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
// Purpose: Defines voice object.
//==============================================================================
#ifndef _SYNKRO_SOUND_IVOICE_
#define _SYNKRO_SOUND_IVOICE_


#include "config.h"
#include <core/IObject.h>


namespace synkro
{


namespace sound
{


/**
 * Recorded voice.
 */
iface IVoice :
	public core::IObject
{
public:
	/**
	 * Starts or stops recording the voice.
	 * @param record Set to true to start recording or to false to stop it.
	 */
	virtual void											Record( Bool record ) = 0;

	/**
	 * Retrieves voice recording state.
	 */
	virtual Bool											IsRecording() const = 0;

	/**
	 * Retrieves voice duration, in seconds.
	 */
	virtual Double											GetLength() const = 0;
};


} // sound


} // synkro


#endif // _SYNKRO_SOUND_IVOICE_
