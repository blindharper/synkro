#include <win/IWindowSystemFactory.h>
#include <win/WindowSystemEx.h>
#include <audio/IAudioSystemFactory.h>
#include <audio/IAudioEnvironment.h>
#include <audio/ISoundEmitter.h>
#include <audio/ISoundListener.h>
#include <audio/AudioSystemEx.h>
#include <sound/SoundManager.h>
#include <sound/BaseSound3D.h>
#include <sound/Sound.h>
#include <sound/Music.h>
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
using namespace synkro::math;
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
		//TestSound2D();
		//TestSound3D();
		TestMusic();
	}

	void TestSound2D()
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

		while ( window->Update() && snd->IsPlaying() )
		{
			//window->SetTitle( snd->IsPlaying() ? L"Playing" : L"Stopped" );
		}
	}

	void TestSound3D()
	{
		P(WindowSystemEx) windowSystem = new WindowSystemEx( _module, nullptr );
		windowSystem->Initialize( _factWindowSys );
		P(IFrameWindow) window = windowSystem->CreateWindow( false, false, _name, 0, 800, 600 );

		SoundFormat format = SoundFormat::Mono22kHz8bit;
		P(AudioSystemEx) audioSystem = new AudioSystemEx( format, nullptr );
		audioSystem->Initialize( _factAudioSys, format, windowSystem );
		P(IAudioPlayer) player = audioSystem->CreatePlayer( 0 );

		Context ctx;
		ctx.AudioSystem = audioSystem;
		ctx.WindowSystem = windowSystem;
		P(SoundManager) soundManager = new SoundManager( &ctx, nullptr );
		WavSoundCodecFactory factWavCodec;
		soundManager->RegisterCodec( &factWavCodec );

		// Load sound from file.
		P(io::IStream) stream = new io::FileStream( "../../data/audio/MusicMono.wav" );
		P(ISound3D) snd = soundManager->LoadSound3D( stream );
		P(ISoundEmitter) emitter = AsBaseSound3D(snd.AsPtr())->GetEmitter();
		emitter->SetPosition( Vector3::Origin );
		snd->Play( true );

		P(ISoundListener) listener = player->GetListener()->Clone();

		P(IAudioEnvironment) env = audioSystem->CreateEnvironment();
		env->SetListener( listener );
		env->AddEmitter( emitter );
		emitter->Bind();

		Float x = 0.0f;
		Bool back = false;
		while ( window->Update() )
		{
			Float dx = 0.0001f;

			if ( x > 5.0f )
			{
				back = true;
			}
			else if ( x < -5.0f )
			{ 
				back = false;
			}

			if ( back )
			{
				dx *= -1.0f;
			}
			x += dx;
				
			listener->SetPosition( Vector3(x, 0.0f, 0.0f) );
			listener->Bind();
			window->SetTitle( String::Format(L"x = {0,#.000000}", x));
		}
	}

	void TestMusic()
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

		// Load music from file.
		P(io::IStream) stream = new io::FileStream( "../../data/audio/Rock01.wav" );
		P(IMusic) music = soundManager->LoadMusic( stream );
		music->Play( true );

		while ( window->Update() && music->IsPlaying() )
		{
			audioSystem->Update( 0.0 );
			soundManager->Update( 0.0 );
		}
	}

private:
	Pointer					_module;
	String					_name;
	IWindowSystemFactory*	_factWindowSys;
	IAudioSystemFactory*	_factAudioSys;
};
