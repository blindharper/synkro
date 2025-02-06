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
SYNKRO_INLINE PlaybackControllerImpl<T>::PlaybackControllerImpl( IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	AnimationControllerImpl<T>( animationSystem, animation ),
	_listener( listener ),
	_mode( AnimationMode::Single ),
	_direction( AnimationDirection::Forward ),
	_dir( 1.0 ),
	_speed( 1.0 ),
	_offset( 0.0 ),
	_length( 0.0 ),
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
				_length = _animation->GetLength();
				_state = core::ControllerState::Active;
				_dir = (_direction == AnimationDirection::Reverse) ? -1.0 : 1.0;
			}
			break;

		default:
			if ( !start )
			{
				_time = _animation->GetLength();
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
SYNKRO_INLINE void PlaybackControllerImpl<T>::SetSpeed( Double speed )
{
	if ( speed < 0.0 )
		throw lang::BadArgumentException( L"Animation speed must be positive.", L"speed", lang::String(speed) );

	_speed = speed;
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::SetOffset( Double offset )
{
	_offset = offset;
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::SetMode( const AnimationMode& mode )
{
	_mode = mode;
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::SetDirection( const AnimationDirection& direction )
{
	_direction = direction;
}

template <class T>
SYNKRO_INLINE void PlaybackControllerImpl<T>::SetLoopCount( UInt loopCount )
{
	_loopCount = loopCount;
}

template <class T>
SYNKRO_INLINE Double PlaybackControllerImpl<T>::GetSpeed() const
{
	return _speed;
}

template <class T>
SYNKRO_INLINE Double PlaybackControllerImpl<T>::GetOffset() const
{
	return _offset;
}

template <class T>
SYNKRO_INLINE AnimationMode PlaybackControllerImpl<T>::GetMode() const
{
	return _mode;
}

template <class T>
SYNKRO_INLINE AnimationDirection PlaybackControllerImpl<T>::GetDirection() const
{
	return _direction;
}

template <class T>
SYNKRO_INLINE UInt PlaybackControllerImpl<T>::GetLoopCount() const
{
	return _loopCount;
}

template <class T>
SYNKRO_INLINE UInt PlaybackControllerImpl<T>::GetIteration() const
{
	return _iteration;
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
}

template<class T>
template<class I, class P>
SYNKRO_INLINE I* PlaybackControllerImpl<T>::GetTrack( I* track, const P& prop )
{
	return (I*)_animation->GetTrack( prop.ToString() );
}
