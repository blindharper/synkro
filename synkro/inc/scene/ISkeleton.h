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
// Purpose: Defines triangle mesh skeleton.
//==============================================================================
#ifndef _SYNKRO_SCENE_ISKELETON_
#define _SYNKRO_SCENE_ISKELETON_


#include "config.h"
#include <core/IObject.h>
#include <core/DataMode.h>
#include <scene/MeshCodec.h>
#include <math/Matrix4x4.h>


namespace synkro
{


namespace scene
{


/**
 * Triangle mesh skeleton. Used as a container for bones.
 */
iface ISkeleton :
	public core::IObject
{
public:
	/**
	 * Creates animation controller.
	 * @param animations Optional bones animations.
	 * @param listener Controller listener.
	 * @return Created controller.
	 */
	virtual ISkeletonAnimationController*					CreateAnimationController( anim::IAnimationSet* animations, anim::AnimationListener* listener ) = 0;

	/**
	 * Creates a new bone.
	 * @param parent Parent bone.
	 * @param name Bone name.
	 * @param transform Bone transformation.
	 * @param offset Bone offset.
	 * @return Created bone.
	 */
	virtual IBone*											CreateBone( IBone* parent, const lang::String& name, const math::Matrix4x4& transform, const math::Matrix4x4& offset ) = 0;

	/**
	 * Adds animation set to the mesh.
	 * @param set Animation set.
	 * @exception Exception Animation set with this name already exists.
	 */
	virtual void											AddAnimationSet( anim::IAnimationSet* set ) = 0;

	/**
	 * Saves mesh to the stream in the given format.
	 * @param stream Stream to which to save mesh.
	 * @param mode Data mode to save data in.
	 * @param type Mesh codec type.
	 */
	virtual void											Save( io::IStream* stream, const core::DataMode& mode, const MeshCodec& type ) = 0;

	/**
	 * Saves mesh to the stream in the given format. Mesh type is guessed from stream name.
	 * @param stream Stream to which to save mesh.
	 * @param mode Data mode to save data in.
	 */
	virtual void											Save( io::IStream* stream, const core::DataMode& mode ) = 0;

	/**
	 * Retrieves the number of bones in the mesh.
	 */
	virtual UInt											GetBoneCount() const = 0;

	/**
	 * Retrieves bone by index.
	 * @param index Index of the bone to retrieve.
	 * @return Requested bone.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual IBone*											GetBone( UInt index ) const = 0;

	/**
	 * Retrieves bone by name.
	 * @param name Bone name.
	 * @return Requested bone, if one is found or null otherwise.
	 */
	virtual IBone*											GetBone( const lang::String& name ) const = 0;

	/**
	 * Retrieves world transformations for skeleton bones.
	 * @param worldTransform World transform of the mesh.
	 * @param transforms Array to write the transforms into.
	 * @param count Total transforms count.
	 */
	virtual void											GetBoneTransforms( const math::Matrix4x4& worldTransform, math::Matrix4x4** transforms, UInt count ) const = 0;

	/**
	 * Retrieves the number of animation sets in the mesh.
	 */
	virtual UInt											GetAnimationSetCount() const = 0;

	/**
	 * Retrieves animation set by index.
	 * @param index Index of the animation set to retrieve.
	 * @return Requested animation set.
	 * @exception OutOfRangeException Index is out of range.
	 */
	virtual anim::IAnimationSet*							GetAnimationSet( UInt index ) const = 0;

	/**
	 * Retrieves animation set by name.
	 * @param name Animation set name.
	 * @return Requested animation set, if found, nullptr otherwise.
	 */
	virtual anim::IAnimationSet*							GetAnimationSet( const lang::String& name ) const = 0;
	
	/**
	 * Returns exact copy of the skeleton, sharing animation sets.
	 * @return Cloned skeleton.
	 */
	virtual ISkeleton*										Clone() const = 0;
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_ISKELETON_
