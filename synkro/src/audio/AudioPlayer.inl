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
// Purpose: Logical player.
//==============================================================================
SYNKRO_INLINE void AudioPlayer::GetFormat( sound::SoundFormat& format ) const
{
	_player->GetFormat( format );
}

SYNKRO_INLINE void AudioPlayer::GetDesc( PlayerDesc& desc ) const
{
	_player->GetDesc( desc );
}

SYNKRO_INLINE ISoundListener* AudioPlayer::GetListener() const
{
	return _listener;
}

SYNKRO_INLINE UInt AudioPlayer::GetIndex() const
{
	return _index;
}
