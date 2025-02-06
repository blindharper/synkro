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
#include "config.h"
#include "WinmmAudioChunk.h"
#include <internal/SafeDelete.h>


namespace synkro
{


namespace audio
{


WinmmAudioChunk::WinmmAudioChunk( HWAVEIN device, UInt offset, UInt size ) :
	AudioChunkImpl<IAudioChunk>( size ),
	_deviceIn( device ),
	_deviceOut( nullptr )
{
	Zero( &_chunk );
	_chunk.lpData = (LPSTR)new Byte[_size];
	_chunk.dwBufferLength = _size;
}

WinmmAudioChunk::WinmmAudioChunk( HWAVEOUT device, UInt offset, UInt size ) :
	AudioChunkImpl<IAudioChunk>( size ),
	_deviceIn( nullptr ),
	_deviceOut( device )
{
	Zero( &_chunk );
	_chunk.lpData = (LPSTR)new Byte[_size];
}

WinmmAudioChunk::~WinmmAudioChunk()
{
	SafeDelete( _chunk.lpData );
}

void WinmmAudioChunk::Write( const Byte* data, UInt size )
{
	assert( size <= _size );

	_chunk.dwBufferLength = size;
	_chunk.dwFlags = WHDR_PREPARED;
	Copy( (Byte*)_chunk.lpData, data, size );
	Winmm::WaveOutPrepareHeader( _deviceOut, &_chunk, sizeof(WAVEHDR) );
	Winmm::WaveOutWrite( _deviceOut, &_chunk, sizeof(WAVEHDR) );
}


} // audio


} // synkro
