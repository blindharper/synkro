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
// Purpose: Triangle mesh set implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_TRIANGLEMESHSET_
#define _SYNKRO_SCENE_TRIANGLEMESHSET_


#include "config.h"
#include <scene/ITriangleMeshSet.h>
#include <scene/INodeAnimationController.h>
#include <scene/ITriangleSet.h>
#include <gfx/PrimitiveType.h>
#include <phys/IActor.h>
#include "MeshImpl.h"
#include "BaseNode.h"


namespace synkro
{


namespace scene
{


// Triangle mesh set implementation.
class TriangleMeshSet :
	public MeshImpl<ITriangleMeshSet>,
	public BaseNode
{
public:
	// Constructor.
	TriangleMeshSet( ITriangleMeshSet* meshSet, ISceneEx* scene, core::IContext* context, const lang::String& name );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimationSet* animations, anim::AnimationListener* listener );
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
	void													GetWorldTransform( math::Matrix4x4& transform ) const;

	// IMesh methods.
	ITriangleMesh*											AsTriangle() const;

	// ITriangleMesh methods.
	ITriangleSet*											CreateTriangleList( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );
	ITriangleSet*											CreateTriangleStrip( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );
	ITriangleSet*											CreateTriangleSet( const lang::String& name, const lang::Range& range );
	void													Save( io::IStream* stream, const core::DataMode& mode, const MeshCodec& type );
	void													Save( io::IStream* stream, const core::DataMode& mode );
	void													SetActor( phys::IActor* actor );
	ISkeleton*												GetSkeleton() const;
	mat::IVisualMaterial*									GetMaterial() const;
	phys::IActor*											GetActor() const;
	IScene*													GetScene() const;
	ITriangleMeshBatch*										AsBatch() const;
	ITriangleMeshSet*										AsSet() const;

	// ITriangleMeshSet methods.
	void													SetMinimumLevelSize( UInt index, Float size );
	UInt													GetLevelCount() const;
	Float													GetMinimumLevelSize( UInt index ) const;

	// BaseNode methods.
	void													Update() override;

private:
	P(ITriangleMeshSet)										_meshSet;
	P(INodeAnimationController)								_ctrlAnimation;
	P(phys::IActor)											_actor;
	lang::Vector<Float>										_levels;

	ITriangleSet*											RegisterSubset( ITriangleSet* subset, const lang::String& name, const math::Matrix4x4& transform );
};


#include "TriangleMeshSet.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_TRIANGLEMESHSET_
