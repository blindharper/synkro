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
// Purpose: Point mesh batch implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_POINTMESHBATCH_
#define _SYNKRO_SCENE_POINTMESHBATCH_


#include "config.h"
#include "MeshBatchImpl.h"
#include <scene/IPointMeshBatch.h>
#include <scene/IMeshBatchAnimationController.h>
#include <scene/IPrimitive.h>
#include <gfx/ILineRenderObject.h>
#include "BaseMeshBatch.h"


namespace synkro
{


namespace scene
{


// Point mesh batch implementation.
class PointMeshBatch :
	public MeshBatchImpl<IPointMeshBatch, IPointMesh>,
	public BaseMeshBatch
{
public:
	// Constructor.
	PointMeshBatch( ISceneEx* scene, core::IContext* context, const lang::String& name, UInt capacity );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// IMesh methods.
	IPointMesh*												AsPoint() const;

	// IPointMesh methods.
	IPointSet*												CreatePointList( const lang::String& name, UInt count, Float size, const ColorMode& colorMode, const math::Matrix4x4& transform );
	IPointSet*												CreatePointSet( const lang::String& name, const lang::Range& range );
	void													SetColor( const img::Color& color );
	IPointMeshBatch*										AsBatch() const;

	// IPointMeshBatch methods.
	IPointMesh*												CreateInstance( INode* parent, const math::Matrix4x4& transform, const img::Color& color );
	void													RemoveInstance( UInt index );
	void													SetInstanceTransform( UInt index, const math::Matrix4x4& transform );
	void													SetInstanceColor( UInt index, const img::Color& color );

	// BaseMeshBatch methods.
	void													Update();

private:
	P(IMeshBatchAnimationController)						_ctrlAnimation;
};


#include "PointMeshBatch.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_POINTMESHBATCH_
