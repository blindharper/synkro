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
// Purpose: OpenAL player.
//==============================================================================
#include "config.h"
#include "AlAudioPlayer.h"
#include "AlSoundBuffer.h"
#include "AlSoundEmitter.h"
#include "AlSoundListener.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::sound;

//------------------------------------------------------------------------------


namespace synkro
{


namespace audio
{


AlAudioPlayer::AlAudioPlayer( const SoundFormat& format, const PlayerDesc& desc ) :
	AudioPlayerImpl<IAudioPlayer>( format, desc ),
	_context( nullptr ),
	_device( nullptr )
{
	ALCenum err = ALC_NO_ERROR;

	// Create device.
	const UInt SIZE = 200;
	ALchar name[SIZE];
	desc.Name.GetBytes( name, SIZE );
	if ( (_device = Alc::OpenDevice(name)) == nullptr )
	{
		err = Alc::GetError( nullptr );
		throw AudioException( String::Format(Str::PlayerCreateFail, desc.Name), String::Format(Str::CallFail, L"alcOpenDevice()"), Alc::ToString(err) );
	}

	// Create and activate context.
	_context = Alc::CreateContext( _device, nullptr );
	if ( _context == 0 )
	{
		err = Alc::GetError( nullptr );
		throw AudioException( String::Format(Str::PlayerCreateFail, desc.Name), String::Format(Str::CallFail, L"alcCreateContext()"), Alc::ToString(err) );
	}
	Alc::MakeContextCurrent( _context );

	// Create listener.
	_listener = new AlSoundListener();
}

AlAudioPlayer::~AlAudioPlayer()
{
	if ( _context != nullptr )
	{
		Alc::MakeContextCurrent( nullptr );
		Alc::DestroyContext( _context );
		_context = nullptr;
	}

	if ( _device != nullptr )
	{
		Alc::CloseDevice( _device );
		_device = nullptr;
	}
}

ISoundBuffer* AlAudioPlayer::CreateSoundBuffer( const SoundFormat& format, Double length, UInt chunkCount )
{
	assert( length > 0.0 );

	return new AlSoundBuffer( format, length, chunkCount );
}

ISoundEmitter* AlAudioPlayer::CreateSoundEmitter( const SoundFormat& format, Double length )
{
	assert( length > 0.0 );

	return new AlSoundEmitter( _device, format, length );
}


} // audio


} // synkro
