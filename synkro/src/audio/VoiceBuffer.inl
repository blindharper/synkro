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
// Purpose: Logical voice buffer.
//==============================================================================
SYNKRO_INLINE void VoiceBuffer::Update()
{
	_buffer->Update();
}

SYNKRO_INLINE void VoiceBuffer::Process( Bool start, Bool loop )
{
	_buffer->Process( start, loop );
}

SYNKRO_INLINE void VoiceBuffer::GetFormat( sound::SoundFormat& format ) const
{
	_buffer->GetFormat( format );
}

SYNKRO_INLINE void VoiceBuffer::SuppressEcho( Bool suppress )
{
	_buffer->SuppressEcho( suppress );
}

SYNKRO_INLINE void VoiceBuffer::SuppressNoise( Bool suppress )
{
	_buffer->SuppressNoise( suppress );
}

SYNKRO_INLINE Bool VoiceBuffer::IsEchoSuppressed() const
{
	return _buffer->IsEchoSuppressed();
}

SYNKRO_INLINE Bool VoiceBuffer::IsNoiseSuppressed() const
{
	return _buffer->IsNoiseSuppressed();
}
