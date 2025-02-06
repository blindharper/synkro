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
// Purpose: DirectSound 8 sound emitter.
//==============================================================================
#ifndef _SYNKRO_AUDIO_DS8SOUNDEMITTER_
#define _SYNKRO_AUDIO_DS8SOUNDEMITTER_


#include "config.h"
#include <audio/SoundEmitterImpl.h>
#include <audio/ISoundEmitter.h>
#include "Ds8BaseBuffer.h"
#include "Ds8AudioChunk.h"
#include "Ds8.h"


namespace synkro
{


namespace audio
{


// DirectSound 8 sound emitter.
class Ds8SoundEmitter :
	public SoundEmitterImpl<ISoundEmitter, Ds8AudioChunk>,
	public Ds8BaseBuffer
{
public:
	// Constructor & destructor.
	Ds8SoundEmitter( IDirectSound8* device, const sound::SoundFormat& format, Double length );
	~Ds8SoundEmitter();

	// IAudioBuffer methods.
	void													Update();
	void													Process( Bool start, Bool loop );

	// ISoundBuffer methods.
	void													SetPan( Int pan );
	void													SetAttenuation( Int attenuation );
	void													SetFrequency( UInt frequency );

	// ISoundEmitter methods.
	void													Bind();

	// Ds8BaseBuffer methods.
	Bool													Map( UInt offset, UInt size, Byte** data );
	Bool													Unmap( Byte* data, UInt size );
	void													GetPosition( UInt* read, UInt* write ) const;

private:
	IDirectSoundBuffer8*									_buffer;
	IDirectSound3DBuffer8*									_buffer3D;
	void*													_ptr1;
	DWORD													_bytes1;
	void*													_ptr2;
	DWORD													_bytes2;
};


} // audio


} // synkro


#endif // _SYNKRO_AUDIO_DS8SOUNDEMITTER_
