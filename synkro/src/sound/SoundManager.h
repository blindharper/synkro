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
#ifndef _SYNKRO_SOUND_SOUNDMANAGER_
#define _SYNKRO_SOUND_SOUNDMANAGER_


#include "config.h"
#include <lang/Map.h>
#include <lang/Vector.h>
#include <core/IContext.h>
#include <core/ObjectImpl.h>
#include <io/IStreamSystem.h>
#include <audio/IAudioSystemEx.h>
#include <sound/ISound2D.h>
#include <sound/ISound3D.h>
#include <sound/IMusic.h>
#include <sound/IVoice.h>
#include <sound/ISoundManager.h>
#include <sound/ISoundCodec.h>
#include "BaseSoundManager.h"


namespace synkro
{


namespace sound
{


// Sound manager implementation.
class SoundManager :
	public core::ObjectImpl<ISoundManager>,
	public BaseSoundManager,
	public Logger
{
public:
	// Constructor & destructor.
	SoundManager( core::IContext* context, diag::ILog* log );
	~SoundManager();

	// ISystem methods.
	Bool													Update( Double delta );

	// ISoundManager methods.
	IVoice*													CreateVoice( io::IStream* stream, const SoundFormat& format, const SoundCodec& type );
	IVoice*													CreateVoice( io::IStream* stream, const SoundFormat& format );
	ISound2D*												LoadSound2D( io::IStream* stream, const SoundCodec& type );
	ISound2D*												LoadSound2D( io::IStream* stream );
	ISound3D*												LoadSound3D( io::IStream* stream, const SoundCodec& type );
	ISound3D*												LoadSound3D( io::IStream* stream );
	IMusic*													LoadMusic( io::IStream* stream, const SoundCodec& type );
	IMusic*													LoadMusic( io::IStream* stream );

	// BaseSoundManager methods.
	void													AddMusic( BaseMusic* music );
	void													AddVoice( BaseVoice* voice );
	void													RemoveMusic( BaseMusic* music );
	void													RemoveVoice( BaseVoice* voice );

	// Other methods.
	void													RegisterCodec( ISoundCodecFactory* factory );
	Bool													Call( BaseMusic* music );
	Bool													Call( BaseVoice* voice );

private:
	typedef lang::MapPair<UInt, P(ISoundCodec)>				CodecEntry;

	lang::Map<UInt, P(ISoundCodec)>							_codecs;
	lang::Vector<BaseMusic*>								_musics;
	lang::Vector<BaseVoice*>								_voices;
	core::IContext*											_context;
};


#include "SoundManager.inl"


} // sound


} // synkro


#endif // _SYNKRO_SOUND_SOUNDMANAGER_
