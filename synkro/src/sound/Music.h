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
// Purpose: Music track implementation.
//==============================================================================
#ifndef _SYNKRO_SOUND_MUSIC_
#define _SYNKRO_SOUND_MUSIC_


#include "config.h"
#include <core/IContext.h>
#include <core/ObjectImpl.h>
#include <sound/IMusic.h>
#include <sound/IMusicAnimationController.h>
#include <sound/ISoundCodec.h>
#include <audio/IAudioSystemEx.h>
#include <audio/ISoundBuffer.h>
#include <audio/IAudioChunk.h>
#include <audio/IAudioPlayer.h>
#include <audio/IAudioSystem.h>
#include <sound/SoundCodecContext.h>
#include <io/IStream.h>
#include <lang/Vector.h>
#include "BaseSoundManager.h"


namespace synkro
{


namespace sound
{


// Music track implementation.
class Music :
	public core::ObjectImpl<IMusic>,
	public BaseMusic
{
public:
	// Constructor & destructor.
	Music( BaseSoundManager* soundManager, core::IContext* context, ISoundCodec* codec, io::IStream* stream );
	~Music();

	// IMusic methods.
	IMusicAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	void													Play( Bool play );
	void													Pause( Bool pause );
	void													SetVolume( Int volume );
	void													SetPan( Int pan );
	void													SetMode( const PlaybackMode& mode );
	void													SetLoopCount( UInt loopCount );
	Bool													IsPlaying() const;
	Bool													IsPaused() const;
	Int														GetVolume() const;
	Int														GetPan() const;
	PlaybackMode											GetMode() const;
	UInt													GetLoopCount() const;
	Double													GetLength() const;

	// BaseMusic methods.
	void													Update();

private:
	lang::Vector<Byte>										_data;
	BaseSoundManager*										_soundManager;
	core::IContext*											_context;
	SoundCodecContext*										_soundContext;
	P(IMusicAnimationController)							_ctrlAnimation;
	audio::IAudioPlayer*									_player;
	P(audio::ISoundBuffer)									_buffer;
	P(io::IStream)											_stream;
	ISoundCodec*											_codec;
	PlaybackMode											_mode;
	UInt													_loopCount;
	UInt													_chunkIndex;
	Bool													_playing;
	Double													_length;
};


#include "Music.inl"


} // sound


} // synkro


#endif // _SYNKRO_SOUND_MUSIC_
