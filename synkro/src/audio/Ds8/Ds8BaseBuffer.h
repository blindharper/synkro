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
// Purpose: Defines DirectSound 8 buffer.
//==============================================================================
#ifndef _SYNKRO_AUDIO_DS8BASEBUFFER_
#define _SYNKRO_AUDIO_DS8BASEBUFFER_


#include "config.h"


namespace synkro
{


namespace audio
{


// DirectSound 8 buffer.
class Ds8BaseBuffer
{
public:
	virtual Bool											Map( UInt offset, UInt size, Byte** data ) = 0;
	virtual Bool											Unmap( Byte* data, UInt size ) = 0;
	virtual void											GetPosition( UInt* read, UInt* write ) const = 0;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_DS8BASEBUFFER_
