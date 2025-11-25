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
// Purpose: Generic playback animation controller implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE PlaybackControllerImpl<T>::PlaybackControllerImpl( IAnimationSystem* animationSystem, IAnimationSet* animations, AnimationListener* listener ) :
	AnimationControllerImpl<T>( animationSystem, animations ),
	_listener( listener ),
	_mode( AnimationMode::Single ),
	_direction( AnimationDirection::Forward ),
	_dir( 1.0 ),
	_speed( 1.0 ),
	_offset( 0.0 ),
	_length( 0.0 ),
	_currentTime( 0.0 ),
	_times( A(Double) ),
	_loopCount( 0 ),
	_iteration( 0 )
{
}

template <class T>
SYNKRO_INLINE PlaybackControllerImpl<T>::~PlaybackControllerImpl()
{
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::Start( Bool start )
{
	switch ( _state )
	{
		case core::CONTROLLER_STATE_INACTIVE:
			if ( start )
			{
				_iteration = 0;
				_time = _offset;
				GetAnimationsLengths();
				_state = core::ControllerState::Active;
				_dir = (_direction == AnimationDirection::Reverse) ? -1.0 : 1.0;
				GetCurrentAnimation();
				UpdateTracks();
			}
			break;

		default:
			if ( !start )
			{
				_time = _animations->GetLength();
				_state = core::ControllerState::Inactive;
				if ( _listener != nullptr )
				{
					_animationSystem->AddStopEvent( this, _listener );
				}
			}
			break;
	}
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::Update( Double delta )
{
	_time += _dir*_speed*delta;
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::SetAnimations( IAnimationSet* animations )
{
	// Call base implementation.
	AnimationControllerImpl<T>::SetAnimations( animations );

	GetAnimationsLengths();
	GetCurrentAnimation();
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::SetSpeed( Double speed )
{
	assert( speed >= 0.0 );

	if ( speed < 0.0 )
		throw lang::BadArgumentException( L"Animation speed must not be negative.", L"speed", lang::String(speed) );

	_speed = speed;
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::SetOffset( Double offset ) SYNKRO_NOEXCEPT
{
	_offset = offset;
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::SetMode( const AnimationMode& mode ) SYNKRO_NOEXCEPT
{
	_mode = mode;
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::SetDirection( const AnimationDirection& direction ) SYNKRO_NOEXCEPT
{
	_direction = direction;
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::SetLoopCount( UInt loopCount ) SYNKRO_NOEXCEPT
{
	_loopCount = loopCount;
}

template <class T>
SYNKRO_INLINE Double PlaybackControllerImpl<T>::GetSpeed() const SYNKRO_NOEXCEPT
{
	return _speed;
}

template <class T>
SYNKRO_INLINE Double PlaybackControllerImpl<T>::GetOffset() const SYNKRO_NOEXCEPT
{
	return _offset;
}

template <class T>
SYNKRO_INLINE AnimationMode PlaybackControllerImpl<T>::GetMode() const SYNKRO_NOEXCEPT
{
	return _mode;
}

template <class T>
SYNKRO_INLINE AnimationDirection PlaybackControllerImpl<T>::GetDirection() const SYNKRO_NOEXCEPT
{
	return _direction;
}

template <class T>
SYNKRO_INLINE UInt PlaybackControllerImpl<T>::GetLoopCount() const SYNKRO_NOEXCEPT
{
	return _loopCount;
}

template <class T>
SYNKRO_INLINE UInt PlaybackControllerImpl<T>::GetIteration() const SYNKRO_NOEXCEPT
{
	return _iteration;
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::UpdateTracks()
{
	// Do nothing.
}

template <class T>
SYNKRO_INLINE Double PlaybackControllerImpl<T>::CurrentTime() const SYNKRO_NOEXCEPT
{
	return _currentTime;
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::PostUpdate()
{
	if ( (_time > _length) || (_time < 0.0) )
	{
		switch ( _mode )
		{
			case ANIMATION_MODE_SINGLE:
				PlaybackControllerImpl<T>::Start( false );
				break;

			case ANIMATION_MODE_LOOP:
				if ( (++_iteration < _loopCount) || (_loopCount == 0) )
				{
					if ( _length != 0.0 )
					{
						if ( _direction == AnimationDirection::Forward )
						{
							ControllerImpl<T>::Reset();
						}
						else if ( _direction == AnimationDirection::Reverse )
						{
							_time = _length;
						}
					}
					if ( _listener != nullptr )
					{
						_animationSystem->AddLoopEvent( this, _listener );
					}
				}
				else
				{
					PlaybackControllerImpl<T>::Start( false );
				}
				break;

			case ANIMATION_MODE_PING_PONG:
				if ( (++_iteration < _loopCount) || (_loopCount == 0) )
				{
					_time = (_time > _length) ? _length : 0.0;
					_dir = (_time == 0.0) ? 1.0 : -1.0;
					if ( _listener != nullptr )
					{
						_animationSystem->AddLoopEvent( this, _listener );
					}
				}
				else
				{
					PlaybackControllerImpl<T>::Start( false );
				}
				break;
		}
	}
	GetCurrentAnimation();
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::GetAnimationsLengths()
{
	_times.Clear();
	Double total = 0.0;
	UInt count = _animations->GetAnimationCount();
	for ( UInt i = 0; i < count; ++i )
	{
		total += _animations->GetAnimation( i )->GetLength();
		_times.Add( total );
	}
	_length = _times.LastValue();
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::GetCurrentAnimation()
{
	UInt index = 0;
	for ( UInt i = 0; i < _times.Size(); ++i )
	{
		if ( _time <= _times[i] )
		{
			index = i;
			break;
		}
	}
	IAnimation* old = _currentAnimation;
	_currentAnimation = _animations->GetAnimation( index );
	_currentTime = ((_times.Size() == 1) || index == 0) ? _time : _time - _times[index-1];
	if ( _currentAnimation != old )
	{
		UpdateTracks();
	}
}

template<class T>
template<class I, class P>
SYNKRO_INLINE I* PlaybackControllerImpl<T>::GetTrack( I* track, const P& prop )
{
	return (I*)_currentAnimation->GetTrack( prop.ToString() );
}
