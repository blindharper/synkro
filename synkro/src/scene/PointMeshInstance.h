//==============================================================================
// This file is a part of the Synkro Framework.
// 
// Copyright (c) Nobody. No rights reserved ;-7
//
// The contents herein is the property of the Mankind.
// Use, distribution and modification of this source code
// is allowed without any permission from the Synkro Project.
// Website: http://synkro.org Email: mailto:blindharper70@gmail.com
//
// Purpose: Point mesh node instance implementation.
//==============================================================================
#ifndef _SYNKRO_SCENE_POINTMESHINSTANCE_
#define _SYNKRO_SCENE_POINTMESHINSTANCE_


#include "config.h"
#include <scene/IPointMeshBatch.h>
#include <scene/INodeAnimationController.h>
#include "NodeImpl.h"
#include "BaseNode.h"


namespace synkro
{


namespace scene
{


// Point mesh instance implementation.
class PointMeshInstance :
	public NodeImpl<IPointMesh>,
	public BaseNode
{
public:
	// Constructor & destructor.
	PointMeshInstance( core::IContext* context, IPointMeshBatch* batch, const lang::String& name, UInt index, const math::Matrix4x4& transform );
	~PointMeshInstance();

	// INode methods.
	INodeAnimationController*								CreateAnimationController( anim::IAnimation* animation, anim::AnimationListener* listener );
	IParentConstraint*										CreateParentConstraint( INode* parent, const math::Matrix4x4& transform );
	ILookAtConstraint*										CreateLookAtConstraint( INode* target );

	// IMesh methods.
	void													Show( Bool show );
	UInt													GetSubsetCount() const;
	lang::String											GetSubsetName( UInt index ) const;
	IPrimitive*												GetSubset( UInt index ) const;
	IPrimitive*												GetSubset( const lang::String& name ) const;
	void													GetCenter( math::Vector3& center ) const;
	Float													GetBoundSphere() const;
	Bool													IsVisible() const;
	ILineMesh*												AsLine() const;
	IPointMesh*												AsPoint() const;
	ITriangleMesh*											AsTriangle() const;

	// IPointMesh methods.
	IPointMesh*												CreateInstance( INode* parent, const math::Matrix4x4& transform, const img::Color& color );
	IPointSet*												CreatePointList( const lang::String& name, UInt count, Float size, const ColorMode& colorMode, const math::Matrix4x4& transform );
	IPointSet*												CreatePointSet( const lang::String& name, const lang::Range& range );
	void													SetColor( const img::Color& color );
	IPointMeshBatch*										AsBatch() const;

	// BaseNode methods.
	void													Update();

	// Other methods.
	void													SetIndex( UInt index );

private:
	P(INodeAnimationController)								_ctrlAnimation;
	IPointMeshBatch*										_batch;
	UInt													_index;
	Bool													_visible;
};


#include "PointMeshInstance.inl"


} // scene


} // synkro


#endif // _SYNKRO_SCENE_POINTMESHINSTANCE_
