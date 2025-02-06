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
// Purpose: DirectSound 8 audio chunk.
//==============================================================================
#include "config.h"
#include "Ds8AudioChunk.h"


namespace synkro
{


namespace audio
{


Ds8AudioChunk::Ds8AudioChunk( Ds8BaseBuffer* buffer, UInt offset, UInt size ) :
	AudioChunkImpl<IAudioChunk>( size ),
	_buffer( buffer ),
	_offset( offset )
{
}

Bool Ds8AudioChunk::IsProcessing() const
{
	UInt read = 0; UInt write = 0;
	_buffer->GetPosition( &read, &write );

	const UInt end = _offset + _size;
	if ( read <= write )
	{
		return (end > read) && (write > _offset);
	}
	else
	{
		return (read > 0) && (write > 0);
	}
}


} // audio


} // synkro
