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
// Purpose: Generic audio system implementation.
//=============================================================================
template <class T>
SYNKRO_INLINE AudioSystemImpl<T>::AudioSystemImpl( const sound::SoundFormat& format, diag::ILog* log ) :
	_players( A(PlayerDesc) ),
	_recorders( A(RecorderDesc) ),
	_format( format ),
	Logger( log, diag::LogFacility::AudioSystem )
{
}

template <class T>
SYNKRO_INLINE AudioSystemImpl<T>::~AudioSystemImpl()
{
}

template <class T>
SYNKRO_INLINE Bool AudioSystemImpl<T>::Update( Double delta )
{
	return true;
}

template <class T>
SYNKRO_INLINE UInt AudioSystemImpl<T>::GetTotalPlayerCount() const
{
	return _players.Size();
}

template <class T>
SYNKRO_INLINE void AudioSystemImpl<T>::GetPlayerDesc( UInt index, PlayerDesc& desc ) const
{
	assert( index < _players.Size() );

	if ( index >= _players.Size() )
		throw lang::OutOfRangeException( index, _players.Size() );

	desc = _players[index];
}

template <class T>
SYNKRO_INLINE UInt AudioSystemImpl<T>::GetTotalRecorderCount() const
{
	return _recorders.Size();
}

template <class T>
SYNKRO_INLINE void AudioSystemImpl<T>::GetRecorderDesc( UInt index, RecorderDesc& desc ) const
{
	assert( index < _recorders.Size() );

	if ( index >= _recorders.Size() )
		throw lang::OutOfRangeException( index, _recorders.Size() );

	desc = _recorders[index];
}
