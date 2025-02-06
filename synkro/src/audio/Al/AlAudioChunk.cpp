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
// Purpose: OpenAL audio chunk.
//==============================================================================
#include "config.h"
#include "AlAudioChunk.h"
#include <audio/AudioException.h>


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


AlAudioChunk::AlAudioChunk( ALuint buffer, ALenum format, ALsizei frequency, Bool streaming, UInt size ) :
	AudioChunkImpl<IAudioChunk>( size ),
	_data( nullptr ),
	_buffer( buffer ),
	_chunk( 0 ),
	_format( format ),
	_frequency( frequency ),
	_streaming( streaming ),
	_processing( false )
{
	ALenum err = AL_NO_ERROR;
	Al::FlushErrors();
	Al::GenBuffers( 1, &_chunk );
	if ( (err = Al::GetError()) != AL_NO_ERROR )
		throw AudioException( L"Failed to create audio chunk.", String::Format(Str::CallFail, L"alGenBuffers()"), Al::ToString(err) );
}

AlAudioChunk::AlAudioChunk( UInt size ) :
	AudioChunkImpl<IAudioChunk>( size ),
	_data( nullptr ),
	_buffer( 0 ),
	_chunk( 0 ),
	_format( 0 ),
	_frequency( 0 ),
	_streaming( false ),
	_processing( false )
{
}

AlAudioChunk::~AlAudioChunk()
{
	if ( _chunk != 0 )
	{
		Al::DeleteBuffers( 1, &_chunk );
		_chunk = 0;
	}
}


} // audio


} // synkro
