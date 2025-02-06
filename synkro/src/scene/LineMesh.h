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
// Purpose: Line mesh implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_LINEMESH_
#define _SYNKRO_SCENE_LINEMESH_


#include "config.h"
#include <scene/ILineMesh.h>
#include <scene/INodeAnimationController.h>
#include <scene/IPrimitive.h>
#include <gfx/ILineRenderObject.h>
#include <gfx/PrimitiveType.h>
#include "MeshImpl.h"
#include "BaseNode.h"


namespace synkro
{


namespace scene
{


// Line mesh implementation.
class LineMesh :
	public MeshImpl<ILineMesh>,
	public BaseNode
{
public:
	// Constructor.
	LineMesh( ISceneEx* scene, core::IContext* context, const lang::String& name );

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	IParentConstraint*										CreateParentConstraint( INode* parent, const math::Matrix4x4& transform );
	ILookAtConstraint*										CreateLookAtConstraint( INode* target );

	// IMesh methods.
	ILineMesh*												AsLine() const;

	// ILineMesh methods.
	ILineSet*												CreateLineList( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform );
	ILineSet*												CreateLineList4D( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform );
	ILineSet*												CreateLineStrip( const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform );
	ILineSet*												CreateLineSet( const lang::String& name, const lang::Range& range );
	void													SetColor( const img::Color& color );
	ILineMeshBatch*											AsBatch() const;

	// BaseNode methods.
	void													Update();

private:
	P(INodeAnimationController)								_ctrlAnimation;

	ILineSet*												CreateLineSet( Bool fourDimensions, const gfx::PrimitiveType& type, const lang::String& name, UInt vertexCount, UInt indexCount, Bool adjacency, const ColorMode& colorMode, const math::Matrix4x4& transform );
};


#include "LineMesh.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_LINEMESH_
