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
// Purpose: Extended audio system.
//=============================================================================
SYNKRO_INLINE UInt AudioSystemEx::GetTotalPlayerCount() const
{
	return _audioSystem->GetTotalPlayerCount();
}

SYNKRO_INLINE void AudioSystemEx::GetPlayerDesc( UInt index, PlayerDesc& desc ) const
{
	_audioSystem->GetPlayerDesc( index, desc );
}

SYNKRO_INLINE UInt AudioSystemEx::GetTotalRecorderCount() const
{
	return _audioSystem->GetTotalRecorderCount();
}

SYNKRO_INLINE void AudioSystemEx::GetRecorderDesc( UInt index, RecorderDesc& desc ) const
{
	_audioSystem->GetRecorderDesc( index, desc );
}

SYNKRO_INLINE IAudioEnvironment* AudioSystemEx::GetActiveEnvironment() const
{
	return _activeEnvironment;
}

SYNKRO_INLINE UInt AudioSystemEx::GetPlayerCount() const
{
	return _players.Size();
}

SYNKRO_INLINE IAudioPlayer* AudioSystemEx::GetPlayer( UInt index ) const
{
	assert( index < _players.Size() );

	if ( index >= _players.Size() )
		throw lang::OutOfRangeException( index, _players.Size() );

	return _players[index];
}

SYNKRO_INLINE IAudioPlayer* AudioSystemEx::GetPlayer() const
{
	return (_players.Size() > 0) ? _players[0] : nullptr;
}

SYNKRO_INLINE UInt AudioSystemEx::GetRecorderCount() const
{
	return _recorders.Size();
}

SYNKRO_INLINE IAudioRecorder* AudioSystemEx::GetRecorder( UInt index ) const
{
	assert( index < _recorders.Size() );

	if ( index >= _recorders.Size() )
		throw lang::OutOfRangeException( index, _recorders.Size() );

	return _recorders[index];
}

SYNKRO_INLINE IAudioRecorder* AudioSystemEx::GetRecorder() const
{
	return (_recorders.Size() > 0) ? _recorders[0] : nullptr;
}
