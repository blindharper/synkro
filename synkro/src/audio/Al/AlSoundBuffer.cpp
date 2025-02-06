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
// Purpose: OpenAL sound buffer.
//==============================================================================
#include "config.h"
#include "AlSoundBuffer.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


AlSoundBuffer::AlSoundBuffer( const SoundFormat& format, Double length, UInt chunkCount ) :
	SoundBufferImpl<ISoundBuffer, AlAudioChunk>( format, chunkCount ),
	_buffer( 0 )
{
	// Create buffer.
	ALenum err = AL_NO_ERROR;
	Al::FlushErrors();
	Al::GenSources( 1, &_buffer );
	if ( (err = Al::GetError()) != AL_NO_ERROR )
		throw AudioException( String::Format(Str::SoundBufferCreateFail, format.ToString()), String::Format(Str::CallFail, L"alGenSources()"), Al::ToString(err) );

	// Create chunks.
	UInt chunkSize = (length * (Double)format.SamplesPerSecond * (Double)format.ChannelCount * (Double)(format.BitsPerSample >> 3) / (Double)chunkCount);
	_size = chunkSize * chunkCount;
	ALenum fmt = Al::Convert( _format );
	for ( UInt i = 0; i < chunkCount; ++i )
	{
		_chunks.Add( new AlAudioChunk(_buffer, fmt, (ALsizei)_format.SamplesPerSecond, (chunkCount > 1), chunkSize) );
	}
}

AlSoundBuffer::~AlSoundBuffer()
{
	if ( _buffer != 0 )
	{
		Al::DeleteSources( 1, &_buffer );
		_buffer = 0;
	}
}

void AlSoundBuffer::Update()
{
	// Do not update static chunks.
	if ( _chunks.Size() == 1 )
	{
		_chunks[0]->_processing = false;
		return;
	}

	// Get buffer state.
	ALint state;
	Al::GetSourcei( _buffer, AL_SOURCE_STATE, &state );
	if ( state == AL_PLAYING )
	{
		// Unqueue processed chunks.
		ALint count = 0; ALuint chunk = 0;
		Al::GetSourcei( _buffer, AL_BUFFERS_PROCESSED, &count );
		for ( ALint i = 0; i < count; ++i )
		{
			Al::SourceUnqueueBuffers( _buffer, 1, &chunk );
			for ( UInt c = 0; c < _chunks.Size(); ++c )
			{
				if ( _chunks[c]->_chunk == chunk )
				{
					_chunks[c]->_processing = false;
					break;
				}
			}
		}
	}
	else if ( state == AL_STOPPED )
	{
		// Re-start playback if there're queued chunks.
		ALint count = 0;
		Al::GetSourcei( _buffer, AL_BUFFERS_QUEUED, &count );
		if ( count > 0 )
		{
			Al::SourcePlay( _buffer );
		}
	}
}

void AlSoundBuffer::Process( Bool start, Bool loop )
{
	if ( start )
	{
		Al::SourcePlay( _buffer );
	}
	else
	{
		Al::SourceStop( _buffer );
		Al::Sourcei( _buffer, AL_BUFFER, 0 );
		if ( _chunks.Size() == 1 )
		{
			_chunks[0]->_processing = false;
		}
	}
}

void AlSoundBuffer::SetPan( Int pan )
{
	// Call base implementation.
	SoundBufferImpl<ISoundBuffer, AlAudioChunk>::SetPan( pan );
}

void AlSoundBuffer::SetAttenuation( Int attenuation )
{
	// Call base implementation.
	SoundBufferImpl<ISoundBuffer, AlAudioChunk>::SetAttenuation( attenuation );

	Al::Sourcef( _buffer, AL_GAIN, CastFloat(_attenuation) );
}

void AlSoundBuffer::SetFrequency( UInt frequency )
{
	// Call base implementation.
	SoundBufferImpl<ISoundBuffer, AlAudioChunk>::SetFrequency( frequency );
}


} // audio


} // synkro
