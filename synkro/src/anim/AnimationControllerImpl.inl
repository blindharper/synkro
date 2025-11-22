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
SYNKRO_INLINE AnimationControllerImpl<T>::AnimationControllerImpl( IAnimationSystem* animationSystem, IAnimationSet* animations )
{
	if ( animationSystem == nullptr )
		throw lang::InvalidOperationException( L"Animation system is disabled." );

	_animationSystem = AsBaseAnimationSystem( animationSystem );
	_animations = (animations != nullptr) ? animations : animationSystem->CreateAnimationSet( L"Default" );
	if ( _animations->GetActiveAnimation() == nullptr )
	{
		_animations->CreateAnimation( L"Default" );
	}
	_animationSystem->AddController( this );
}

template <class T>
SYNKRO_INLINE AnimationControllerImpl<T>::~AnimationControllerImpl()
{
	_animationSystem->RemoveController( this );
}

template <class T>
SYNKRO_INLINE void AnimationControllerImpl<T>::SetAnimations( IAnimationSet* animations )
{
	assert( animations != nullptr );

	if ( animations == nullptr )
		throw lang::BadArgumentException( L"Bad animation sequence", L"animations", L"nullptr" );

	if ( animations->GetAnimationCount() == 0 )
		throw lang::BadArgumentException( L"Empty animation sequence", L"animations", L"0" );

	_animations = animations;
}

template <class T>
SYNKRO_INLINE IAnimationSet* AnimationControllerImpl<T>::GetAnimations() const
{
	return _animations;
}
