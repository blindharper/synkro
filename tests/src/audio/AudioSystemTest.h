#include <win/IWindowSystemFactory.h>
#include <win/WindowSystemEx.h>
#include <audio/IAudioSystemFactory.h>
#include <audio/AudioSystemEx.h>
#include <sound/SoundManager.h>
#include <sound/Sound.h>
//#include <sound/SoundCodec/Mp3SoundCodecFactory.h>
#include <sound/SoundCodec/WavSoundCodecFactory.h>
#include <io/FileStream.h>
#include <lang/Convert.h>
#include <stdio.h>
#include "Context.h"


//------------------------------------------------------------------------------

using namespace synkro::audio;
using namespace synkro::core;
using namespace synkro::lang;
using namespace synkro::sound;
using namespace synkro::win;
using namespace synkro;

//------------------------------------------------------------------------------


class AudioSystemTest
{
public:
	AudioSystemTest( Pointer module, const String& name, IWindowSystemFactory* factWindowSys, IAudioSystemFactory* factAudioSys ) :
		_module( module ), 
		_name( name ),
		_factWindowSys( factWindowSys ),
		_factAudioSys( factAudioSys )
	{
	}

	void Run()
	{
		P(WindowSystemEx) windowSystem = new WindowSystemEx( _module, nullptr );
		windowSystem->Initialize( _factWindowSys );
		P(IFrameWindow) window = windowSystem->CreateWindow( false, false, _name, 0, 800, 600 );

		SoundFormat format = SoundFormat::Mono22kHz8bit;
		P(AudioSystemEx) audioSystem = new AudioSystemEx( format, nullptr );
		audioSystem->Initialize( _factAudioSys, format, windowSystem );
		audioSystem->CreatePlayer( 0 );

		Context ctx;
		ctx.AudioSystem = audioSystem;
		ctx.WindowSystem = windowSystem;
		P(SoundManager) soundManager = new SoundManager( &ctx, nullptr );
		WavSoundCodecFactory factWavCodec;
		soundManager->RegisterCodec( &factWavCodec );
		/*Mp3SoundCodecFactory factMp3Codec;
		soundManager->RegisterCodec( &factMp3Codec );*/

		// Load sound from file.
		P(io::IStream) stream = new io::FileStream( "../../data/audio/Rock01.wav" );
		//P(io::IStream) stream = new io::FileStream( "../../data/audio/demo.mp3" );
		P(ISound2D) snd = soundManager->LoadSound2D( stream );
		snd->Play( true );

		/*//Platform::Sleep( 0 );

		//P(IMusic) music = soundManager->LoadMusic( stream );
		//music->Play( true );*/

		while ( window->Update() && snd->IsPlaying() )
		{
			//window->SetTitle( snd->IsPlaying() ? L"Playing" : L"Stopped" );

			//audioSystem->Update( 0.0 );
			//soundManager->Update( 0.0 );
		}
	}

private:
	Pointer					_module;
	String					_name;
	IWindowSystemFactory*	_factWindowSys;
	IAudioSystemFactory*	_factAudioSys;
};
