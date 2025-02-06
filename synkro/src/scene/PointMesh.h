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
// Purpose: Point mesh implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_POINTMESH_
#define _SYNKRO_SCENE_POINTMESH_


#include "config.h"
#include <scene/IPointMesh.h>
#include <scene/INodeAnimationController.h>
#include <scene/IPrimitive.h>
#include <gfx/ILineRenderObject.h>
#include "MeshImpl.h"
#include "BaseNode.h"


namespace synkro
{


namespace scene
{


// Point mesh implementation.
class PointMesh :
	public MeshImpl<IPointMesh>,
	public BaseNode
{
public:
	// Constructor.
	PointMesh( ISceneEx* scene, core::IContext* context, const lang::String& name );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	IParentConstraint*										CreateParentConstraint( INode* parent, const math::Matrix4x4& transform );
	ILookAtConstraint*										CreateLookAtConstraint( INode* target );

	// IMesh methods.
	IPointMesh*												AsPoint() const;

	// IPointMesh methods.
	IPointSet*												CreatePointList( const lang::String& name, UInt count, Float size, const ColorMode& colorMode, const math::Matrix4x4& transform );
	IPointSet*												CreatePointSet( const lang::String& name, const lang::Range& range );
	void													SetColor( const img::Color& color );
	IPointMeshBatch*										AsBatch() const;

	// BaseNode methods.
	void													Update();

private:
	P(INodeAnimationController)								_ctrlAnimation;
};


#include "PointMesh.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_POINTMESH_
