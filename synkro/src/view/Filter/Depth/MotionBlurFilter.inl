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
	_params->Set( _paramPrevViewProj, _transPrevViewProj );

	math::Matrix4x4 transInverseViewProjection;
	_camera->GetInverseViewProjectionTransform( transInverseViewProjection );
	_params->Set( _paramInvViewProj, transInverseViewProjection );

	math::Matrix4x4 transView;
	_camera->GetViewTransform( transView );
	math::Matrix4x4 transProjection;
	_camera->GetProjectionTransform( transProjection );
	_transPrevViewProj = transProjection*transView;
}

SYNKRO_INLINE IMotionBlurFilter* MotionBlurFilter::AsMotionBlur() const
{
	return (IMotionBlurFilter*)this;
}

SYNKRO_INLINE void MotionBlurFilter::SetSampleCount( UInt count )
{
	_params->Set( _paramSampleCount, CastInt(count) );
}

SYNKRO_INLINE UInt MotionBlurFilter::GetSampleCount() const
{
	Int value = 0;
	_params->Get( _paramSampleCount, &value );
	return CastUInt(value);
}
