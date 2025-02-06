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
// Purpose: DirectSound 8 sound buffer.
//==============================================================================
SYNKRO_INLINE void Ds8SoundBuffer::Update()
{
	// Do nothing.
}

SYNKRO_INLINE void Ds8SoundBuffer::SetPan( Int pan )
{
	// Call base implementation.
	SoundBufferImpl<ISoundBuffer, Ds8AudioChunk>::SetPan( pan );

	HRESULT hr = _buffer->SetPan( pan );
}

SYNKRO_INLINE void Ds8SoundBuffer::SetAttenuation( Int attenuation )
{
	// Call base implementation.
	SoundBufferImpl<ISoundBuffer, Ds8AudioChunk>::SetAttenuation( attenuation );

	HRESULT hr = _buffer->SetVolume( attenuation );
}

SYNKRO_INLINE void Ds8SoundBuffer::SetFrequency( UInt frequency )
{
	// Call base implementation.
	SoundBufferImpl<ISoundBuffer, Ds8AudioChunk>::SetFrequency( frequency );

	HRESULT hr = _buffer->SetFrequency( frequency );
}
