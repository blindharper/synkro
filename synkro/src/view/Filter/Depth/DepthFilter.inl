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
// Purpose: Depth viewport filter implementation.
//==============================================================================
SYNKRO_INLINE void DepthFilter::SetCamera( scene::ICamera* camera )
{
	// Call base implementation.
	DepthFilterImpl<IDepthFilter>::SetCamera( camera );

	// Set camera-specific parameters.
	_params->Set( _paramFront, _camera->GetFront() );
	_params->Set( _paramBack, _camera->GetBack() );
}
