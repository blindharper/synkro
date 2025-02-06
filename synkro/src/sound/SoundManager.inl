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
SYNKRO_INLINE void SoundManager::AddMusic( BaseMusic* music )
{
	_musics.Add( music );
}

SYNKRO_INLINE void SoundManager::AddVoice( BaseVoice* voice )
{
	_voices.Add( voice );
}

SYNKRO_INLINE void SoundManager::RemoveMusic( BaseMusic* music )
{
	_musics.Remove( music );
}

SYNKRO_INLINE void SoundManager::RemoveVoice( BaseVoice* voice )
{
	_voices.Remove( voice );
}

SYNKRO_INLINE Bool SoundManager::Call( BaseMusic* music )
{
	music->Update();
	return true;
}

SYNKRO_INLINE Bool SoundManager::Call( BaseVoice* voice )
{
	voice->Update();
	return true;
}
