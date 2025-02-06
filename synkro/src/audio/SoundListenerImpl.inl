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
// Purpose: Generic sound listener implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE SoundListenerImpl<T>::SoundListenerImpl() :
	_dirty( true ),
	_position( math::Vector3(0.0f, 0.0f, 0.0f) ),
	_direction( math::Vector3(0.0f, 0.0f, 1.0f) ),
	_velocity( math::Vector3(0.0f, 0.0f, 0.0f) ),
	_rolloffFactor( 1.0f ),
	_dopplerFactor( 1.0f )
{
}

template <class T>
SYNKRO_INLINE SoundListenerImpl<T>::~SoundListenerImpl()
{
}

template <class T>
SYNKRO_INLINE void SoundListenerImpl<T>::SetPosition( const math::Vector3& position )
{
	if ( position != _position )
	{
		_position = position;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SoundListenerImpl<T>::SetDirection( const math::Vector3& direction )
{
	if ( direction != _direction )
	{
		_direction = direction;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SoundListenerImpl<T>::SetVelocity( const math::Vector3& velocity )
{
	if ( velocity != _velocity )
	{
		_velocity = velocity;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SoundListenerImpl<T>::SetRolloffFactor( Float factor )
{
	if ( factor != _rolloffFactor )
	{
		_rolloffFactor = factor;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SoundListenerImpl<T>::SetDopplerFactor( Float factor )
{
	if ( factor != _dopplerFactor )
	{
		_dopplerFactor = factor;
		_dirty = true;
	}
}

template <class T>
SYNKRO_INLINE void SoundListenerImpl<T>::GetPosition( math::Vector3& position ) const
{
	position = _position;
}

template <class T>
SYNKRO_INLINE void SoundListenerImpl<T>::GetDirection( math::Vector3& direction ) const
{
	direction = _direction;
}

template <class T>
SYNKRO_INLINE void SoundListenerImpl<T>::GetVelocity( math::Vector3& velocity ) const
{
	velocity = _velocity;
}

template <class T>
SYNKRO_INLINE Float SoundListenerImpl<T>::GetRolloffFactor() const
{
	return _rolloffFactor;
}

template <class T>
SYNKRO_INLINE Float SoundListenerImpl<T>::GetDopplerFactor() const
{
	return _dopplerFactor;
}
