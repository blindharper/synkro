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
// Purpose: Motion blur viewport filter implementation.
//==============================================================================
SYNKRO_INLINE void MotionBlurFilter::Update()
{
	_params->Set( _paramPrevViewProj, _transViewProj );
	_camera->GetInverseViewProjectionTransform( _transViewProj );
	_params->Set( _paramInvViewProj, _transViewProj );
}

SYNKRO_INLINE IMotionBlurFilter* MotionBlurFilter::AsMotionBlur() const
{
	return (IMotionBlurFilter*)this;
}

SYNKRO_INLINE void MotionBlurFilter::SetSampleCount( UInt count )
{
	_params->Set( _paramSampleCount, (Int)count );
}

SYNKRO_INLINE UInt MotionBlurFilter::GetSampleCount() const
{
	Int value = 0;
	_params->Get( _paramSampleCount, &value );
	return CastUInt(value);
}
