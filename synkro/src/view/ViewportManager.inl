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
// Purpose: Viewport manager implementation.
//==============================================================================
SYNKRO_INLINE UInt ViewportManager::GetViewportCount() const
{
	return _viewports.Size();
}

SYNKRO_INLINE IViewport* ViewportManager::GetViewport( UInt index ) const
{
	assert( index < _viewports.Size() );

	if ( index >= _viewports.Size() )
		throw lang::OutOfRangeException( index, _viewports.Size() );

	return _viewports[index]->AsViewport();
}

SYNKRO_INLINE IViewport* ViewportManager::GetViewport( gfx::IRenderView* view ) const
{
	assert( view != nullptr );

	if ( view == nullptr )
		throw lang::BadArgumentException( L"Bad view", L"view", L"nullptr" );

	return _views.ContainsKey(view->ID()) ? _views[view->ID()]->AsViewport() : nullptr;
}

SYNKRO_INLINE IViewport* ViewportManager::GetActiveViewport() const
{
	return (_activeViewport != nullptr) ? _activeViewport->AsViewport() : nullptr;
}

SYNKRO_INLINE void ViewportManager::RemoveViewport( BaseViewport* viewport )
{
	_viewports.Remove( viewport );
}

SYNKRO_INLINE void ViewportManager::AddTransitionController( BaseViewportTransitionController* controller )
{
	_transitionControllers.Add( controller );
}

SYNKRO_INLINE void ViewportManager::RemoveTransitionController( BaseViewportTransitionController* controller )
{
	_transitionControllers.Remove( controller );
}

SYNKRO_INLINE void ViewportManager::AddStopEvent( IViewportTransitionController* sender, ViewportListener* listener )
{
	assert( sender != nullptr );
	assert( listener != nullptr );

	_transitionEvents.Add( TransitionEvent(TRANSITION_EVENT_STOP, sender, listener) );
}

SYNKRO_INLINE void ViewportManager::AddLoopEvent( IViewportTransitionController* sender, ViewportListener* listener )
{
	assert( sender != nullptr );
	assert( listener != nullptr );

	_transitionEvents.Add( TransitionEvent(TRANSITION_EVENT_LOOP, sender, listener) );
}

SYNKRO_INLINE Bool ViewportManager::Call( BaseViewport* viewport )
{
	viewport->Update();
	return true;
}
