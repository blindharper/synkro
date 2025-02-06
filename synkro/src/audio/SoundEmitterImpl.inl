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
// Purpose: Generic sound emitter implementation.
//==============================================================================
template <class T, class C>
SYNKRO_INLINE SoundEmitterImpl<T, C>::SoundEmitterImpl( const sound::SoundFormat& format, UInt chunkCount ) :
	SoundBufferImpl<T, C>( format, chunkCount ),
	_position( math::Vector3(0.0f, 0.0f, 0.0f) ),
	_direction( math::Vector3(0.0f, 0.0f, 1.0f) ),
	_velocity( math::Vector3(0.0f, 0.0f, 0.0f) ),
	_innerAngle( 360.0f ),
	_outerAngle( 360.0f ),
	_innerAttenuation( 0L ),
	_outerAttenuation( 0L ),
	_innerReverb( 1.0f ),
	_outerReverb( 1.0f ),
	_minDistance( 1.0f ),
	_maxDistance( 1000000000.0f )
{
}

template <class T, class C>
SYNKRO_INLINE SoundEmitterImpl<T, C>::~SoundEmitterImpl()
{
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::SetPosition( const math::Vector3& position )
{
	if ( position != _position )
	{
		_position = position;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::SetDirection( const math::Vector3& direction )
{
	if ( direction != _direction )
	{
		_direction = direction;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::SetVelocity( const math::Vector3& velocity )
{
	if ( velocity != _velocity )
	{
		_velocity = velocity;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::SetInnerAngle( Float angle )
{
	if ( angle != _innerAngle )
	{
		_innerAngle = angle;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::SetOuterAngle( Float angle )
{
	if ( angle != _outerAngle )
	{
		_outerAngle = angle;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::SetInnerAttenuation( Int attenuation )
{
	if ( attenuation != _innerAttenuation )
	{
		_innerAttenuation = attenuation;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::SetOuterAttenuation( Int attenuation )
{
	if ( attenuation != _outerAttenuation )
	{
		_outerAttenuation = attenuation;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::SetInnerReverb( Float reverb )
{
	if ( reverb != _innerReverb )
	{
		_innerReverb = reverb;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::SetOuterReverb( Float reverb )
{
	if ( reverb != _outerReverb )
	{
		_outerReverb = reverb;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::SetMinDistance( Float distance )
{
	if ( distance != _minDistance )
	{
		_minDistance = distance;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::SetMaxDistance( Float distance )
{
	if ( distance != _maxDistance )
	{
		_maxDistance = distance;
		_dirty = true;
	}
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::GetPosition( math::Vector3& position ) const
{
	position = _position;
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::GetDirection( math::Vector3& direction ) const
{
	direction = _direction;
}

template <class T, class C>
SYNKRO_INLINE void SoundEmitterImpl<T, C>::GetVelocity( math::Vector3& velocity ) const
{
	velocity = _velocity;
}

template <class T, class C>
SYNKRO_INLINE Float SoundEmitterImpl<T, C>::GetInnerAngle() const
{
	return _innerAngle;
}

template <class T, class C>
SYNKRO_INLINE Float SoundEmitterImpl<T, C>::GetOuterAngle() const
{
	return _outerAngle;
}

template <class T, class C>
SYNKRO_INLINE Int SoundEmitterImpl<T, C>::GetInnerAttenuation() const
{
	return _innerAttenuation;
}

template <class T, class C>
SYNKRO_INLINE Int SoundEmitterImpl<T, C>::GetOuterAttenuation() const
{
	return _outerAttenuation;
}

template <class T, class C>
SYNKRO_INLINE Float SoundEmitterImpl<T, C>::GetInnerReverb() const
{
	return _innerReverb;
}

template <class T, class C>
SYNKRO_INLINE Float SoundEmitterImpl<T, C>::GetOuterReverb() const
{
	return _outerReverb;
}

template <class T, class C>
SYNKRO_INLINE Float SoundEmitterImpl<T, C>::GetMinDistance() const
{
	return _minDistance;
}

template <class T, class C>
SYNKRO_INLINE Float SoundEmitterImpl<T, C>::GetMaxDistance() const
{
	return _maxDistance;
}
