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
// Purpose: Camera node implementation.
//==============================================================================
SYNKRO_INLINE void Camera::SetTransform( const math::Matrix4x4& transform )
{
	// Call base implementation.
	NodeImpl<ICamera>::SetTransform( transform );

	_viewTransformDirty = true;
	_invViewProjectionDirty = true;
	UpdateListener( true, false );
}

SYNKRO_INLINE void Camera::SetPosition( const math::Vector3& position )
{
	// Call base implementation.
	NodeImpl<ICamera>::SetPosition( position );

	_viewTransformDirty = true;
	_invViewProjectionDirty = true;
	UpdateListener( true, false );
}

SYNKRO_INLINE void Camera::SetPositionX( Float x )
{
	// Call base implementation.
	NodeImpl<ICamera>::SetPositionX( x );

	_viewTransformDirty = true;
	_invViewProjectionDirty = true;
	UpdateListener( true, false );
}

SYNKRO_INLINE void Camera::SetPositionY( Float y )
{
	// Call base implementation.
	NodeImpl<ICamera>::SetPositionY( y );

	_viewTransformDirty = true;
	_invViewProjectionDirty = true;
	UpdateListener( true, false );
}

SYNKRO_INLINE void Camera::SetPositionZ( Float z )
{
	// Call base implementation.
	NodeImpl<ICamera>::SetPositionZ( z );

	_viewTransformDirty = true;
	_invViewProjectionDirty = true;
	UpdateListener( true, false );
}

SYNKRO_INLINE void Camera::SetOrientation( const math::Quaternion& orientation )
{
	// Call base implementation.
	NodeImpl<ICamera>::SetOrientation( orientation );

	_viewTransformDirty = true;
	_invViewProjectionDirty = true;
	UpdateListener( false, true );
}

SYNKRO_INLINE void Camera::SetOrientationYaw( Float yaw )
{
	// Call base implementation.
	NodeImpl<ICamera>::SetOrientationYaw( yaw );

	_viewTransformDirty = true;
	_invViewProjectionDirty = true;
	UpdateListener( false, true );
}

SYNKRO_INLINE void Camera::SetOrientationPitch( Float pitch )
{
	NodeImpl<ICamera>::SetOrientationPitch( pitch );

	_viewTransformDirty = true;
	_invViewProjectionDirty = true;
	UpdateListener( false, true );
}

SYNKRO_INLINE void Camera::SetOrientationRoll( Float roll )
{
	NodeImpl<ICamera>::SetOrientationRoll( roll );

	_viewTransformDirty = true;
	_invViewProjectionDirty = true;
	UpdateListener( false, true );
}

SYNKRO_INLINE void Camera::LookAt( const math::Vector3& target )
{
	NodeImpl<ICamera>::LookAt( target );

	_target = target;

	_viewTransformDirty = true;
	_invViewProjectionDirty = true;
	UpdateListener( false, true );
}

SYNKRO_INLINE ICamera* Camera::AsCamera() const
{
	return (ICamera*)this;
}

SYNKRO_INLINE void Camera::SetHorizontalFieldOfView( Float fieldOfView )
{
	fieldOfView = Clamp( fieldOfView, 0.0f, math::Math::Pi );

	if ( fieldOfView != _horzFieldOfView )
	{
		_horzFieldOfView = fieldOfView;
		UpdateProjectionTransform();
		_planesDirty = true;
	}
}

SYNKRO_INLINE void Camera::SetAspect( Float aspect )
{
	if ( aspect != _aspect )
	{
		_aspect = aspect;
		UpdateProjectionTransform();
		_planesDirty = true;
	}
}

SYNKRO_INLINE void Camera::SetFront( Float front )
{
	if ( front != _front )
	{
		if ( _back < front )
			throw lang::InvalidOperationException( L"Near plane cannot be farther than the far plane." );

		_front = front;
		UpdateProjectionTransform();
		_planesDirty = true;
	}
}

SYNKRO_INLINE void Camera::SetBack( Float back )
{
	if ( back != _back )
	{
		if ( back < _front )
			throw lang::InvalidOperationException( L"Near plane cannot be farther than the far plane." );

		_back = back;
		UpdateProjectionTransform();
		_planesDirty = true;
	}
}

SYNKRO_INLINE void Camera::SetEyeDistance( Float distance )
{
	_eyeDist = distance;
}

SYNKRO_INLINE Float Camera::GetHorizontalFieldOfView() const
{
	return _horzFieldOfView;
}

SYNKRO_INLINE Float Camera::GetAspect() const
{
	return _aspect;
}

SYNKRO_INLINE Float Camera::GetFront() const
{
	return _front;
}

SYNKRO_INLINE Float Camera::GetBack() const
{
	return _back;
}

SYNKRO_INLINE Float Camera::GetEyeDistance() const
{
	return _eyeDist;
}

SYNKRO_INLINE void Camera::GetLeftViewTransform( math::Matrix4x4& transform ) const
{
	transform = _viewTransformLeft;
}

SYNKRO_INLINE void Camera::GetRightViewTransform( math::Matrix4x4& transform ) const
{
	transform = _viewTransformRight;
}

SYNKRO_INLINE void Camera::GetProjectionTransform( math::Matrix4x4& transform ) const
{
	transform = _projectionTransform;
}

SYNKRO_INLINE void Camera::GetInverseViewProjectionTransform( math::Matrix4x4& transform ) const
{
	if ( _invViewProjectionDirty )
	{
		math::Matrix4x4 transViewProj( _projectionTransform * _viewTransform );
		_invViewProjection = transViewProj.Inverse();
		_invViewProjectionDirty = false;
	}
	transform = _invViewProjection;
}
