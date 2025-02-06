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
// Purpose: Software solid mesh implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_SOFTTRIANGLEMESH_
#define _SYNKRO_SCENE_SOFTTRIANGLEMESH_


#include "config.h"
#include <scene/ITriangleMesh.h>
#include <scene/ISkeleton.h>
#include <mat/IVisualMaterial.h>
#include "MeshImpl.h"
#include "BaseSceneManager.h"


namespace synkro
{


namespace scene
{


// Software solid mesh implementation.
class SoftTriangleMesh :
	public MeshImpl<ITriangleMesh>
{
public:
	// Constructors.
	SoftTriangleMesh( BaseSceneManager* sceneManager, ISkeleton* skeleton, UInt subsetCount );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// IMesh methods.
	ITriangleMesh*											AsTriangle() const;

	// ITriangleMesh methods.
	ITriangleMesh*											CreateInstance( INode* parent, const math::Matrix4x4& transform, const img::Color& color );
	ITriangleSet*											CreateTriangleList( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );
	ITriangleSet*											CreateTriangleStrip( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );
	ITriangleSet*											CreateTriangleSet( const lang::String& name, const lang::Range& range );
	void													Save( io::IStream* stream, const core::DataMode& mode, const MeshCodec& type );
	void													Save( io::IStream* stream, const core::DataMode& mode );
	ISkeleton*												GetSkeleton() const;
	mat::IVisualMaterial*									GetMaterial() const;
	IScene*													GetScene() const;
	ITriangleMeshBatch*										AsBatch() const;

	// Other methods.
	ITriangleSet*											CreateTriangleSet( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const math::Matrix4x4& transform );

private:
	BaseSceneManager*										_sceneManager;
	P(ISkeleton)											_skeleton;
	P(mat::IVisualMaterial)									_material;
	/*lang::Vector<math::Matrix4x4>				_boneTransforms;*/
};


} // scene


} // synkro


#endif // _SYNKRO_SCENE_SOFTTRIANGLEMESH_
