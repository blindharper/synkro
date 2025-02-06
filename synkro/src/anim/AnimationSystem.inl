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
// Purpose: Implements animation system.
//==============================================================================
SYNKRO_INLINE void AnimationSystem::AddController( IPlaybackAnimationController* controller )
{
	assert( controller != nullptr );

	_playbackControllers.Add( controller );
}

SYNKRO_INLINE void AnimationSystem::AddController( IRecordAnimationController* controller )
{
	assert( controller != nullptr );

	_recordControllers.Add( RecordControllerDesc(controller) );
}

SYNKRO_INLINE void AnimationSystem::RemoveController( IPlaybackAnimationController* controller )
{
	assert( controller != nullptr );

	_playbackControllers.Remove( controller );
}

SYNKRO_INLINE void AnimationSystem::AddStopEvent( IAnimationController* sender, AnimationListener* listener )
{
	assert( sender != nullptr );
	assert( listener != nullptr );

	_events.Add( AnimationEvent(ANIMATION_EVENT_STOP, sender, listener) );
}

SYNKRO_INLINE void AnimationSystem::AddLoopEvent( IAnimationController* sender, AnimationListener* listener )
{
	assert( sender != nullptr );
	assert( listener != nullptr );

	_events.Add( AnimationEvent(ANIMATION_EVENT_LOOP, sender, listener) );
}

SYNKRO_INLINE void AnimationSystem::SetThreadPool( core::ThreadPool* threadPool )
{
	_threadPool = threadPool;
}
