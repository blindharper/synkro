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
// Purpose: XAudio2 sound emitter.
//==============================================================================
#include "config.h"
#include "AlSoundEmitter.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


AlSoundEmitter::AlSoundEmitter( ALCdevice* device, const SoundFormat& format, Double length ) :
	SoundEmitterImpl<ISoundEmitter, AlAudioChunk>( format, 1 ),
	_emitter( 0 )
{
	// Create emitter.
	ALenum err = AL_NO_ERROR;
	Al::FlushErrors();
	Al::GenSources( 1, &_emitter );
	if ( (err = Al::GetError()) != AL_NO_ERROR )
		throw AudioException( String::Format(Str::SoundEmitterCreateFail, format.ToString()), String::Format(Str::CallFail, L"alGenSources()"), Al::ToString(err) );

	// Create chunk.
	_size = length * (Double)format.SamplesPerSecond * (Double)format.ChannelCount * (Double)(format.BitsPerSample >> 3);
	ALenum fmt = Al::Convert( _format );
	_chunks.Add( new AlAudioChunk(_emitter, fmt, (ALsizei)format.SamplesPerSecond, false, _size) );
}

AlSoundEmitter::~AlSoundEmitter()
{
	if ( _emitter != 0 )
	{
		Al::DeleteSources( 1, &_emitter );
		_emitter = 0;
	}
}

void AlSoundEmitter::Update()
{
	// Do nothing.
}

void AlSoundEmitter::Process( Bool start, Bool loop )
{
	if ( start )
	{
		Al::SourcePlay( _emitter );
	}
	else
	{
		Al::SourceStop( _emitter );
		Al::Sourcei( _emitter, AL_BUFFER, 0 );
		_chunks[0]->_processing = false;
	}
}

void AlSoundEmitter::SetPan( Int pan )
{
}

void AlSoundEmitter::SetAttenuation( Int attenuation )
{
}

void AlSoundEmitter::SetFrequency( UInt frequency )
{
}

void AlSoundEmitter::Bind()
{
	// Do nothing.
}


} // audio


} // synkro
