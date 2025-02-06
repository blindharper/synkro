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
// Purpose: Generic implementation of animation controller for kernel 3x3 filter.
//==============================================================================
template <class T>
SYNKRO_INLINE Kernel3x3FilterAnimationControllerImpl<T>::Kernel3x3FilterAnimationControllerImpl( IKernel3x3Filter* kernel3x3Filter, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener ) :
	ViewportFilterAnimationControllerImpl<T>( kernel3x3Filter, animationSystem, animation, listener ),
	_kernel3x3Filter( kernel3x3Filter )
{
}

template <class T>
SYNKRO_INLINE void Kernel3x3FilterAnimationControllerImpl<T>::Update( Double delta )
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<T>::Update( delta );

	// Update filter.
	if ( _trackPassCount != nullptr )
	{
		Int count;
		_trackPassCount->GetValue( _time, count );
		_kernel3x3Filter->SetPassCount( count );
	}
}

template <class T>
SYNKRO_INLINE void Kernel3x3FilterAnimationControllerImpl<T>::SetAnimation( anim::IAnimation* animation )
{
	// Call base implementation.
	ViewportFilterAnimationControllerImpl<T>::SetAnimation( animation );

	_trackPassCount = GetTrack( _trackPassCount, Kernel3x3FilterProperty::PassCount );
}

template <class T>
SYNKRO_INLINE IKernel3x3FilterAnimationController* Kernel3x3FilterAnimationControllerImpl<T>::AsKernel3x3() const
{
	return (IKernel3x3FilterAnimationController*)this;
}

template <class T>
SYNKRO_INLINE anim::IKeyframedIntTrack* Kernel3x3FilterAnimationControllerImpl<T>::CreatePassCountTrack()
{
	return (_trackPassCount = (_trackPassCount == nullptr) ? _animation->CreateIntTrack(Kernel3x3FilterProperty::PassCount.ToString()) : _trackPassCount)->AsKeyframed();
}

template <class T>
SYNKRO_INLINE IEmbossFilterAnimationController* Kernel3x3FilterAnimationControllerImpl<T>::AsEmboss() const
{
	return nullptr;
}
