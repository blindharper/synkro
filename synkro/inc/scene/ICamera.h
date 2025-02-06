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
// Purpose: Defines camera scene node.
//==============================================================================
#ifndef _SYNKRO_SCENE_ICAMERA_
#define _SYNKRO_SCENE_ICAMERA_


#include "config.h"
#include <scene/INode.h>


namespace synkro
{


namespace scene
{


/**
 * Camera node.
 */
iface ICamera :
	public INode
{
public:
	/**
	 * Creates camera record controller.
	 * @param animation Animation to record.
	 * @return Created controller.
	 */
	virtual ICameraRecordController*						CreateRecordController( anim::IAnimation* animation ) = 0;

	/**
	 * Sets camera horizontal field of view.
	 * @param fieldOfView Horizontal field of view, in radians. Valid values are [0.0-PI]
	 */
	virtual void											SetHorizontalFieldOfView( Float fieldOfView ) = 0;

	/**
	 * Sets aspect of the image produced by camera.
	 * @param aspect Aspect ratio.
	 */
	virtual void											SetAspect( Float aspect ) = 0;
	
	/**
	 * Sets camera near view-plane.
	 * @param front Near view-plane distance.
	 */
	virtual void											SetFront( Float front ) = 0;

	/**
	 * Sets camera far view-plane.
	 * @param back Far view-plane distance.
	 */
	virtual void											SetBack( Float back ) = 0;

	/**
	 * Sets distance between eyes. Used to get stereoscopic picture.
	 * @param distance Distance between eyes.
	 */
	virtual void											SetEyeDistance( Float distance ) = 0;

	/**
	 * Retrieves camera vertical field of view.
	 */
	virtual Float											GetVerticalFieldOfView() const = 0;

	/**
	 * Retrieves camera horizontal field of view.
	 */
	virtual Float											GetHorizontalFieldOfView() const = 0;

	/**
	 * Retrieves camera aspect ratio.
	 */
	virtual Float											GetAspect() const = 0;

	/**
	 * Retrieves camera near view-plane.
	 */
	virtual Float											GetFront() const = 0;

	/**
	 * Retrieves camera far view-plane.
	 */
	virtual Float											GetBack() const = 0;

	/**
	 * Retrieves distance between eyes. Used to get stereoscopic picture.
	 */
	virtual Float											GetEyeDistance() const = 0;

	/**
	 * Retrieves camera view transformation.
	 * @param [out] transform Variable where to store transformation.
	 */
	virtual void											GetViewTransform( math::Matrix4x4& transform ) const = 0;

	/**
	 * Retrieves camera left view transformation.
	 * @param [out] transform Variable where to store transformation.
	 */
	virtual void											GetLeftViewTransform( math::Matrix4x4& transform ) const = 0;

	/**
	 * Retrieves camera right view transformation.
	 * @param [out] transform Variable where to store transformation.
	 */
	virtual void											GetRightViewTransform( math::Matrix4x4& transform ) const = 0;

	/**
	 * Retrieves camera projection transformation.
	 * @param [out] transform Variable where to store transformation.
	 */
	virtual void											GetProjectionTransform( math::Matrix4x4& transform ) const = 0;

	/**
	 * Retrieves inverse view-projection transformation.
	 * @param [out] transform Variable where to store transformation.
	 */
	virtual void											GetInverseViewProjectionTransform( math::Matrix4x4& transform ) const = 0;

	/**
	 * Performs view frustum culling test.
	 * @param center Object's bounding sphere center.
	 * @param radius Object's bounding sphere radius.
	 * @return True if the sphere in world space is within camera's view frustum.
	 */
	virtual Bool											IsInView( const math::Vector3& center, Float radius ) const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ICAMERA_
