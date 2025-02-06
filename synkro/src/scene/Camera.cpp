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
#include "config.h"
#include "Camera.h"
#include "CameraAnimationController.h"
#include "CameraRecordController.h"
#include "ParentConstraint.h"
#include "LookAtConstraint.h"


//------------------------------------------------------------------------------

using namespace synkro::anim;
using namespace synkro::audio;
using namespace synkro::core;
using namespace synkro::input;
using namespace synkro::lang;
using namespace synkro::math;

//------------------------------------------------------------------------------


namespace synkro
{


namespace scene
{


Camera::Camera( ISceneEx* scene, IContext* context, const String& name, IAudioEnvironment* audioEnvironment, ISoundListener* listener ) :
	NodeImpl<ICamera>( scene, context, AsBaseScene(scene)->GetCameraName(name) ),
	_audioEnvironment( audioEnvironment ),
	_listener( listener ),
	_horzFieldOfView( Math::QuarterPi ),
	_aspect( 1.0f ),
	_front( 0.1f ),
	_back( 1000.0f ),
	_eyeDist( 0.0f ),
	_viewTransformDirty( true ),
	_invViewProjectionDirty( true ),
	_target( Vector3::Invalid ),
	_planesDirty( true )
{
	UpdateProjectionTransform();
	UpdateListener( true, false );
}

Camera::Camera( const Camera& other ) :
	NodeImpl<ICamera>( other._scene, other._context, AsBaseScene(other._scene)->GetCameraName(other._name) ),
	_audioEnvironment( other._audioEnvironment ),
	_listener( (other._listener != nullptr) ? other._listener->Clone() : nullptr ),
	_horzFieldOfView( other._horzFieldOfView ),
	_aspect( other._aspect ),
	_front( other._front ),
	_back( other._back ),
	_eyeDist( other._eyeDist ),
	_target( other._target ),
	_planesDirty( other._planesDirty )
{
	UpdateProjectionTransform();
	UpdateListener( true, false );
}

INodeAnimationController* Camera::CreateAnimationController( IAnimation* animation, AnimationListener* listener )
{
	return (_ctrlAnimation == nullptr) ? _ctrlAnimation = new CameraAnimationController( this, _context->GetAnimationSystem(), animation, listener ) : _ctrlAnimation;
}

IParentConstraint* Camera::CreateParentConstraint( INode* parent, const Matrix4x4& transform )
{
	return (_parentConstraint == nullptr) ? _parentConstraint = new ParentConstraint( this, parent, transform ) : _parentConstraint;
}

ILookAtConstraint* Camera::CreateLookAtConstraint( INode* target )
{
	return (_lookAtConstraint == nullptr) ? _lookAtConstraint = new LookAtConstraint( _context->GetGraphicsSystem(), this, target ) : _lookAtConstraint;
}

ICameraRecordController* Camera::CreateRecordController( IAnimation* animation )
{
	return (_ctrlRecord == nullptr) ? _ctrlRecord = new CameraRecordController( this, _context->GetAnimationSystem(), animation ) : _ctrlRecord;
}

Float Camera::GetVerticalFieldOfView() const
{
	Float vx; Float vy; Float front;
	GetViewDimensions( vx, vy, front );
	const Float tan = 0.5*vy/front;
	return 2.0f*Math::Atan( tan );
}

void Camera::GetViewTransform( Matrix4x4& transform ) const
{
	UpdateViewTransform();
	transform = _viewTransform;
}

Bool Camera::IsInView( const Vector3& center, Float radius ) const
{
	Matrix4x4 worldTransform;
	GetWorldTransform( worldTransform );
	_worldToCamera = worldTransform.Inverse();
	const Vector3 centerInCamera = _worldToCamera * center;

	UpdatePlanes();
	for ( UInt i = 0; i < PLANE_COUNT; ++i )
	{
		const Vector4 p
		(
			centerInCamera.x - _planes[i].x*radius,
			centerInCamera.y - _planes[i].y*radius,
			centerInCamera.z - _planes[i].z*radius,
			1.0f
		);
		const Float d = p*_planes[i];
		if ( d > 0.0f )
			return false;
	}

	return true;
}

void Camera::Update()
{
	NodeImpl<ICamera>::ApplyConstraints( _ctrlAnimation );
}

void Camera::Activate()
{
	if ( _audioEnvironment != nullptr )
	{
		_audioEnvironment->SetListener( _listener );
	}
}

void Camera::UpdateViewTransform() const
{
	Matrix4x4 worldTransform;
	GetWorldTransform( worldTransform );
	const Vector3 eye = worldTransform.Translation();
	const Vector3 target = (_target != Vector3::Invalid) ? _target : eye + worldTransform.Forward().Normalize();
	_viewTransform.SetLookAt( target, eye, Vector3::Y );

	Vector3 right = target^Vector3::Y;
	if ( right.Length() > 0.0f )
	{
		right.Normalize();
	}
	else
	{
		right = Vector3::X;
	}

	if ( _eyeDist != 0.0f )
	{
		const Vector3 eyeLeft = eye - right*_eyeDist/2.0f;
		_viewTransformLeft.SetLookAt( target, eyeLeft, Vector3::Y );

		const Vector3 eyeRight = eye + right*_eyeDist/2.0f;
		_viewTransformRight.SetLookAt( target, eyeRight, Vector3::Y );
	}

	_invViewProjectionDirty = true;
	_viewTransformDirty = false;
}

void Camera::UpdateProjectionTransform()
{
	_projectionTransform.SetPerspectiveProjection( _horzFieldOfView, _aspect, _front, _back );
	_invViewProjectionDirty = true;
}

void Camera::UpdateListener( Bool position, Bool direction )
{
	if ( _listener != nullptr )
	{
		Matrix4x4 worldTransform;
		GetWorldTransform( worldTransform );

		if ( position )
		{
			_listener->SetPosition( worldTransform.Translation() );
		}

		if ( direction )
		{
			const Vector3 eye = worldTransform.Translation();
			const Vector3 dir = (_target != Vector3::Invalid) ? (_target - eye).Normalize() : worldTransform.Forward().Normalize();
			_listener->SetDirection( dir );
		}
	}
}

void Camera::UpdatePlanes() const
{
	if ( _planesDirty )
	{
		const Float halfFovHorz = _horzFieldOfView*0.5f;
		const Float halfFovVert = GetVerticalFieldOfView()*0.5f;
		const Vector3 rightPlaneNormalOut = -Vector3::X.Rotate( Vector3::Y, halfFovHorz );
		const Vector3 leftPlaneNormalOut = Vector3::X.Rotate( Vector3::Y, -halfFovHorz );
		const Vector3 topPlaneNormalOut = Vector3::Y.Rotate( -Vector3::X, -halfFovVert );		
		const Vector3 bottomPlaneNormalOut = -Vector3::Y.Rotate( -Vector3::X, halfFovVert );

		_planes[0] = Vector4( rightPlaneNormalOut, 0.0f );
		_planes[1] = Vector4( leftPlaneNormalOut, 0.0f );
		_planes[2] = Vector4( topPlaneNormalOut, 0.0f );
		_planes[3] = Vector4( bottomPlaneNormalOut, 0.0f );
		_planes[4] = Vector4( Vector3::Z, _front );
		_planes[5] = Vector4( -Vector3::Z, -_back );

		_planesDirty = false;
	}
}

void Camera::GetViewDimensions( Float& x, Float& y, Float& z ) const
{
	const Float w = Math::Abs( 1.0f/Math::Tan(_horzFieldOfView*0.5f) );
	const Float vw = 2.0f*_front/w;
	const Float vh = vw/_aspect;

	x = vw;
	y = vh;
	z = _front;
}


} // scene


} // synkro
