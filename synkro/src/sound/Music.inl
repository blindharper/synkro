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
SYNKRO_INLINE void Music::Pause( Bool pause )
{
	_buffer->Process( !pause, false );
	_playing = !pause;
}

SYNKRO_INLINE void Music::SetVolume( Int volume )
{
	_buffer->SetAttenuation( volume );
}

SYNKRO_INLINE void Music::SetPan( Int pan )
{
	_buffer->SetPan( pan );
}

SYNKRO_INLINE void Music::SetMode( const PlaybackMode& mode )
{
	_mode = mode;
}

SYNKRO_INLINE void Music::SetLoopCount( UInt loopCount )
{
	_loopCount = loopCount;
}

SYNKRO_INLINE Bool Music::IsPlaying() const
{
	return _playing;
}

SYNKRO_INLINE Bool Music::IsPaused() const
{
	return !_playing;
}

SYNKRO_INLINE Int Music::GetVolume() const
{
	return _buffer->GetAttenuation();
}

SYNKRO_INLINE Int Music::GetPan() const
{
	return _buffer->GetPan();
}

SYNKRO_INLINE PlaybackMode Music::GetMode() const
{
	return _mode;
}

SYNKRO_INLINE UInt Music::GetLoopCount() const
{
	return _loopCount;
}

SYNKRO_INLINE Double Music::GetLength() const
{
	return _length;
}
