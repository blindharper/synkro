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
// Purpose: Generic record animation controller implementation.
//==============================================================================
template <class T> 
SYNKRO_INLINE RecordControllerImpl<T>::RecordControllerImpl( IAnimationSystem* animationSystem, IAnimation* animation ) :
	AnimationControllerImpl<T>( animationSystem, animation ),
	_step( 1.0 )
{
}

template <class T>
SYNKRO_INLINE RecordControllerImpl<T>::~RecordControllerImpl()
{
}

template <class T>
SYNKRO_INLINE void RecordControllerImpl<T>::Start( Bool start )
{
	_state = start ? core::ControllerState::Active : core::ControllerState::Inactive;
}

template <class T>
SYNKRO_INLINE void RecordControllerImpl<T>::SetStep( Double step )
{
	_step = step;
}

template <class T>
SYNKRO_INLINE Double RecordControllerImpl<T>::GetStep() const
{
	return _step;
}
