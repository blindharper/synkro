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
// Purpose: Camera record controller implementation.
//==============================================================================
#include "config.h"
#include "CameraRecordController.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


CameraRecordController::CameraRecordController( ICamera* camera, IAnimationSystem* animationSystem, IAnimation* animation ) :
	NodeRecordControllerImpl<ICameraRecordController>( camera, animationSystem, animation ),
	_camera( camera )
{
}

void CameraRecordController::Update( Double delta )
{
	// Call base implementation.
	NodeRecordControllerImpl<ICameraRecordController>::Update( delta );

	// Save camera parameters.
	if ( _trackFov != nullptr )
	{
		const Float fov = _camera->GetHorizontalFieldOfView();
		_trackFov->SetKey( _time, fov );
	}
}

IKeyframedFloatTrack* CameraRecordController::CreateFieldOfViewTrack()
{
	return (_trackFov == nullptr) ? _trackFov = _animation->CreateFloatTrack( CameraProperty::FieldOfView.ToString() ) : _trackFov;
}


} // scene


} // synkro
