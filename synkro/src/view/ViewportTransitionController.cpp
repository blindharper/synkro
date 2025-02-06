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
// Purpose: Viewport transition controller implementation.
//==============================================================================
#include "config.h"
#include "ViewportTransitionController.h"
#include "TransitionEffectConst.h"


//------------------------------------------------------------------------------

using namespace synkro::core;
using namespace synkro::img;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace view
{


ViewportTransitionController::ViewportTransitionController( BaseViewportManager* viewportManager, ViewportListener* listener ) :
	_keys( A(Key) ),
	_viewportManager( viewportManager ),
	_listener( listener ),
	_length( 0.0 ),
	_loopCount( 0 ),
	_iteration( 0 )
{
	_viewportManager->AddTransitionController( this );
}

ViewportTransitionController::~ViewportTransitionController()
{
	_viewportManager->RemoveTransitionController( this );
}

void ViewportTransitionController::Start( Bool start )
{
	switch ( _state )
	{
		case CONTROLLER_STATE_INACTIVE:
			if ( start )
			{
				_iteration = 0;
				_length = GetLength();
				_state = ControllerState::Active;
				Prepare();
			}
			break;

		default:
			if ( !start )
			{
				_time = GetLength();
				_state = core::ControllerState::Inactive;
				if ( _listener != nullptr )
				{
					_viewportManager->AddStopEvent( this, _listener );
				}
				Prepare();
			}
			break;
	}
}

void ViewportTransitionController::Update( Double delta )
{
	// Call base implementation.
	ControllerImpl<IViewportTransitionController>::Update( delta );

	if ( _keys.Size() > 1 )
	{
		UInt key1 = none; UInt key2 = none;
		if ( GetFork(_time, key1, key2) )
		{
			Double d = 0.0;
			IViewport* viewport1 = _keys[key1].Viewport;
			IViewport* viewport2 = _keys[key2].Viewport;
			switch ( _keys[key2].Effect )
			{
				case TRANSITION_EFFECT_STEP:
					if ( viewport1 != viewport2 )
					{
						viewport1->SetOpacity( 0.0f );
					}
					viewport2->SetOpacity( 1.0f );
					break;

				case TRANSITION_EFFECT_BLEND:
					d = (_time - _keys[key1].Time)/(_keys[key2].Time - _keys[key1].Time);
					if ( viewport1 != viewport2 )
					{
						viewport1->SetOpacity( CastFloat(1.0-d) );
					}
					viewport2->SetOpacity( CastFloat(d) );
					break;
			}
		}
	}
}

void ViewportTransitionController::SetKey( Double time, IViewport* viewport, const TransitionEffect& effect )
{
	assert( viewport != nullptr );

	// Make sure all viewports in the controller have identical size.
	if ( _keys.Size() > 0 )
	{
		Size size0; Size size;
		_keys[0].Viewport->GetSize( size0 );
		viewport->GetSize( size );
		if ( size != size0 )
			throw Exception( L"All viewports in the controller must have identical size." );
	}

	// Add the key.
	if ( time >= GetLength() )
	{
		_keys.Add( Key(time, viewport, effect) );
	}
	else
	{
		const UInt count = _keys.Size();
		for ( UInt i = 0; i < count; ++i )
		{
			if ( _keys[i].Time == time )
			{
				_keys[i].Viewport	= viewport;
				_keys[i].Effect		= effect;
				return;
			}
		}

		_keys.SetSize( count+1 );
		_keys[count-1] = _keys[count-2];

		for ( UInt i = 0, j = 0; i < count-2; ++i, ++j )
		{
			if ( (_keys[i].Time < time) && (time < _keys[i+1].Time) )
			{
				_keys[j] = Key( time, viewport, effect );
			}
			else
			{
				_keys[j] = _keys[i];
			}
		}
	}
}

void ViewportTransitionController::SetKey( Double time, IViewport* viewport )
{
	SetKey( time, viewport, TransitionEffect::Step );
}

void ViewportTransitionController::PostUpdate()
{
	if ( _time > _length )
	{
		if ( (++_iteration < _loopCount) || (_loopCount == 0) )
		{
			ControllerImpl<IViewportTransitionController>::Reset();
			if ( _listener != nullptr )
			{
				_viewportManager->AddLoopEvent( this, _listener );
			}
		}
		else
		{
			Start( false );
		}
	}
}

Bool ViewportTransitionController::GetFork( Double time, UInt& key1, UInt& key2 ) const
{
	key1 = none; key2 = none;

	for ( UInt i = 0; i < _keys.Size(); ++i )
	{
		if ( time > _keys[i].Time )
		{
			key1 = i;
		}
		else if ( time < _keys[i].Time )
		{
			key2 = i;
		}
		else if ( time == _keys[i].Time )
		{
			key1 = i;
			return false;
		}

		if ( (key1 != none) && (key2 != none) )
			return true;
	}

	key1 = 0;
	key2 = _keys.Size()-1;
	return false;
}

void ViewportTransitionController::Prepare()
{
	// Show the very first viewport and hide all other.
	for ( UInt i = 1; i < _keys.Size(); ++i )
	{
		_keys[i].Viewport->SetOpacity( 0.0f );
	}
	if ( _keys.Size() > 0 )
	{
		_keys[0].Viewport->SetOpacity( 1.0f );
	}
}


} // view


} // synkro
