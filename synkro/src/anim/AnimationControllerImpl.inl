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
// Purpose: Generic animation controller implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE AnimationControllerImpl<T>::AnimationControllerImpl( IAnimationSystem* animationSystem, IAnimation* animation )
{
	if ( animationSystem == nullptr )
		throw lang::InvalidOperationException( L"Animation system is disabled." );

	_animationSystem = AsBaseAnimationSystem( animationSystem );
	_animation = (animation != nullptr) ? animation : animationSystem->CreateAnimation();
	_animationSystem->AddController( this );
}

template <class T>
SYNKRO_INLINE AnimationControllerImpl<T>::~AnimationControllerImpl()
{
	_animationSystem->RemoveController( this );
}

template <class T>
SYNKRO_INLINE void AnimationControllerImpl<T>::SetAnimation( IAnimation* animation )
{
	assert( animation != nullptr );

	if ( animation == nullptr )
		throw lang::BadArgumentException( L"Bad animation", L"animation", L"nullptr" );

	_animation = animation;
}

template <class T>
SYNKRO_INLINE IAnimation* AnimationControllerImpl<T>::GetAnimation() const
{
	return _animation;
}
