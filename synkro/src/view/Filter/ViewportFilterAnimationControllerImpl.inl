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
// Purpose: Generic implementation of animation controller for viewport filter.
//==============================================================================
template <class T>
SYNKRO_INLINE ViewportFilterAnimationControllerImpl<T>::ViewportFilterAnimationControllerImpl( IViewportFilter* filter, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener ) :
	anim::PlaybackControllerImpl<T>( animationSystem, animation, listener ),
	_filter( filter )
{
}

template <class T>
SYNKRO_INLINE ViewportFilterAnimationControllerImpl<T>::~ViewportFilterAnimationControllerImpl()
{
}

template <class T>
SYNKRO_INLINE void ViewportFilterAnimationControllerImpl<T>::Update( Double delta )
{
	// Call base implementation.
	PlaybackControllerImpl<T>::Update( delta );

	if ( _trackRect != nullptr )
	{
		lang::Rect rect;
		_trackRect->GetValue( _time, rect );
		_filter->SetRect( rect );
	}
}

template <class T>
SYNKRO_INLINE void ViewportFilterAnimationControllerImpl<T>::SetAnimation( anim::IAnimation* animation )
{
	// Call base implementation.
	PlaybackControllerImpl<T>::SetAnimation( animation );

	_trackRect = GetTrack( _trackRect, ViewportFilterProperty::Rect );
}

template <class T>
SYNKRO_INLINE anim::IKeyframedRectTrack* ViewportFilterAnimationControllerImpl<T>::CreateRectTrack()
{
	return (_trackRect = (_trackRect == nullptr) ? _animation->CreateRectTrack(ViewportFilterProperty::Rect.ToString()) : _trackRect)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE IColorFilterAnimationController* ViewportFilterAnimationControllerImpl<T>::AsColor() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IFogFilterAnimationController* ViewportFilterAnimationControllerImpl<T>::AsFog() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IKernel3x3FilterAnimationController* ViewportFilterAnimationControllerImpl<T>::AsKernel3x3() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE ISimpleFilterAnimationController* ViewportFilterAnimationControllerImpl<T>::AsSimple() const
{
	return nullptr;
}
