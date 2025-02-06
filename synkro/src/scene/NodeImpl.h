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
// Purpose: Generic node implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_NODEIMPL_
#define _SYNKRO_SCENE_NODEIMPL_


#include "config.h"
#include <core/IContext.h>
#include <core/ObjectImpl.h>
#include <scene/INode.h>
#include <scene/ISceneEx.h>
#include <scene/ICurve.h>
#include <scene/INodeAnimationController.h>
#include <scene/ILookAtConstraint.h>
#include <scene/IParentConstraint.h>
#include "BaseScene.h"
#include "Gizmo.h"


namespace synkro
{


namespace scene
{


// Generic node implementation.
template <class T>
class NodeImpl :
	public core::ObjectImpl<T>
{
public:
	// Constructors & destructor.
	NodeImpl( ISceneEx* scene, core::IContext* context, const lang::String& name, Bool visualize = false );
	virtual ~NodeImpl();

	// INode methods.
	virtual IParentConstraint*								CreateParentConstraint( INode* parent, const math::Matrix4x4& transform );
	virtual ILookAtConstraint*								CreateLookAtConstraint( INode* target );
	virtual void											SetTransform( const math::Matrix4x4& transform );
	virtual void											SetPosition( const math::Vector3& position );
	virtual void											SetPositionX( Float x );
	virtual void											SetPositionY( Float y );
	virtual void											SetPositionZ( Float z );
	virtual void											SetOrientation( const math::Quaternion& orientation );
	virtual void											SetOrientationYaw( Float yaw );
	virtual void											SetOrientationPitch( Float pitch );
	virtual void											SetOrientationRoll( Float roll );
	virtual void											LookAt( const math::Vector3& target );
	virtual void											SetScale( const math::Vector3& scale );
	virtual void											SetScale( Float scale );
	virtual void											SetScaleX( Float scale );
	virtual void											SetScaleY( Float scale );
	virtual void											SetScaleZ( Float scale );
	virtual void											SetPath( ICurve* path );
	virtual void											SetPathPhase( Float phase );
	virtual void											SetParent( INode* parent );
	virtual void											ShowGizmo( Bool show );
	virtual void											SetGizmoSize( Float size );
	virtual IParentConstraint*								GetParentConstraint() const;
	virtual ILookAtConstraint*								GetLookAtConstraint() const;
	virtual void											GetWorldTransform( math::Matrix4x4& transform ) const;
	virtual void											GetTransform( math::Matrix4x4& transform ) const;
	virtual void											GetPosition( math::Vector3& position ) const;
	virtual Float											GetPositionX() const;
	virtual Float											GetPositionY() const;
	virtual Float											GetPositionZ() const;
	virtual void											GetOrientation( math::Quaternion& orientation ) const;
	virtual Float											GetOrientationYaw() const;
	virtual Float											GetOrientationPitch() const;
	virtual Float											GetOrientationRoll() const;
	virtual void											GetScale( math::Vector3& scale ) const;
	virtual Float											GetScaleX() const;
	virtual Float											GetScaleY() const;
	virtual Float											GetScaleZ() const;
	virtual ICurve*											GetPath() const;
	virtual Float											GetPathPhase() const;
	virtual INode*											GetParent() const;
	virtual INode*											GetNode( const lang::String& name ) const;
	virtual ISceneEx*										GetSceneEx() const;
	virtual lang::String									GetName() const;
	virtual ICamera*										AsCamera() const;
	virtual ILight*											AsLight() const;
	virtual IMesh*											AsMesh() const;
	virtual ISound*											AsSound() const;

	// Other methods.
	INode*													GetNextNode() const;

protected:
	core::IContext*											_context;
	lang::String											_name;
	mutable Bool											_transformDirty;
	mutable math::Matrix4x4									_transform;
	mutable math::Vector3									_translation;
	mutable math::Quaternion								_orientation;
	math::Vector3											_scale;
	Float													_yaw;
	Float													_pitch;
	Float													_roll;
	ISceneEx*												_scene;
	INode*													_parent;
	INode*													_child;
	INode*													_next;
	INode*													_prev;
	Float													_pathPhase;
	P(ICurve)												_path;
	P(IParentConstraint)									_parentConstraint;
	P(ILookAtConstraint)									_lookAtConstraint;
	Gizmo													_gizmo;

	Bool													IsParent( const INode* node ) const;
	void													AdjustAngle( Float& angle );
	void													ApplyConstraints( INodeAnimationController* ctrl );
};


#include "NodeImpl.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_NODEIMPL_
