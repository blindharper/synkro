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
// Purpose: Defines scene graph node.
//==============================================================================
#ifndef _SYNKRO_SCENE_INODE_
#define _SYNKRO_SCENE_INODE_


#include "config.h"
#include <core/IObject.h>
#include <lang/String.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace scene
{


/**
 * Scene graph node.
 */
iface INode :
	public core::IObject
{
public:
	/**
	 * Creates animation controller for the node.
	 * @param animation Optional node animation.
	 * @param listener Controller listener.
	 * @return Created controller.
	 */
	virtual INodeAnimationController*						CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener ) = 0;

	/**
	 * Creates parent constraint.
	 * @param parent Parent node.
	 * @param transform Node-to-parent transformation.
	 * @return Created constraint.
	 */
	virtual IParentConstraint*								CreateParentConstraint( INode* parent, const math::Matrix4x4& transform ) = 0;

	/**
	 * Creates "Look At" constraint.
	 * @param target Node to look at.
	 * @return Created constraint.
	 */
	virtual ILookAtConstraint*								CreateLookAtConstraint( INode* target ) = 0;

	/**
	 * Sets node transformation.
	 * @param transform Node transformation.
	 */
	virtual void											SetTransform( const math::Matrix4x4& transform ) = 0;

	/**
	 * Sets node position.
	 * @param position Node position.
	 */
	virtual void											SetPosition( const math::Vector3& position ) = 0;

	/**
	 * Sets node position's x coordinate.
	 * @param x Node position's x coordinate.
	 */
	virtual void											SetPositionX( Float x ) = 0;

	/**
	 * Sets node position's y coordinate.
	 * @param y Node position's y coordinate.
	 */
	virtual void											SetPositionY( Float y ) = 0;

	/**
	 * Sets node position's z coordinate.
	 * @param z Node position's z coordinate.
	 */
	virtual void											SetPositionZ( Float z ) = 0;

	/**
	 * Sets node orientation.
	 * @param orientation Node orientation.
	 */
	virtual void											SetOrientation( const math::Quaternion& orientation ) = 0;

	/**
	 * Sets node yaw angle.
	 * @param yaw Yaw angle, in radians.
	 */
	virtual void											SetOrientationYaw( Float yaw ) = 0;

	/**
	 * Sets node pitch angle.
	 * @param pitch Pitch angle, in radians.
	 */
	virtual void											SetOrientationPitch( Float pitch ) = 0;

	/**
	 * Sets node roll angle.
	 * @param roll Roll angle, in radians.
	 */
	virtual void											SetOrientationRoll( Float roll ) = 0;

	/**
	 * Adjusts node orientation so that it looks at the given point.
	 * @param target Point to look at.
	 */
	virtual void											LookAt( const math::Vector3& target ) = 0;

	/**
	 * Sets node scale.
	 * @param scale Node scale.
	 */
	virtual void											SetScale( const math::Vector3& scale ) = 0;

	/**
	 * Sets uniform node scale.
	 * @param scale Node scale.
	 */
	virtual void											SetScale( Float scale ) = 0;

	/**
	 * Sets node scale along X axis.
	 * @param scale Node scale.
	 */
	virtual void											SetScaleX( Float scale ) = 0;

	/**
	 * Sets node scale along Y axis.
	 * @param scale Node scale.
	 */
	virtual void											SetScaleY( Float scale ) = 0;

	/**
	 * Sets node scale along Z axis.
	 * @param scale Node scale.
	 */
	virtual void											SetScaleZ( Float scale ) = 0;

	/**
	 * Sets trajectory for the node to follow.
	 * @param path Path to follow.
	 */
	virtual void											SetPath( ICurve* path ) = 0;

	/**
	 * Sets node current position at the path.
	 * @param phase Relative place at the path [0.0-1.0].
	 */
	virtual void											SetPathPhase( Float phase ) = 0;

	/**
	 * Links node to specified parent node. To remove parent, pass null.
	 * @param parent Parent node.
	 */
	virtual void											SetParent( INode* parent ) = 0;

	/**
	 * Sets node gizmo visibility.
	 * @param show Set to true to make node gizmo visible, set to false to hide it.
	 */
	virtual void											ShowGizmo( Bool show ) = 0;

	/**
	 * Sets node gizmo size.
	 * @param size Gizmo size.
	 */
	virtual void											SetGizmoSize( Float size ) = 0;

	/**
	 * Retrieves previously created parent constraint.
	 * @return Parent constraint.
	 */
	virtual IParentConstraint*								GetParentConstraint() const = 0;

	/**
	 * Retrieves previously created "Look At" constraint.
	 * @return "Look At" constraint.
	 */
	virtual ILookAtConstraint*								GetLookAtConstraint() const = 0;

	/**
	 * Retrieves node's world transform.
	 * @param [out] transform Variable where to store transform.
	 */
	virtual void											GetWorldTransform( math::Matrix4x4& transform ) const = 0;

	/**
	 * Retrieves node transform.
	 * @param [out] transform Variable where to store transform.
	 */
	virtual void											GetTransform( math::Matrix4x4& transform ) const = 0;

	/**
	 * Retrieves node position.
	 * @param [out] position Variable where to store position.
	 */
	virtual void											GetPosition( math::Vector3& position ) const = 0;

	/**
	 * Retrieves node position's x coordinate.
	 * @return Node position's x coordinate.
	 */
	virtual Float											GetPositionX() const = 0;

	/**
	 * Retrieves node position's y coordinate.
	 * @return Node position's y coordinate.
	 */
	virtual Float											GetPositionY() const = 0;

	/**
	 * Retrieves node position's z coordinate.
	 * @return Node position's z coordinate.
	 */
	virtual Float											GetPositionZ() const = 0;

	/**
	 * Retrieves node orientation.
	 * @param [out] orientation Variable where to store orientation.
	 */
	virtual void											GetOrientation( math::Quaternion& orientation ) const = 0;

	/**
	 * Retrieves node yaw angle.
	 * @return Node yaw angle, in radians.
	 */
	virtual Float											GetOrientationYaw() const = 0;

	/**
	 * Retrieves node pitch angle.
	 * @return Node pitch angle, in radians.
	 */
	virtual Float											GetOrientationPitch() const = 0;

	/**
	 * Retrieves node roll angle.
	 * @return Node roll angle, in radians.
	 */
	virtual Float											GetOrientationRoll() const = 0;

	/**
	 * Retrieves node scale.
	 * @param [out] scale Variable where to store scale.
	 */
	virtual void											GetScale( math::Vector3& scale ) const = 0;

	/**
	 * Retrieves node scale along X axis.
	 * @return Node scale along X axis.
	 */
	virtual Float											GetScaleX() const = 0;

	/**
	 * Retrieves node scale along Y axis.
	 * @return Node scale along Y axis.
	 */
	virtual Float											GetScaleY() const = 0;

	/**
	 * Retrieves node scale along Z axis.
	 * @return Node scale along Z axis.
	 */
	virtual Float											GetScaleZ() const = 0;

	/**
	 * Retrieves trajectory for the node to follow.
	 * @return Node Path to follow.
	 */
	virtual ICurve*											GetPath() const = 0;

	/**
	 * Retrieves node current position at the path.
	 * @return Current path phase.
	 */
	virtual Float											GetPathPhase() const = 0;

	/**
	 * Retrieves node's direct parent.
	 * @return Node's parent, if one exists, or null otherwise.
	 */
	virtual INode*											GetParent() const = 0;

	/**
	 * Retrieves child node by name.
	 * @param name Node name.
	 * @return Child node with the given name, if found or null otherwise.
	 */
	virtual INode*											GetNode( const lang::String& name ) const = 0;

	/**
	 * Retrieves scene holding the node.
	 * @return Scene holding the node.
	 */
	virtual ISceneEx*										GetSceneEx() const = 0;

	/**
	 * Retrieves node name.
	 * @return Node name.
	 */
	virtual lang::String									GetName() const = 0;

	/**
	 * Casts node to camera.
	 * @return Non-null for camera, nullptr otherwise.
	 */
	virtual ICamera*										AsCamera() const = 0;

	/**
	 * Casts node to light.
	 * @return Non-null for light, nullptr otherwise.
	 */
	virtual ILight*											AsLight() const = 0;

	/**
	 * Casts node to mesh.
	 * @return Non-null for mesh, nullptr otherwise.
	 */
	virtual IMesh*											AsMesh() const = 0;

	/**
	 * Casts node to sound.
	 * @return Non-null for sound, nullptr otherwise.
	 */
	virtual ISound*											AsSound() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_INODE_
