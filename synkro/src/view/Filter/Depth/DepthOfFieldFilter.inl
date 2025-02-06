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
// Purpose: Depth-of-field viewport filter implementation.
//==============================================================================
SYNKRO_INLINE IDepthOfFieldFilter* DepthOfFieldFilter::AsDepthOfField() const
{
	return (IDepthOfFieldFilter*)this;
}

SYNKRO_INLINE void DepthOfFieldFilter::SetFocalDistance( Float distance )
{
	if ( distance < 0.0f )
	{
		distance = -distance;
	}

	_focalPlane.w = -distance;
	_params->Set( _paramFocalPlane, _focalPlane );
}

SYNKRO_INLINE Float DepthOfFieldFilter::GetFocalDistance() const
{
	return _focalPlane.w;
}
