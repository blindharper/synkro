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
SYNKRO_INLINE MeshBatchAnimationControllerImpl<T,B>::MeshBatchAnimationControllerImpl( B* batch, anim::IAnimationSystem* animationSystem, anim::IAnimationSet* animations, anim::AnimationListener* listener ) :
	NodeAnimationControllerImpl<T>( batch, animationSystem, animations, listener ),
	_batch( batch ),
	_trackRange( nullptr )
{
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
		_trackRange->GetValue( CurrentTime(), range );
		_batch->SetRange( range );
	}
}

template <class T, class B>
SYNKRO_INLINE IMeshBatchAnimationController* MeshBatchAnimationControllerImpl<T,B>::AsMeshBatch() const
{
	return (IMeshBatchAnimationController*)this;
}

template <class T, class B>
SYNKRO_INLINE anim::IKeyframedRangeTrack* MeshBatchAnimationControllerImpl<T,B>::CreateRangeTrack()
{
	return (_trackRange = _animations->GetActiveAnimation()->CreateRangeTrack( MeshBatchProperty::Range.ToString()) )->AsKeyframed();
}

template <class T, class B>
SYNKRO_INLINE void MeshBatchAnimationControllerImpl<T, B>::UpdateTracks()
{
	// Call base implementation.
	NodeAnimationControllerImpl<T>::UpdateTracks();

	_trackRange = GetTrack( _trackRange, MeshBatchProperty::Range );
}
