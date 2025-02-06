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
// Purpose: WinMM audio chunk.
//==============================================================================
SYNKRO_INLINE void WinmmAudioChunk::Read( Byte* data, UInt size ) const
{
	assert( size <= _size );

	Copy( data, (Byte*)_chunk.lpData, size );
}

SYNKRO_INLINE Bool WinmmAudioChunk::IsProcessing() const
{
	return (_chunk.dwFlags & WHDR_DONE) == 0;
}
