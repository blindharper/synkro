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
// Purpose: Triangle mesh batch implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_TRIANGLEMESHBATCH_
#define _SYNKRO_SCENE_TRIANGLEMESHBATCH_


#include "config.h"
#include "MeshBatchImpl.h"
#include <scene/ITriangleMeshBatch.h>
#include <scene/IMeshBatchAnimationController.h>
#include <scene/ISkeleton.h>
#include <scene/ITriangleSet.h>
#include <gfx/PrimitiveType.h>
#include "BaseMeshBatch.h"


namespace synkro
{


namespace scene
{


// Triangle mesh batch implementation.
class TriangleMeshBatch :
	public MeshBatchImpl<ITriangleMeshBatch, ITriangleMesh>,
	public BaseMeshBatch
{
public:
	// Constructor.
	TriangleMeshBatch( ITriangleMeshBatch* batch, ISceneEx* scene, core::IContext* context, const lang::String& name, ISkeleton* skeleton, UInt capacity );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

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

	// ITriangleMeshBatch methods.
	ITriangleMesh*											CreateInstance( INode* parent, const math::Matrix4x4& transform, const img::Color& color );
	void													RemoveInstance( UInt index );
	void													SetInstanceTransform( UInt index, const math::Matrix4x4& transform );
	void													SetInstanceColor( UInt index, const img::Color& color );
	
	// BaseMeshBatch methods.
	void													Update();

private:
	enum
	{
		MAX_BONE_COUNT = 50,
	};

	P(ITriangleMeshBatch)									_batch;
	P(IMeshBatchAnimationController)						_ctrlAnimation;
	P(ISkeleton)											_skeleton;
	lang::Vector<math::Matrix4x4>							_boneTransforms;

	ITriangleSet*											RegisterSubset( ITriangleSet* subset, const lang::String& name, const math::Matrix4x4& transform );
};


#include "TriangleMeshBatch.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_TRIANGLEMESHBATCH_
