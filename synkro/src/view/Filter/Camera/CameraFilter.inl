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
// Purpose: Camera viewport filter implementation.
//==============================================================================
SYNKRO_INLINE void CameraFilter::Update()
{
	// Set camera-specific parameters.
	_params->Set( _paramFront, _camera->GetFront() );
	_params->Set( _paramBack, _camera->GetBack() );
}

SYNKRO_INLINE ICameraFilter* CameraFilter::AsCamera() const
{
	return (ICameraFilter*)this;
}

SYNKRO_INLINE void CameraFilter::SetCamera( scene::ICamera* camera )
{
	assert( camera != nullptr );

	_camera = camera;
}

SYNKRO_INLINE scene::ICamera* CameraFilter::GetCamera() const
{
	return _camera;
}
