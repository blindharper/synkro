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
// Purpose: Triangle mesh implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_TRIANGLEMESH_
#define _SYNKRO_SCENE_TRIANGLEMESH_


#include "config.h"
#include <scene/ITriangleMesh.h>
#include <scene/INodeAnimationController.h>
#include <scene/ISkeleton.h>
#include <scene/ITriangleSet.h>
#include <gfx/PrimitiveType.h>
#include "MeshImpl.h"
#include "BaseNode.h"


namespace synkro
{


namespace scene
{


// Triangle mesh implementation.
class TriangleMesh :
	public MeshImpl<ITriangleMesh>,
	public BaseNode
{
public:
	// Constructor.
	TriangleMesh( ITriangleMesh* mesh, ISceneEx* scene, core::IContext* context, const lang::String& name, ISkeleton* skeleton );

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
	void													SetScale( const math::Vector3& scale );
	void													SetScale( Float scale );
	void													SetScaleX( Float scale );
	void													SetScaleY( Float scale );
	void													SetScaleZ( Float scale );
	void													SetParent( INode* parent );

	// IMesh methods.
	ITriangleMesh*											AsTriangle() const;

	// ITriangleMesh methods.
	ITriangleSet*											CreateTriangleList( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );
	ITriangleSet*											CreateTriangleStrip( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );
	ITriangleSet*											CreateTriangleSet( const lang::String& name, const lang::Range& range );
	void													Save( io::IStream* stream, const core::DataMode& mode, const MeshCodec& type );
	void													Save( io::IStream* stream, const core::DataMode& mode );
	ISkeleton*												GetSkeleton() const;
	mat::IVisualMaterial*									GetMaterial() const;
	IScene*													GetScene() const;
	ITriangleMeshBatch*										AsBatch() const;

	// BaseNode methods.
	void													Update() override;

private:
	P(ITriangleMesh)										_mesh;
	P(INodeAnimationController)								_ctrlAnimation;
	P(ISkeleton)											_skeleton;
	lang::Vector<math::Matrix4x4>							_boneTransforms;

	ITriangleSet*											RegisterSubset( ITriangleSet* subset, const lang::String& name, const math::Matrix4x4& transform );
};


#include "TriangleMesh.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_TRIANGLEMESH_
