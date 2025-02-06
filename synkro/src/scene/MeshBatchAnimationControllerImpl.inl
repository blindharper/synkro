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
// Purpose: Generic mesh batch animation controller implementation.
//==============================================================================
template <class T, class B>
SYNKRO_INLINE MeshBatchAnimationControllerImpl<T,B>::MeshBatchAnimationControllerImpl( B* batch, anim::IAnimationSystem* animationSystem, anim::IAnimation* animation, anim::AnimationListener* listener ) :
	NodeAnimationControllerImpl<T>( batch, animationSystem, animation, listener ),
	_batch( batch )
{
	SetAnimation( _animation );
}

template <class T, class B>
SYNKRO_INLINE MeshBatchAnimationControllerImpl<T,B>::~MeshBatchAnimationControllerImpl()
{
}

template <class T, class B>
SYNKRO_INLINE void MeshBatchAnimationControllerImpl<T,B>::Update( Double delta )
{
	// Call base implementation.
	NodeAnimationControllerImpl<T>::Update( delta );

	// Update mesh batch.
	if ( _trackRange != nullptr )
	{
		lang::Range range;
		_trackRange->GetValue( _time, range );
		_batch->SetRange( range );
	}
}

template <class T, class B>
SYNKRO_INLINE void MeshBatchAnimationControllerImpl<T, B>::SetAnimation( anim::IAnimation* animation )
{
	// Call base implementation.
	NodeAnimationControllerImpl<T>::SetAnimation( animation );

	_trackRange = GetTrack( _trackRange, MeshBatchProperty::Range );
}

template <class T, class B>
SYNKRO_INLINE IMeshBatchAnimationController* MeshBatchAnimationControllerImpl<T,B>::AsMeshBatch() const
{
	return (IMeshBatchAnimationController*)this;
}

template <class T, class B>
SYNKRO_INLINE anim::IKeyframedRangeTrack* MeshBatchAnimationControllerImpl<T,B>::CreateRangeTrack()
{
	return (_trackRange = (_trackRange == nullptr) ? _animation->CreateRangeTrack(MeshBatchProperty::Range.ToString()) : _trackRange)->AsKeyframed();
}
