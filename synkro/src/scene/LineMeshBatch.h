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
// Purpose: Line mesh batch implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_LINEMESHBATCH_
#define _SYNKRO_SCENE_LINEMESHBATCH_


#include "config.h"
#include "MeshBatchImpl.h"
#include <scene/ILineMeshBatch.h>
#include <scene/IMeshBatchAnimationController.h>
#include <scene/IPrimitive.h>
#include <gfx/ILineRenderObject.h>
#include <gfx/PrimitiveType.h>
#include "BaseMeshBatch.h"


namespace synkro
{


namespace scene
{


// Line mesh batch implementation.
class LineMeshBatch :
	public MeshBatchImpl<ILineMeshBatch, ILineMesh>,
	public BaseMeshBatch
{
public:
	// Constructor.
	LineMeshBatch( ISceneEx* scene, core::IContext* context, const lang::String& name, UInt capacity );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );

	// IMesh methods.
	ILineMesh*												AsLine() const;

	// ILineMesh methods.
	ILineSet*												CreateLineList( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform );
	ILineSet*												CreateLineList4D( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform );
	ILineSet*												CreateLineStrip( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform );
	ILineSet*												CreateLineSet( const lang::String& name, const lang::Range& range );
	void													SetColor( const img::Color& color );
	ILineMeshBatch*											AsBatch() const;

	// ILineMeshBatch methods.
	ILineMesh*												CreateInstance( INode* parent, const math::Matrix4x4& transform, const img::Color& color );
	void													RemoveInstance( UInt index );
	void													SetInstanceTransform( UInt index, const math::Matrix4x4& transform );
	void													SetInstanceColor( UInt index, const img::Color& color );
	
	// BaseMeshBatch methods.
	void													Update();

private:
	P(IMeshBatchAnimationController)						_ctrlAnimation;

	ILineSet*												CreateLineSet( const gfx::PrimitiveType& type, const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform );
};


#include "LineMeshBatch.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_LINEMESHBATCH_
