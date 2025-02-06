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
// Purpose: Logical sound buffer.
//==============================================================================
SYNKRO_INLINE void SoundBuffer::Update()
{
	_buffer->Update();
}

SYNKRO_INLINE void SoundBuffer::Process( Bool start, Bool loop )
{
	_buffer->Process( start, loop );
}

SYNKRO_INLINE void SoundBuffer::GetFormat( sound::SoundFormat& format ) const
{
	_buffer->GetFormat( format );
}

SYNKRO_INLINE void SoundBuffer::SetPan( Int pan )
{
	_buffer->SetPan( pan );
}

SYNKRO_INLINE void SoundBuffer::SetAttenuation( Int attenuation )
{
	_buffer->SetAttenuation( attenuation );
}

SYNKRO_INLINE void SoundBuffer::SetFrequency( UInt frequency )
{
	_buffer->SetFrequency( frequency );
}

SYNKRO_INLINE Int SoundBuffer::GetPan() const
{
	return _buffer->GetPan();
}

SYNKRO_INLINE Int SoundBuffer::GetAttenuation() const
{
	return _buffer->GetAttenuation();
}

SYNKRO_INLINE UInt SoundBuffer::GetFrequency() const
{
	return _buffer->GetFrequency();
}
