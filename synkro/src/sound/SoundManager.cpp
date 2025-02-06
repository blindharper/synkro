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
// Purpose: Sound manager implementation.
//==============================================================================
#include "config.h"
#include "SoundManager.h"
#include "Sound2D.h"
#include "Sound3D.h"
#include "Music.h"
#include "Voice.h"
#include <audio/IAudioSystem.h>
#include <audio/IAudioPlayer.h>
#include <lang/Convert.h>
#include <io/Path.h>
#include <io/IStream.h>
#include <io/IStreamDirectory.h>
#include <sound/SoundCodec.h>
#include <sound/ISoundCodecFactory.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::audio;
using namespace synkro::core;
using namespace synkro::diag;
using namespace synkro::lang;
using namespace synkro::io;

//------------------------------------------------------------------------------


namespace synkro
{


namespace sound
{


SoundManager::SoundManager( IContext* context, ILog* log ) :
	_codecs( A(CodecEntry) ),
	_musics( A(BaseMusic*) ),
	_voices( A(BaseVoice*) ),
	_context( context ),
	Logger( log, LogFacility::SoundManager )
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Creating sound manager...") );
}

SoundManager::~SoundManager()
{
	LogInfo( MessagePriority::Lowest, Formatter::Format(L"Destroying sound manager...") );
}

Bool SoundManager::Update( Double delta )
{
	SynkroProfile( "SoundManager.Update" );

	_musics.Each( *this );
	_voices.Each( *this );

	return true;
}

IVoice* SoundManager::CreateVoice( IStream* stream, const SoundFormat& format, const SoundCodec& type )
{
	if ( _codecs.ContainsKey(type) )
	{
		ISoundCodec* codec = _codecs[type];
		Voice* voice = new Voice( this, _context->GetAudioSystem()->GetRecorder(0), codec, stream, format);
		_voices.Add( voice );
		return voice;
	}
	return nullptr;
}

IVoice* SoundManager::CreateVoice( IStream* stream, const SoundFormat& format )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	return !type.IsEmpty() ? CreateVoice( stream, format, SoundCodec(type) ) : nullptr;
}

ISound2D* SoundManager::LoadSound2D( IStream* stream, const SoundCodec& type )
{
	return _codecs.ContainsKey(type) ? new Sound2D( _context->GetAudioSystem(), _codecs[type], stream) : nullptr;
}

ISound2D* SoundManager::LoadSound2D( IStream* stream )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	return !type.IsEmpty() ? LoadSound2D( stream, SoundCodec(type) ) : nullptr;
}

ISound3D* SoundManager::LoadSound3D( IStream* stream, const SoundCodec& type )
{
	return _codecs.ContainsKey(type) ? new Sound3D( _context->GetAudioSystem(), _codecs[type], stream ) : nullptr;
}

ISound3D* SoundManager::LoadSound3D( IStream* stream )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	return !type.IsEmpty() ? LoadSound3D( stream, SoundCodec(type) ) : nullptr;
}

IMusic* SoundManager::LoadMusic( IStream* stream, const SoundCodec& type )
{
	return _codecs.ContainsKey(type) ? new Music( this, _context, _codecs[type], stream ) : nullptr;
}

IMusic* SoundManager::LoadMusic( IStream* stream )
{
	String type = Path(stream->GetName()).GetExtensionWoDot();
	return !type.IsEmpty() ? LoadMusic( stream, SoundCodec(type) ) : nullptr;
}

void SoundManager::RegisterCodec( ISoundCodecFactory* factory )
{
	assert( factory != nullptr );

	const SoundCodec type( factory->GetClassID() );
	LogInfoStart( MessagePriority::Lowest, Formatter::Format(L"Registering sound codec {0,q}...", type.ToString()) );
	if ( !_codecs.ContainsKey(type) )
	{
		try
		{
			_codecs[type] = factory->Create();
			LogInfoEnd( Formatter::Format(Str::Done) );
		}
		catch ( const Exception& ex )
		{
			LogInfoEnd( String::Empty );
			LogWarning( MessagePriority::Normal, ex.ToString() );
		}
	}
	else
	{
		LogInfoEnd( Formatter::Format(L"Codec already registered.") );
	}
}


} // sound


} // synkro
