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
// Purpose: Logical audio buffer chunk.
//==============================================================================
#include "config.h"
#include "AudioChunk.h"


namespace synkro
{


namespace audio
{


AudioChunk::AudioChunk( IAudioChunk* chunk, Bool readonly ) :
	_chunk( chunk ),
	_readonly( readonly )
{
}


} // audio


} // synkro
