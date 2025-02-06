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
// Purpose: Animation controller for camera.
//==============================================================================
#include "config.h"
#include "CameraAnimationController.h"
#include "CameraProperty.h"
#include <scene/ICamera.h>


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::core;
using namespace synkro::lang;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


CameraAnimationController::CameraAnimationController( ICamera* camera, IAnimationSystem* animationSystem, IAnimation* animation, AnimationListener* listener ) :
	NodeAnimationControllerImpl<ICameraAnimationController>( camera, animationSystem, animation, listener ),
	_camera( camera )
{
	SetAnimation( _animation );
}

void CameraAnimationController::Update( Double delta )
{
	// Call base implementation.
	NodeAnimationControllerImpl<ICameraAnimationController>::Update( delta );

	// Update camera.
	if ( _trackFieldOfView != nullptr )
	{
		Float fov;
		_trackFieldOfView->GetValue( _time, fov );
		_camera->SetHorizontalFieldOfView( fov );
	}
}

void CameraAnimationController::SetAnimation( IAnimation* animation )
{
	// Call base implementation.
	NodeAnimationControllerImpl<ICameraAnimationController>::SetAnimation( animation );

	_trackFieldOfView = GetTrack( _trackFieldOfView, CameraProperty::FieldOfView );
}

ICameraAnimationController* CameraAnimationController::AsCamera() const
{
	return (ICameraAnimationController*)this;
}

IKeyframedFloatTrack* CameraAnimationController::CreateFieldOfViewTrack()
{
	return (_trackFieldOfView = (_trackFieldOfView == nullptr) ? _animation->CreateFloatTrack(CameraProperty::FieldOfView.ToString()) : _trackFieldOfView)->AsKeyframed();
}

IProceduralFloatTrack* CameraAnimationController::CreateFieldOfViewTrack( const AnimationTrack& type )
{
	return (_trackFieldOfView = (_trackFieldOfView == nullptr) ? _animation->CreateFloatTrack(CameraProperty::FieldOfView.ToString(), type) : _trackFieldOfView)->AsProcedural();
}

IExpressionFloatTrack* CameraAnimationController::CreateFieldOfViewTrack( IExpressionScript* script )
{
	return (_trackFieldOfView = (_trackFieldOfView == nullptr) ? _animation->CreateFloatTrack(CameraProperty::FieldOfView.ToString(), script) : _trackFieldOfView)->AsExpression();
}

IExpressionFloatTrack* CameraAnimationController::CreateFieldOfViewTrack( const String& expression )
{
	return (_trackFieldOfView = (_trackFieldOfView == nullptr) ? _animation->CreateFloatTrack(CameraProperty::FieldOfView.ToString(), expression) : _trackFieldOfView)->AsExpression();
}


} // scene


} // synkro
