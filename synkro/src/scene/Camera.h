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
#ifndef _SYNKRO_SCENE_CAMERA_
#define _SYNKRO_SCENE_CAMERA_


#include "config.h"
#include "NodeImpl.h"
#include <scene/ICamera.h>
#include <scene/ICameraAnimationController.h>
#include <scene/ICameraRecordController.h>
#include <audio/IAudioEnvironment.h>
#include <audio/ISoundListener.h>
#include <math/Math.h>
#include "BaseNode.h"
#include "BaseCamera.h"


namespace synkro
{


namespace scene
{


// Camera node implementation.
class Camera :
	public NodeImpl<ICamera>,
	public BaseNode,
	public BaseCamera
{
public:
	// Constructors.
	Camera( ISceneEx* scene, core::IContext* context, const lang::String& name, audio::IAudioEnvironment* audioEnvironment, audio::ISoundListener* listener );
	Camera( const Camera& other );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	IParentConstraint*										CreateParentConstraint( INode* parent, const math::Matrix4x4& transform );
	ILookAtConstraint*										CreateLookAtConstraint( INode* target );
	void													SetTransform( const math::Matrix4x4& transform );
	void													SetPosition( const math::Vector3& position );
	void													SetPositionX( Float x );
	void													SetPositionY( Float y );
	void													SetPositionZ( Float z );
	void													SetOrientation( const math::Quaternion& orientation );
	void													SetOrientationYaw( Float yaw );
	void													SetOrientationPitch( Float pitch );
	void													SetOrientationRoll( Float roll );
	void													LookAt( const math::Vector3& target );
	ICamera*												AsCamera() const;

	// ICamera methods.
	ICameraRecordController*								CreateRecordController( anim::IAnimation* animation );
	void													SetHorizontalFieldOfView( Float fieldOfView );
	void													SetAspect( Float aspect );
	void													SetFront( Float front );
	void													SetBack( Float back );
	void													SetEyeDistance( Float distance );
	Float													GetVerticalFieldOfView() const;
	Float													GetHorizontalFieldOfView() const;
	Float													GetAspect() const;
	Float													GetFront() const;
	Float													GetBack() const;
	Float													GetEyeDistance() const;
	void													GetViewTransform( math::Matrix4x4& transform ) const;
	void													GetLeftViewTransform( math::Matrix4x4& transform ) const;
	void													GetRightViewTransform( math::Matrix4x4& transform ) const;
	void													GetProjectionTransform( math::Matrix4x4& transform ) const;
	void													GetInverseViewProjectionTransform( math::Matrix4x4& transform ) const;
	Bool													IsInView( const math::Vector3& center, Float radius ) const;

	// BaseNode methods.
	void													Update();

	// BaseCamera methods.
	void													Activate();

private:
	enum
	{
		PLANE_COUNT = 6
	};

	P(ICameraAnimationController)							_ctrlAnimation;
	P(ICameraRecordController)								_ctrlRecord;
	audio::IAudioEnvironment*								_audioEnvironment;
	P(audio::ISoundListener)								_listener;
	Float													_horzFieldOfView;
	Float													_aspect;
	Float													_front;
	Float													_back;
	Float													_eyeDist;
	mutable math::Matrix4x4									_viewTransform;
	mutable math::Matrix4x4									_viewTransformLeft;
	mutable math::Matrix4x4									_viewTransformRight;
	mutable Bool											_viewTransformDirty;
	math::Matrix4x4											_projectionTransform;
	mutable math::Matrix4x4									_invViewProjection;
	mutable Bool											_invViewProjectionDirty;
	math::Vector3											_target;
	mutable math::Vector4									_planes[PLANE_COUNT];
	mutable Bool											_planesDirty;
	mutable math::Matrix4x4									_worldToCamera;

	void													UpdateViewTransform() const;
	void													UpdateProjectionTransform();
	void													UpdateListener( Bool position, Bool direction );
	void													UpdatePlanes() const;
	void													GetViewDimensions( Float& x, Float& y, Float& z ) const;
};


#include "Camera.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_CAMERA_
