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
// Purpose: Generic depth-based viewport filter implementation.
//==============================================================================
template <class T>
SYNKRO_INLINE DepthFilterImpl<T>::DepthFilterImpl( IViewport* viewport, anim::IAnimationSystem* animationSystem, gfx::IProgram* program ) :
	ViewportFilterImpl<T>( viewport, animationSystem, program ),
	_camera( nullptr )
{
	_filter->SetInput( _viewport->GetView()->GetDepthTarget() );

	_paramInvViewProj = _params->GetParam( L"p_invViewProj" );
	_resources = _filter->GetProgram()->GetFragmentStage()->GetResources()->Clone( _filter->ID() );
	_filter->SetFragmentResources( _resources );
}

template <class T>
SYNKRO_INLINE DepthFilterImpl<T>::~DepthFilterImpl()
{
}

template <class T>
SYNKRO_INLINE void DepthFilterImpl<T>::Update()
{
	if ( _paramInvViewProj != nullptr )
	{
		math::Matrix4x4 transInvViewProj;
		_camera->GetInverseViewProjectionTransform( transInvViewProj );
		_params->Set( _paramInvViewProj, transInvViewProj );
	}
}

template <class T>
SYNKRO_INLINE IDepthFilter* DepthFilterImpl<T>::AsDepth() const
{
	return (IDepthFilter*)this;
}

template <class T>
SYNKRO_INLINE void DepthFilterImpl<T>::SetCamera( scene::ICamera* camera )
{
	assert( camera != nullptr );

	_camera = camera;
}

template <class T>
SYNKRO_INLINE scene::ICamera* DepthFilterImpl<T>::GetCamera() const
{
	return _camera;
}

template <class T>
SYNKRO_INLINE IDepthOfFieldFilter* DepthFilterImpl<T>::AsDepthOfField() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IFogFilter* DepthFilterImpl<T>::AsFog() const
{
	return nullptr;
}

template <class T>
SYNKRO_INLINE IMotionBlurFilter* DepthFilterImpl<T>::AsMotionBlur() const
{
	return nullptr;
}
