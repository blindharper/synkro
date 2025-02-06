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
// Purpose: Generic controller implementation.
//==============================================================================
template <class T> 
SYNKRO_INLINE ControllerImpl<T>::ControllerImpl() :
	_state( ControllerState::Inactive ),
	_time( 0.0 )
{
}

template <class T>
SYNKRO_INLINE ControllerImpl<T>::~ControllerImpl()
{
}

template <class T>
SYNKRO_INLINE void ControllerImpl<T>::Start( Bool start )
{
	_state = start ? ControllerState::Active : ControllerState::Inactive;
}

template <class T>
SYNKRO_INLINE void ControllerImpl<T>::Pause( Bool pause )
{
	switch ( _state )
	{
		case CONTROLLER_STATE_ACTIVE:
			if ( pause )
				_state = ControllerState::Suspended;
			break;

		case CONTROLLER_STATE_SUSPENDED:
			if ( !pause )
				_state = ControllerState::Active;
			break;
	}
}

template <class T>
SYNKRO_INLINE void ControllerImpl<T>::Update( Double delta )
{
	_time += delta;
}

template <class T>
SYNKRO_INLINE void ControllerImpl<T>::SetTime( Double time )
{
	_time = time;
}

template <class T>
SYNKRO_INLINE void ControllerImpl<T>::Restart()
{
	Start( false );
	Start( true );
}

template <class T>
SYNKRO_INLINE void ControllerImpl<T>::Reset()
{
	_time = 0.0;
}

template <class T>
SYNKRO_INLINE Double ControllerImpl<T>::GetTime() const
{
	return _time;
}

template <class T>
SYNKRO_INLINE ControllerState ControllerImpl<T>::GetState() const
{
	return _state;
}
